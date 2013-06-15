// perspective
#define PSHIFT 50

// shading options
#define ZBUFFER  1
#define DIFUSE   2
#define REFLECT  3

// light coordinates
#define INTENSITY 300
#define LIGHT_X   80
#define LIGHT_Y   0
#define LIGHT_Z   0

#include "Canvas.h"
#include "dgcapp.h"

#include <QMouseEvent>

#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief Creates canvas. Set initial coords.
 * @param parent Window where canvas is to be painted
 */
Canvas::Canvas( QWidget * parent ) : QWidget( parent )
{
    // Coords: Beginning and End
    x = y = j = k = 0;
    L       = NULL; // label
    axis    = true; // paint axis?
    pressed = false; // mouse not pressed
}

Canvas::~Canvas() { }

/**
 *  @brief assign label to canvas to show coords
 *  @param L Label where to update coords through (Canvas::UpdateCoords)
 */
void Canvas::SetLabel( QLabel * L ) { this->L = L; LabelText = L->text(); }

/**
 * @brief Updates coords when mouse is pressed
 * @param x X Coord
 * @param y Y Coord
 */
void Canvas::SetInitialCoords( int x, int y ) { this->x = x; this->y = y; }

/**
 * @brief Updates coords when mouse is released
 * @param x X Coord
 * @param y Y Coord
 */
void Canvas::SetFinalCoords( int j, int k ) { this->j = j; this->k = k; }

/**
 * @brief Shows X and Y coords in Canvas label when mouse moves
 * @param x X Coord
 * @param y Y Coord
 */
void Canvas::UpdateCoords( int x, int y )
{
    L->setText( LabelText + ": " + QString::number( x ) + ", " + QString::number( y ) );
}

/**
 *
 * Slots 
 * 
 */

/**
 * @brief indicates if to paint or not to paint the axis
 */
void Canvas::ToggleAxis() { axis = ! axis; update(); }

/**
 *  @brief Updates all canvases
 *
 *  Retrieves all edges from every object in every layer and paints them according
 *  its view (front, side, etc.)
 */
void Canvas::Update()
{
    if ( Edges.size() ) { Edges.clear(); C.clear(); } // clean vector to avoid mistakes

    vector < Edge * > * E = NULL;
    
    int size = Lay->size();
    for ( int i = 0; i < size; i++ )
        if ( E = Lay->at( i )->GetState() ) // retrieve edges info
        {
            Edges.push_back( E ); // store them to paint them in the paint event
            E = NULL; 
            C.push_back( Lay->at( i )->getColor() ); // store also their color
        }
    update();
}

/**
 * 
 * MouseEvents
 * 
 */

/**
 * @brief udpates coords and performs object transformatios if mouse is pressed.
 * @param e mouseEvent
 * 
 *  Calls dgcapp::getCurrentLayer to know if there is an object selected or not.
 *  If so, dgcapp::getCurrentTransform is invoked to take action.
 *  According to the corresponding transformation, actions are performed through
 *  layers.
 */
void Canvas::mouseMoveEvent( QMouseEvent * e )
{
    int X = e->x(), Y = e->y();
    
    UpdateCoords( e->x(), e->y() );
    
    if ( pressed )
    {
        dgcapp * d = ( dgcapp * ) this->parent();
        int l = d->getCurrentLayer();
        
        if ( l < 0 ) return;
        
        int t = d->getCurrentTransform();
        
        switch ( t )
        {
            case 1: // translation
                if ( this == d->getCanvas( Front ) ) 
                    Lay->at( l )->Translation( X - x, -Y + y, 0 ); // XY
                else
                {
                    if ( this == d->getCanvas( Air ) )
                        Lay->at( l )->Translation( X - x, 0, -Y + y ); // XZ
                    else 
                        Lay->at( l )->Translation( 0, - Y + y, X - x ); // YZ
                }
            break;
            
            case 2: // escalation
                if ( this == d->getCanvas( Front ) )
                    Lay->at( l )->RotationZ( 0.2 * ( Y - y ) );  // XY
                else
                {
                    if ( this == d->getCanvas( Air ) )
                        Lay->at( l )->RotationY( 0.2 * ( Y - y ) );  // XZ
                    else 
                        Lay->at( l )->RotationX( 0.2 * ( Y - y ) ); // YZ
                }
            break;
            
            case 3: Lay->at( l )->selfRotation( Y - y ); break; // self rotation
            
            case 4:
                if ( this == d->getCanvas( Front ) )
                    Lay->at( l )->Escalation( 0.02 * ( X - x ) + 1, 
                                              0.02 * ( Y - y ) + 1, 1 );  // XY
                else
                {
                    if ( this == d->getCanvas( Air ) )
                        Lay->at( l )->Escalation( 0.02 * ( X - x ) + 1, 1,
                                                  0.02 * ( Y - y ) + 1 ); // YZ
                    else 
                        Lay->at( l )->Escalation( 1, 0.02 * ( Y - y ) + 1,
                                                     0.02 * ( X - x ) + 1 ); // XZ
                }
            break;
        }
        
        SetInitialCoords( e->x(), e->y() );
        
        if ( t ) Update(); // if t -> transformation performed -> update
    }
}

