/*
 * File:   dgcapp.cpp
 * Author: Leo
 *
 * Created on 8 de marzo de 2012, 12:11
 */

#include "dgcapp.h"
#include "Cube.h"
#include "Pyramid.h"
#include "RevObj.h"
#include "Layer.h"

/*
 * Macros used to get pointers to canvases in dgcapp
 * (Canvas * dgcapp::getCanvas( int i )).
 */

#define Air   1
#define Persp 2
#define Front 3
#define Lat   4

// index of 'define border' option when creating a rev Object.
#define BORDER 4

/**
 *  @brief  DgcApp constructor (application constructor, the first to exec.)
 *
 *  Creates, positions and enables interface objects such as mouse tracking on
 *  canvases.
 *  Sets up UI, Assigns labels to update the coordinates information, registers
 *  prototype objects, create subjects and observers and finally connects signals
 *  and slots.
 */
dgcapp::dgcapp() 
{
/***********                     Interface                      ***************/
    
    // Creating, positioning and enable mouse tracking on Canvas.
    LAir   = new Canvas( this ); LAir->setMouseTracking( true );
    LPersp = new Canvas( this ); LPersp->setMouseTracking( true );
    LFront = new Canvas( this ); LFront->setMouseTracking( true );
    LLat   = new Canvas( this ); LLat->setMouseTracking( true );
    
    // Canvases are painted white
    QPalette Pal( QApplication::palette() );
    Pal.setColor( QPalette::Background, Qt::white );
    LAir->setAutoFillBackground( true );   LAir->setPalette( Pal );
    LPersp->setAutoFillBackground( true ); LPersp->setPalette( Pal );
    LFront->setAutoFillBackground( true ); LFront->setPalette( Pal );
    LLat->setAutoFillBackground( true );   LLat->setPalette( Pal );
    
    // Initialization of the interface created with Designer
    widget.setupUi( this );
    
    // Init rev object
    resetRev();
    
    // show light vals
    widget.LightXVal->setText( QString::number( 80 ) );
    widget.LightYVal->setText( QString::number( 0 ) );
    widget.LightZVal->setText( QString::number( 0 ) );
    widget.intensityVal->setText( QString::number( 300 ) );
    
    widget.Nmerid->setText( QString::number( 20 ) );
    
    // Assign Labels to update the coordinate information
    LAir->SetLabel( widget.LabAir );
    LPersp->SetLabel( widget.LabPersp );
    LFront->SetLabel( widget.LabFront );
    LLat->SetLabel( widget.LabLat );
    
    // QDialog (? X) -> QWindow (- ■ X)
    this->setWindowFlags( Qt::Window );
    
    // Definición de la interfaz de distribución
    this->setLayout( widget.layout );
    
    // add the 4 canvases
    widget.layAir->addWidget(   LAir,   0, 0 );
    widget.layPersp->addWidget( LPersp, 0, 0 );
    widget.layFront->addWidget( LFront, 1, 0 );
    widget.layLat->addWidget(   LLat,   1, 0 );
    
    // Update Layers' containter info
    widget.gbCapas->setTitle( "Capas (#" + QString::number( ScreenLayers.size() ) + ")" );
    widget.lbColor->setText( "#000000" );
    widget.lbColor->setPalette( QPalette( Qt::black ) );
    widget.lbColor->setAutoFillBackground( true );
    widget.lbObjColor->setText( "#ffff00" );
    widget.lbObjColor->setPalette( QPalette( Qt::yellow ) );
    widget.lbObjColor->setAutoFillBackground( true );
    
    C = Qt::yellow; // Reflection Color
    
/***********                 Register Objects                   ***************/

    RegisterObj( new Cube() );
    RegisterObj( new Pyramid() );
    RegisterObj( new RevObj( 20 ) );

/***********            Subjects and Observers                  ***************/
        
    // Observers = Canvas | Client    = dgcapp | Subject   = ScreenLayers
    
    LAir->SetSubject( & ScreenLayers ); LFront->SetSubject( & ScreenLayers );
    LLat->SetSubject( & ScreenLayers ); LPersp->SetSubject( & ScreenLayers );
    
/***********                    Connections                     ***************/
    
    // Click on button 'Ejes' -> erase/paint axis on Canvases
    connect( widget.pbEjes, SIGNAL( clicked() ), LAir,   SLOT( ToggleAxis() ) );
    connect( widget.pbEjes, SIGNAL( clicked() ), LPersp, SLOT( ToggleAxis() ) );
    connect( widget.pbEjes, SIGNAL( clicked() ), LLat,   SLOT( ToggleAxis() ) );
    connect( widget.pbEjes, SIGNAL( clicked() ), LFront, SLOT( ToggleAxis() ) );
    
    // Click on 'Dibujar' button
    connect( widget.pbDibujar, SIGNAL( clicked() ), this, SLOT( Draw() ) );
    
    // Click on 'Borrar' button    
    connect( widget.pbBorrar, SIGNAL( clicked() ), this, SLOT( erase() ) );

    // Click on Layer visibility
    connect( widget.listWidget, SIGNAL( itemChanged( QListWidgetItem * ) ), 
             this,              SLOT( ToggleLayer( QListWidgetItem * ) ) );
    
    // Click on 'Color' button
    connect( widget.pbColor, SIGNAL( clicked() ), this, SLOT( SetColor() ) );
    connect( widget.pbObjColor, SIGNAL( clicked() ), this, SLOT( SetRefColor() ) );
}

