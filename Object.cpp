//
//
//  @ Project : DgcApp
//  @ File Name : Object.cpp
//  @ Description: General Object
//  @ Date : 15/03/2012
//  @ Author : Leonardo Lanchas
//
//


#include "Object.h"


Object::Object() { zBuffer = NULL; }

/**
 * @brief Cleans vertices, edges, faces and zbuffer
 */
Object::~Object()
{
    int size = Vertices.size();
    for ( int i = 0; i < size; i++ ) delete Vertices[ i ];
    Vertices.clear();
    
    size = Edges.size();
    for ( int i = 0; i < size; i++ ) delete Edges[ i ];
    Edges.clear();
    
    size = Faces.size();
    for ( int i = 0; i < size; i++ ) delete Faces[ i ];
    Faces.clear();
    
    if ( zBuffer ) delete [] zBuffer;
}

/**
 * 
 * @return Pointer to object edges
 */
vector < Edge * > * Object::getEdges() { return & Edges; }

/**
 * @brief Creates a new edge and adds it to the end of the edges so the object
 * can self rotate
 * @param d depth
 */
void Object::createSelfAxis( int d )
{
    /* self axis */
    punto3d * axisIni = new punto3d(); // axis Initial point
    axisIni->x = 0; axisIni->y = 0; axisIni->z = d; axisIni->h = 1;
    addVertex( axisIni );
    
    for( int i = 0; i < NVertices; i++ )
    {
        axisIni->x += Edges[ i ]->GetIni()->x; // sum every x
        axisIni->y += Edges[ i ]->GetIni()->y; // sum every y
    }
    axisIni->x /= NVertices; // compute x mean
    axisIni->y /= NVertices; // compute y mean

    if ( Name != "Pyramid" )
    {
        punto3d * axisEnd = new punto3d(); // axis End point
        axisEnd->x = axisIni->x;  axisEnd->y = axisIni->y; axisEnd->z = -d;
        axisEnd->h = 1;
        addVertex( axisEnd );
        Edges.push_back( new Edge( axisIni, axisEnd ) ); // self axis
    }
    else Edges.push_back( new Edge( axisIni, Edges[ 3 ]->GetEnd() ) ); // self axis
    
    NEdges++; // + triangles + axis
}

/**
 * @brief Transform every object vertices by multiplying them by the transformation
 * matrix.
 * @param T (double) Transformation matrix
 */
void Object::computeTransformation( double T[ 4 ][ 4 ] )
{
    for ( int i = 0; i < NVertices; i++ )
    {
        float parx, pary, parz, parh, x, y, z, h;

        x = Vertices[ i ]->x; y = Vertices[ i ]->y;
        z = Vertices[ i ]->z; h = Vertices[ i ]->h;

        /* vertex * transformation matrix */
        parx = x * T[ 0 ][ 0 ] + y * T[ 1 ][ 0 ] + z * T[ 2 ][ 0 ] + h * T[ 3 ][ 0 ];
        pary = x * T[ 0 ][ 1 ] + y * T[ 1 ][ 1 ] + z * T[ 2 ][ 1 ] + h * T[ 3 ][ 1 ];
        parz = x * T[ 0 ][ 2 ] + y * T[ 1 ][ 2 ] + z * T[ 2 ][ 2 ] + h * T[ 3 ][ 2 ];
        parh = x * T[ 0 ][ 3 ] + y * T[ 1 ][ 3 ] + z * T[ 2 ][ 3 ] + h * T[ 3 ][ 3 ];

        /* update vertex */
        Vertices[ i ]->x = parx; Vertices[ i ]->y = pary;
        Vertices[ i ]->z = parz; Vertices[ i ]->h = parh;
    }

    for ( int i = 0; i < NFaces; i++ ) Faces[ i ]->ComputeNormal();
}

/**
 * @brief Creates escalation matrix and invokes 
 * Object::computeTransformation( double T[ 4 ][ 4 ] ) with it.
 * @param sx x Escalation
 * @param sy y Escalation
 * @param sz z Escalation
 */
void Object::Escalation( double sx, double sy, double sz )
{
    double E[4][4] = { { sx,  0,  0,  0 },
                       {  0, sy,  0,  0 },
                       {  0,  0,  sz, 0 },
                       {  0,  0,  0,  1 } };
    
    computeTransformation( E );
}

/**
 * @brief Creates Translation matrix and invokes 
 * Object::computeTransformation( double T[ 4 ][ 4 ] ) with it.
 * @param tx x Translation
 * @param ty y Translation
 * @param tz z Translation
 */