/**
 * @brief Updates coords and sets mouse 'pressed' to true.
 * @param e MouseEvent
 */
void Canvas::mousePressEvent( QMouseEvent * e )
{
    SetInitialCoords( e->x(), e->y() );
    SetFinalCoords( e->x(), e->y() );
    pressed = true;
}

/**
 * @brief Updates coords and sets mouse 'pressed' to true and adds the new point
 * of the border defined by the user, if border is selected.
 * @param e MouseEvent
 */
void Canvas::mouseReleaseEvent( QMouseEvent * e )
{
    SetInitialCoords( e->x(), e->y() );
    SetFinalCoords( e->x(), e->y() );
    pressed = false;
    
    dgcapp * d = ( dgcapp * ) this->parent();
    if ( d->isBorderSelected() )
    {
        int centerW = this->size().width() / 2, 
            centerH = this->size().height() / 2;
        
        // border
        d->setRevPoint( -e->x() + centerW, -e->y() + centerH, 0, 1 );
    }
    update();
}

/**
 * @brief PaintEvent
 * @param e
 * Paints axis and objects (zbuffered or not, or difused)
 */

void Canvas::paintEvent( QPaintEvent * e )
{
    QPainter p( this );
    p.setPen( Qt::black ); // black color
    
    dgcapp * d = ( dgcapp * ) this->parent();
    
    QSize s = this->size();
    
    int centerW = s.width() / 2, centerH = s.height() / 2;
    
    if ( axis ) // paint axis ?
    {
        p.drawLine( 0, centerH, s.width(), centerH ); // horizontal axis
        p.drawLine( centerW, 0, centerW, s.height() );  // vertical axis
        
        p.setPen( Qt::red );
        p.drawLine( 0, s.height(), s.width(), 0 ); // 3º axis
    }
    
    if ( Edges.size() )
    {        
        int size = Edges.size(); // updated through Canvas::Update
        vector < Edge * > * E = NULL;
        for ( int i = 0; i < size; i++ )
        {        
            float x1, y1, x2, y2, z1, z2;
            float parx1, pary1, parx2, pary2;

            E = Edges.at( i );
            p.setPen( C[ i ] ); // set axis color
            int NEdges = E->size();
            
            for ( int i = 0; i < NEdges; i++ ) // travel through edges
            {
                x1 = E->at( i )->GetIni()->x; x2 = E->at( i )->GetEnd()->x;
                y1 = E->at( i )->GetIni()->y; y2 = E->at( i )->GetEnd()->y;
                z1 = E->at( i )->GetIni()->z; z2 = E->at( i )->GetEnd()->z;

                // perpective: shift in Z and scale and translate
                z1 += PSHIFT; z2 += PSHIFT;

                float r = 1 / ( float ) 20; // shift point -> perspective

                parx1 = x1; pary1 = y1; // default: no depth
                parx2 = x2; pary2 = y2; // default: no depth

                if ( ( int ) z1 > 0 ) // front point -> make perspective
                {
                    parx1 /= ( r * z1 + 1 );
                    pary1 /= ( r * z1 + 1 );
                }

                if ( ( int ) z2 > 0 ) // front point -> make perspective
                {
                    parx2 = x2 / ( r * z2 + 1 );
                    pary2 = y2 / ( r * z2 + 1 );
                }

                //escalation for representation
                parx1 *= 3; parx2 *= 3; pary1 *= 3; pary2 *= 3;

                dgcapp * d = ( dgcapp * ) this->parent();
                Canvas * A = d->getCanvas( Air ), * F = d->getCanvas( Front ), 
                       * L = d->getCanvas( Lat );
                
                if ( this == F ) p.drawLine( x1 + centerW, -y1 + centerH, 
                                             x2 + centerW, -y2 + centerH ); // XY: FRONTAL
                else
                {   // XZ: AÉREA
                    if ( this == A ) p.drawLine( x1 + centerW, -z1 + centerH + PSHIFT, 
                                                 x2 + centerW, -z2 + centerH + PSHIFT );
                    else
                    {   // ZY: LATERAL
                        if ( this == L ) p.drawLine( z1 + centerW - PSHIFT, -y1 + centerH, 
                                                     z2 + centerW - PSHIFT, -y2 + centerH );
                        else // if both edges points are visible -> paint them: perspective
                            if ( ( int ) z1 >= 0 and ( int ) z2 >= 0 ) 
                                p.drawLine( parx1 + centerW, -pary1 + centerH, 
                                            parx2 + centerW, -pary2 + centerH ); // PERSPECTIVE
                    }
                }
            }
        }
    
        if ( d->getCurrentShading() /*and this == d->getCanvas( Front )*/ ) ZBuffer( & p ); // zbuffer or difuse lighting
        
        update();
    }
    
    if ( d->getRevNumP() > 1 ) // a line is made out of 2 points
    {
        int x0, y0, x, y;
        for( int i = 0; i < d->getRevNumP() - 1; i++ )
        {
            x0 = ( d->getRevIX( i ) * -1 ) + centerW;
            y0 = ( d->getRevIY( i ) * -1 ) + centerH;
            x  = ( d->getRevIX( i + 1 ) * -1 ) + centerW;
            y  = ( d->getRevIY( i + 1 ) * -1 ) + centerH;
            p.drawLine( x0, y0, x, y );
        }
        update();
    }
}