/**
 *  @brief  DgcApp destructor.
 *
 *  Destroys layers and registered objects and canvases.
 */
dgcapp::~dgcapp()
{
    // delete objects on screen
    int size = ScreenLayers.size();
    for ( int i = 0; i < size; i++ ) delete ScreenLayers[ i ];
    
    // delete registered models
    size = regObj.size();
    for ( int i = 0; i < size; i++ ) delete regObj[ i ];
    
    // delete canvases
    delete LAir; delete LPersp; delete LFront; delete LLat;
}

/**
 * 
 * Slots
 * 
 */

/**
 *  @brief  Creates new Object and its layer and append to list.
 *  Finally, updates canvases.
 *
 *  Creates new object from the prototypes table. However, if user has defined
 *  a border, it has previously captured all 3d points (punto3d: struct punto3d)
 *  in an array and passed them to the constructor.
 *  If the object is successfully created, a new layer is created and the object
 *  is assigned to that layer.
 *  Finally, the layer is informed of the 4 canvases and observers are updated.
 */
void dgcapp::Draw()
{
    iObj * o = NULL;
    if ( ! isBorderSelected() ) o = CreateObj( widget.cbFigOpt->currentIndex() );
    else
        if ( drawing.num_p ) 
        {
            o = new RevObj( & drawing, getNMerid() ); // new revolution object
            widget.cbFigOpt->setCurrentIndex( 0 ); // option selected = none
            resetRev(); // struct drawing number of points = 0
        }
    
    if ( o )
    {
        Layer * L = new Layer( o );
        ScreenLayers.push_back( L ); // register layer
        
        // Update Layers' containter info
        widget.gbCapas->setTitle( "Capas (#" + QString::number( ScreenLayers.size() ) + ")" );
        
        QListWidgetItem * qlistwidgetitem = new QListWidgetItem( widget.listWidget );        
        qlistwidgetitem->setCheckState( Qt::Checked );
        qlistwidgetitem->setFlags( Qt::ItemIsSelectable  | Qt::ItemIsEditable
                                 | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled
                                 | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled
                                 | Qt::ItemIsTristate );
        
        int size = ScreenLayers.size();
        qlistwidgetitem->setText( "Capa " + QString::number( size )
                                + " - Object: " + o->getName() );
    
        // add observers
        L->Adscribe( LAir ); L->Adscribe( LPersp );
        L->Adscribe( LLat ); L->Adscribe( LFront ); 

        // Update State
        for ( int i = 0; i < size; i++ ) ScreenLayers.at( i )->SetState();
    }
}

/**
 *  @brief Toggle object in layer
 *  @param QListWidgetItem * item. It provides an item for use with the 
 *  QListWidget item view class. A QListWidgetItem represents a single item in a 
 *  QListWidget.
 *
 *  Hides or shows the drawn object.
 */