void Object::Translation( double tx, double ty, double tz )
{
    double T[4][4] = { { 1,  0,  0,  0 },
                       { 0,  1,  0,  0 },
                       { 0,  0,  1,  0 },
                       { tx, ty, tz, 1 } };
    
    computeTransformation( T );
}

/**
 * @brief Creates Rotation in X matrix and invokes 
 * Object::computeTransformation( double T[ 4 ][ 4 ] ) with it.
 * @param ang radians to rotate
 */
void Object::RotationX( double ang )
{
    double R[4][4] = { { 1,           0,          0,  0 },
                       { 0,  cos( ang ), sin( ang ),  0 },
                       { 0, -sin( ang ), cos( ang ),  0 },
                       { 0,           0,          0,  1 } };
    
    computeTransformation( R );
}

/**
 * @brief Creates Rotation in Y matrix and invokes 
 * Object::computeTransformation( double T[ 4 ][ 4 ] ) with it.
 * @param ang radians to rotate
 */
void Object::RotationY( double ang )
{
    double R[4][4] = { { cos( ang ), 0, -sin( ang ),  0 },
                       {          0, 1,           0,  0 },
                       { sin( ang ), 0,  cos( ang ),  0 },
                       {          0, 0,           0,  1 } };
    
    computeTransformation( R );
}

/**
 * @brief Creates Rotation in Z matrix and invokes 
 * Object::computeTransformation( double T[ 4 ][ 4 ] ) with it.
 * @param ang radians to rotate
 */
void Object::RotationZ( double ang )
{
    double R[4][4] = { {  cos( ang ), sin( ang ), 0,  0 },
                       { -sin( ang ), cos( ang ), 0,  0 },
                       {           0,          0, 1,  0 },
                       {           0,          0, 0,  1 } };
    
    computeTransformation( R );
}

/**
 * @brief Rotates object in its own axis.
 * @param ang radians to rotate
 */
void Object::selfRotation( double ang )
{
    float x = Edges.back()->GetEnd()->x, y = Edges.back()->GetEnd()->y,
          z = Edges.back()->GetEnd()->z;
    
    Translation( -x, -y, -z ); // take objecto to origin
    
    float a  = Edges.back()->GetIni()->x;
    float b  = Edges.back()->GetIni()->y;
    float c  = Edges.back()->GetIni()->z;
    
    float d1 = sqrt( b * b + c  * c );
    float d2 = sqrt( a * a + d1 * d1 );

    if ( c / d1 > 0 ) RotationX( asin( b / d1 ) );
    else RotationX( 3.14159265 - asin( b / d1 ) );

    if ( d1 / d2 > 0 ) RotationY( asin( -a / d2 ) );
    else RotationY( 3.14159265 - asin( -a / d2 ) );

    RotationZ( 0.02 * ( ang ) );

    if( d1 / d2 > 0 ) RotationY( -asin ( -a / d2 ) );
    else RotationY( -( 3.14159265 - asin( -a / d2 ) ) );

    if( c / d1 > 0 ) RotationX( -asin( b / d1 ) );
    else RotationX( -( 3.14159265 - asin ( b / d1 ) ) );
    
    Translation( x, y, z ); // bring object back
}

/**
 * @brief returns its object points values
 * @param FaceIndex Face from which we must retrieve the points value
 * @param P1 first point
 * @param P2 second point
 * @param P3 third point
 */
void Object::FacePoints( int FaceIndex, punto3d * P1, punto3d * P2, punto3d * P3 )
{
    if ( FaceIndex < NFaces ) Faces[ FaceIndex ]->Points( P1, P2, P3 );
}

/**
 * @brief returns the N-th face of the object
 * @param N N-th face (int)
 * @throws std::out_of_range  If N is an invalid index.
 * @return int
 */
Face * Object::getNFace( int N ) { return Faces.at( N ); }

/**
 * @brief set object name (cube, pyramid, or rev)
 * @param s string containing the object name
 */
void Object::setName( QString s ) { Name = s; }

/**
 * @brief returns object name
 * @return string
 */
QString Object::getName( void ) { return Name; }

/**
 * 
 * @return int -> number of object faces
 */
int Object::getNumFaces(){ return NFaces; }

/**
 * @brief Adds new vertex to object
 * @param p vertex to add
 */
void Object::addVertex( punto3d * p )
{
    Vertices.push_back( p ); // append to vertex list
    NVertices++; // 1 more vertex
}