/**
 * @brief informs canvases (observers) whom to watch
 * @param S Subject (dgcapp::ScreenLayers)
 */
void Canvas::SetSubject( vector < Layer * > * S ) { Lay = S; }

/**
 * @brief Z-Buffer algorith, may also illuminate objects if selected.
 * @param p pointer to painter in paintEvent to draw points to fill polygons
 */
void Canvas::ZBuffer( QPainter * p )
{
    int Faces, w = this->size().width(), h = this->height();
    
    struct punto3d Light;

    // light position & intensity
    dgcapp * d = ( dgcapp * ) this->parent();
        
    // update light in scene
    Light.x = d->getLightX();
    Light.y = d->getLightY();
    Light.z = d->getLightZ(); 
    Light.h = 1.;
    
    float ** zbuffer = new float * [ w ];
    for( int i = 0; i < w; i++ ) zbuffer[ i ] = new float[ h ];
    
    // init screen memory -> zbuffer = ∞
    for ( int i = 0; i < w; i++ )
        for ( int j = 0; j < h; j++ ) *( zbuffer[ i ] + j ) = 7777;
    
    int size = Lay->size();
    for ( int k = 0; k < size; k++ )
    {
        Faces = Lay->at( k )->getObjNumFaces();
        for ( int n = 0; n < Faces; n++ )
        {
            punto3d A, B, C;
            
            Lay->at( k )->FacePoints( n, & A, & B, & C ); // face coordinates
            
            Canvas * Ae = d->getCanvas( Air ), * F = d->getCanvas( Front ), 
                   * L = d->getCanvas( Lat );
            
            
            p->setPen( Qt::red );
            p->setBrush( Qt::red );
            
            if ( this == F ) // XY: FRONTAL
            {
                // mimic light bulb
                p->drawEllipse( Light.x + w / 2, Light.y + h / 2, 10, 10 );
    
                fill( p, zbuffer, A.x, A.y, B.x, B.y, C.x, C.y,
                      Lay->at( k )->getNFace( n ), Lay->at( k )->getColor(),
                      d->getCurrentShading() >= DIFUSE, & Light, d->getIntensity() );
            }
            else
            {
                // XZ: AÉREA
                if ( this == Ae )
                {
                    // mimic light bulb
                    p->drawEllipse( Light.x + w / 2, Light.z + h / 2, 10, 10 );
    
                    fill( p, zbuffer, A.x, A.z, B.x, B.z, C.x, C.z,
                          Lay->at( k )->getNFace( n ), Lay->at( k )->getColor(),
                          d->getCurrentShading() >= DIFUSE, & Light, d->getIntensity() );
                }
                else
                    // ZY: LATERAL
                    if ( this == L )
                    {
                        // mimic light bulb
                        p->drawEllipse( Light.z + w / 2, Light.y + h / 2, 10, 10 );

                        fill( p, zbuffer, A.z, A.y, B.z, B.y, C.z, C.y,
                              Lay->at( k )->getNFace( n ), Lay->at( k )->getColor(),
                              d->getCurrentShading() >= DIFUSE, & Light, 
                              d->getIntensity() );
                    }
            }
        }
    }
    
    // clean memory
    for( int i = 0; i < w; i++ ) delete [] zbuffer[ i ];
    delete [] zbuffer;
}