void dgcapp::ToggleLayer( QListWidgetItem * item )
{
    int row = widget.listWidget->row( item ); // get clicked row (item)
    
    if ( row >= 0 and ScreenLayers[ row ]->isVisible() ==
                                        ( item->checkState() != Qt::Checked ) )
    {
        // toggle
        ScreenLayers[ row ]->ToggleVisible( item->checkState() == Qt::Checked );
        
        update();

        // Update State
        int size = ScreenLayers.size();
        for ( int i = 0; i < size; i++ ) ScreenLayers.at( i )->SetState();
    }
}

/**
 *  @brief Returs a pointer to a canvas
 *  @param i the index canvas to be retrieved. i values are predefined: Air (1),
 *  Persp (2), Front (3), Lat (4).
 *  @return Canvas *.
 */
Canvas * dgcapp::getCanvas( int i )
{
    switch ( i )
    {
        case Air:   return LAir;   break;
        case Persp: return LPersp; break;
        case Front: return LFront; break;
        case Lat:   return LLat;   break;
        default:    return NULL;
    }
}

/**
 *  @brief  Changes object color.
 *
 *  Sets the selected color (from QColorDialog) to the layer and its corresponding
 *  QListWidgetItem in layers' list.
 */
void dgcapp::SetColor( void )
{
    QColor color = QColorDialog::getColor( Qt::red, this );
    if ( color.isValid() )
    {
        // update QLabel (lbcolor) palette and text with new color and its name.
        widget.lbColor->setText( color.name() );
        widget.lbColor->setPalette( QPalette( color ) );
        
        int row = widget.listWidget->currentRow();
        
        if ( row >= 0 )
        {
            ScreenLayers[ row ]->setColor( color ); // update layer color
            
            // set current item color in qlistwidget to identify it.
            widget.listWidget->item( row )->setBackgroundColor( color );
            
            // Update State
            int size = ScreenLayers.size();
            for ( int i = 0; i < size; i++ ) ScreenLayers.at( i )->SetState();
        }
    }
}

/**
 *  @brief  Changes reflection color.
 *
 *  Sets the reflection color (from QColorDialog) for phong's model
 */
void dgcapp::SetRefColor( void )
{
    QColor color = QColorDialog::getColor( Qt::red, this );
    if ( color.isValid() )
    {
        // update QLabel (lbcolor) palette and text with new color and its name.
        widget.lbObjColor->setText( color.name() );
        widget.lbObjColor->setPalette( QPalette( color ) );
        C = color;
    }
    // Update State
    int size = ScreenLayers.size();
    for ( int i = 0; i < size; i++ ) ScreenLayers.at( i )->SetState();
}

/**
 *  @brief returns what transformation is selected: None, Traslation, escalation
 *  or rotation.
 *  @return int. 0 -> None; 1 -> Translation; 2 -> Rotation; 
 *  3 -> Self Axis Rotation; 4 -> Escalation;
 */
int dgcapp::getCurrentTransform( void ) { return widget.cbTransform->currentIndex(); }

/**
 *  @brief returns the index of the selected layer in the list widget.
 *  @return int. Number >= 0 if any row selected; -1 in other case.
 */
int dgcapp::getCurrentLayer( void ) { return widget.listWidget->currentRow(); }

/**
 *  @brief returns the index of the selected shading(ZBuffer, ray tracing or difuse).
 *  @return int. Number >= 0 if any row selected; -1 in other case.
 */
int dgcapp::getCurrentShading( void ) { return widget.cbShading->currentIndex(); }

/**
 *  @brief returns true if the user has selected to define the border of a 
 *  revolution object.
 *  @return bool.
 */
bool dgcapp::isBorderSelected( void ) { return widget.cbFigOpt->currentIndex() == BORDER; }

/**
 *  @brief deletes an object or a line depending on the option selected.
 *
 *  If the user is defining a border line to line and clicks 'borrar', then the
 *  last line is erased. In other case, the object in the selected layer is deleted.
 */
void dgcapp::erase( void )
{
    if ( isBorderSelected() ) revEraseLine();
    else // erase selected object and its layer
    {
        int l = getCurrentLayer();
        if ( l >= 0 ) deleteLayer( l ); // delete from layers list
    }
    // update canvases
    LFront->Update(); LAir->Update(); LPersp->Update(); LLat->Update();
}

/**
 *  @brief Deletes the selected layer and the object associated with it.
 *  @param L Layer index.
 *
 *  Deletes the layer from the register and its name from the list widget.
 */
void dgcapp::deleteLayer( int L )
{
    // delete name from the listwidget.
    QListWidgetItem * item = widget.listWidget->takeItem( L );
    widget.listWidget->setCurrentRow( -1 );
    delete item;

/******************************************************************************/
    //delete ScreenLayers[ L ]; // BUG
/******************************************************************************/
    
    ScreenLayers.erase( ScreenLayers.begin() + L ); // delete it from the register

    // Update Layers' containter info
    widget.gbCapas->setTitle( "Capas (#" + QString::number( ScreenLayers.size() ) + ")" );
}

/**
 *  @brief sets struct rev (drawing; dgcapp.h) points number to 0.
 */
void dgcapp::resetRev( void ) { drawing.num_p = 0; }

/**
 *  @brief returns the number of points drawn by the user
 *  @return int
 */
int dgcapp::getRevNumP( void ) { return drawing.num_p; }

/**
 *  @brief returns the i-th x coordinate of the i-th 'punto3d' list in the struct rev.
 *  @param i (int) i-th X coordinate to retrieve
 *  @return float (x coord)
 */
float dgcapp::getRevIX( int i )   { return drawing.lista_P[ i ].x; }

/**
 *  @brief returns the i-th y coordinate of the i-th 'punto3d' list in the struct rev.
 *  @param i (int) i-th Y coordinate to retrieve
 *  @return float (y coord)
 */
float dgcapp::getRevIY( int i )   { return drawing.lista_P[ i ].y; }

/**
 *  @brief decreases the number of lines by one
 */
void dgcapp::revEraseLine( void ) { if ( drawing.num_p ) drawing.num_p--; }

/**
 *  @brief assigns values to the next punto3d in the struct rev list.
 *  @param float x the X coordinate
 *  @param float y the Y coordinate
 *  @param float z the Z coordinate
 *  @param float h the H coordinate
 * 
 *  increases the number of points by one
 */
void dgcapp::setRevPoint( float x, float y, float z, float h )
{
    drawing.lista_P[ drawing.num_p ].x = x;
    drawing.lista_P[ drawing.num_p ].y = y;
    drawing.lista_P[ drawing.num_p ].z = z;
    drawing.lista_P[ drawing.num_p ].h = h;
    drawing.num_p++;
}

/**
 *  @brief returns intensity val from line edit in the main window.
 *  @return int
 */
int dgcapp::getIntensity( void ) { return widget.intensityVal->text().toInt(); }

/**
 *  @brief returns Light X coord val from line edit in the main window
 *  @return int
 */
int dgcapp::getLightX( void ) { return widget.LightXVal->text().toInt(); }

/**
 *  @brief returns Light Y coord val from line edit in the main window.
 *  @return int
 */
int dgcapp::getLightY( void ) { return widget.LightYVal->text().toInt(); }

/**
 *  @brief returns Light Z coord val from line edit in the main window.
 *  @return int
 */
int dgcapp::getLightZ( void ) { return widget.LightZVal->text().toInt(); }

/**
 *  @brief returns number of meridians to create the rev object,
 *  from line edit in the main window.
 *  @return int
 */
int dgcapp::getNMerid( void ) { return widget.Nmerid->text().toInt(); }

/**
 * @brief Returns the reflection Color
 * @return QColor
 */
QColor dgcapp::getRefColor( void ) { return C; }

/**
 * 
 * Non Slots
 * 
 */

/**
 *  @brief Clones the prototype selected
 *  @param i i-th registered object
 *  @return newly cloned object
 *
 *  If i is wrong, NULL is returned.
 */
iObj * dgcapp::CreateObj( int i )
{
    i--; // to match comboBox index
    if( i >= 0 and i < ( int ) regObj.size() ) return regObj[ i ]->Clone();
    
    return NULL;
}

/**
 *  @brief Registers object prototype
 *  @param iObj * O. A pointer to an object (cube, pyramid, or rev)
 *
 *  Stores it to clone it when a user selects it a calls to draw (clicks on 'Dibujar')
 */
void dgcapp::RegisterObj( iObj * O ) { regObj[ regObj.size() ] = O; }