/**
 * @brief Fills object triangular faces according to z-buffer or phong illumination
 * model.
 * @param p pointer to painter in paintEvent to draw points to fill polygons
 * @param zbuffer matrix (screen)
 * @param x1 first point x coordinate
 * @param y1 first point y coordinate
 * @param x2 second point x coordinate
 * @param y2 second point y coordinate
 * @param x3 third point x coordinate
 * @param y3 third point y coordinate
 * @param F Face pointer
 * @param Color Face color
 * @param Shade illuminate or not?
 * @param Light light coords
 * @param intensity Color intensity
 */
void Canvas::fill( QPainter * p, float ** zbuffer, float x1, float y1, float x2,
                   float y2, float x3, float y3, Face * F, QColor Color, 
                   bool Shade, punto3d * Light, int intensity )
{
    // sort y coordinates from high to low (and its corresponding x pairs)
    vector < Coords > v;
    struct Coords first = { x1, y1 }, second = { x2, y2 }, third = { x3, y3 };
    v.push_back( first ); v.push_back( second ); v.push_back( third );
    sort( v.begin(), v.end() );
    
    // get min and max x coord
    float Xmin = x1, Xmax = x1;
    if ( x2 >= x1 and x2 >= x3 ) Xmax = x2;
    else if ( x3 >= x1 and x3 >= x2 ) Xmax = x3;
    if ( x2 <= x1 and x2 <= x3 ) Xmin = x2;
    else if ( x3 <= x1 and x3 <= x2 ) Xmin = x3;
    
    for ( int i = ( int ) v[ 0 ].y; i > ( int ) v[ 1 ].y; i-- )
    {
        int ini, end;

        // compute where to start and to end painting
        ini = ( int ) v[ 0 ].x * ( ( v[ 1 ].y - i ) / ( v[ 1 ].y - v[ 0 ].y ) )
                    + v[ 1 ].x * ( 1 - ( ( v[ 1 ].y - i ) / ( v[ 1 ].y - v[ 0 ].y ) ) );
        
        end = ( int ) v[ 0 ].x * ( ( v[ 2 ].y - i ) / ( v[ 2 ].y - v[ 0 ].y ) )
                    + v[ 2 ].x * ( 1 - ( ( v[ 2 ].y - i ) / ( v[ 2 ].y - v[ 0 ].y ) ) );

        if ( ini > end ) { swap( ini, end ); }

        for ( int j = ini; j <= end; j++ )
        {
            if ( j <= end and j >= ini and j <= Xmax and j >= Xmin )
            {
                // point depth -> plane equation
                float depth = -F->getD() - F->getNormal().x * j - F->getNormal().y * i;

                if ( F->getNormal().z ) depth /= F->getNormal().z;
                else depth = 0;

                // calculate zbuffer index
                QSize s = this->size();
                int centerW = s.width() / 2, centerH = s.height() / 2;
                int w = ( int ) i + centerH;
                int h = ( int ) j + centerW;

                if ( h > 0 and h < s.width() and w > 0 and w < s.height() and 
                     depth < zbuffer[ h ][ w ] )
                {
                    // update zbuffer
                    zbuffer[ h ][ w ] = depth;
                    
                    // compute color
                    if( ! Shade ) p->setPen( Color ); // zbuffer
                    // difuse (phong)
                    else p->setPen( lightColor ( i, j, depth, F->getNormal(),
                                    Color, Light, intensity ) );
                    
                    p->drawPoint( j + centerW, -i + centerH ); // paint
                }
            }
        }
    }

    // second part of the face
    for ( int i = ( int ) v[ 1 ].y; i > ( int ) v[ 2 ].y; i-- )
    {
        int ini, end;

        ini = ( int ) v[ 1 ].x * ( ( v[ 2 ].y - i ) / ( v[ 2 ].y - v[ 1 ].y ) )
                    + v[ 2 ].x * ( 1 - ( ( v[ 2 ].y - i ) / ( v[ 2 ].y - v[ 1 ].y ) ) );
        
        end = ( int ) v[ 0 ].x * ( ( v[ 2 ].y - i ) / ( v[ 2 ].y - v[ 0 ].y ) )
                    + v[ 2 ].x * ( 1 - ( ( v[ 2 ].y - i ) / ( v[ 2 ].y - v[ 0 ].y ) ) );

        if ( ini > end ) { swap( ini, end ); }
        
        
        for ( int j = ini; j <= end; j++ )
        {
            if ( j <= end and j >= ini and j <= Xmax and j >= Xmin )
            {
                // point depth -> plane equation
                float depth = -F->getD() - F->getNormal().x * j - F->getNormal().y * i;

                if ( F->getNormal().z ) depth /= F->getNormal().z;
                else depth = 0;

                // calculate zbuffer index
                QSize s = this->size();
                int centerW = s.width() / 2, centerH = s.height() / 2;
                int w = ( int ) i + centerH;
                int h = ( int ) j + centerW;

                //if ( depth < zbuffer[ h ][ w ] )
                if ( h > 0 and h < s.width() and w > 0 and w < s.height() and 
                     depth < zbuffer[ h ][ w ] )
                {
                    // update zbuffer
                    zbuffer[ h ][ w ] = depth;
                    
                    if( ! Shade ) p->setPen( Color );
                    else p->setPen( lightColor ( i, j, depth, F->getNormal(),
                                    Color, Light, intensity ) );
                    p->drawPoint( h, -i + centerH );
                }
            }
        }
    }
}

/**
 * @brief Computes de intensity of Color at a given point by x, y and z.
 * @param x float
 * @param y float
 * @param z float
 * @param normalFace Normal
 * @param Color (QColor)
 * @param Light coords
 * @param intensity of color
 * @return QColor (according to phong and the intensity passed as a parameter)
 */
QColor Canvas::lightColor ( float x, float y, float z, Normal normalFace, 
                            QColor Color, punto3d * Light, int intensity )
{
    // Color components
    float Red, Green, Blue, Redp, Greenp, Bluep;
    Red = Color.red(); Green = Color.green(); Blue = Color.green();

    // pixel illumination
    float difu, AmbientLight = 55.;

    // phong
    difu = Difuse( normalFace, x, y, z, Light, intensity ); // Canvas::Difuse
    
    dgcapp * d = ( dgcapp * ) this->parent();
    QColor C( d->getRefColor() );
    
    float reflect = 2 * z * ( y + x + z - 1 ) / 100000;
    
    if ( d->getCurrentShading() != REFLECT ) reflect = 0;

    // update color components
    Redp = AmbientLight + Red * difu + C.red() * reflect;
    if ( Redp > 255 ) Redp = 255;

    Greenp = AmbientLight + Green * difu + C.green() * reflect;
    if ( Greenp > 255 ) Greenp = 255;

    Bluep = AmbientLight + Blue * difu + C.blue() * reflect;
    if ( Bluep > 255 ) Bluep = 255;
    
    // compose color
    QColor c; c.setRgb( Redp, Greenp, Bluep );
    
    return c;
}

/**
 * @brief modifies the color of a given pixel
 * @param normalPixel pixel Normal (struct Normal { float x, y, z; };)
 * @param x x coord of pixel
 * @param y y coord of pixel
 * @param z z coord of pixel
 * @param Light light coords
 * @param intensity light power
 * @return color modifier
 */
float Canvas::Difuse ( Normal normalPixel, float x, float y, float z,
                       punto3d * Light, int intensity )
{
    // known intensity and constant
    float k = 1, kd = 1;
    Normal N;
    float innerProd, total = 0;
    double dist;

    // x, y, z -> resultant vector
    swap(x,y);
    N.x = Light->x - x; N.y = Light->y - y; N.z = Light->z - z;

    // tenemos que normalizar el vector
    dist = sqrt( N.x * N.x + N.y * N.y + N.z * N.z );
    N.x /= dist; N.y /= dist; N.z /= dist;

    innerProd = normalPixel.x * N.x + normalPixel.y * N.y + normalPixel.z * N.z;
      
    // si esta entre cero y uno, afecta al color
    // Ecuacion de phong sin reflexion, iluminacion difusa
    if ( innerProd > 0. and innerProd <= 1. )
        total += ( intensity * innerProd * kd ) / ( k + dist );
      
    return total;
}