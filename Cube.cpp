//
//
//  @ Project : DgcApp
//  @ File Name : Cube.cpp
//  @ Date : 15/03/2012
//  @ Author : Leonardo Lanchas
//
//


#include "Cube.h"

/**
 * @param h int height
 * @param w int width
 * @param d int depth
 */
Cube::Cube( int h, int w, int d )
{
    Name = "Cube";
    
    w /= 2; h /=2; d /= 2;
    
    punto3d * P0 = new punto3d(); // 00
    P0->x = w; P0->y = h; P0->z = d; P0->h = 1;
    Vertices.push_back( P0 );
    
    punto3d * P1 = new punto3d(); // 11
    P1->x = -w; P1->y = h; P1->z = d; P1->h = 1;
    Vertices.push_back( P1 );
    
    punto3d * P2 = new punto3d(); // 22
    P2->x = -w; P2->y = -h; P2->z = d; P2->h = 1;
    Vertices.push_back( P2 );
    
    punto3d * P3 = new punto3d(); // 33
    P3->x = w; P3->y = -h; P3->z = d; P3->h = 1;
    Vertices.push_back( P3 );

    punto3d * P4 = new punto3d(); // 44
    P4->x = w; P4->y = h; P4->z = -d; P4->h = 1;
    Vertices.push_back( P4 );

    punto3d * P5 = new punto3d(); // 55
    P5->x = -w; P5->y = h; P5->z = -d; P5->h = 1;
    Vertices.push_back( P5 );

    punto3d * P6 = new punto3d(); // 66
    P6->x = -w; P6->y = -h; P6->z = -d; P6->h = 1;
    Vertices.push_back( P6 );

    punto3d * P7 = new punto3d(); // 77
    P7->x = w; P7->y = -h; P7->z = -d; P7->h = 1;
    Vertices.push_back( P7 );

    createEdges();
    
    NEdges    = 18; // + triangles + axis
    NVertices = 8;
    
    createSelfAxis( d );
    
    createFaces();
}

/**
 * @brief Copy Constructor
 * @param C Cube&
 */
Cube::Cube( const Cube & C )
{
    for ( int i = 0; i < C.NVertices; i++ )
    {
        punto3d * p = new punto3d;
        p->x = C.Vertices[ i ]->x; p->y = C.Vertices[ i ]->y;
        p->z = C.Vertices[ i ]->z; p->h = C.Vertices[ i ]->h;
        Vertices.push_back( p );
    }
    
    NFaces    = C.NFaces;
    NEdges    = C.NEdges;
    NVertices = C.NVertices;
    Name      = C.Name;
    
    createEdges();
    createSelfAxis( 25 );
    createFaces();
}

Cube::~Cube(){ }

/**
 * @brief Creates the cube 12 faces (triangular) and computes their normal
 */
void Cube::createFaces( void ) 
{
    int idx[ 12 ][ 3 ] = { { 0, 1, 2 }, { 0, 2, 3 }, { 4, 0, 3 },
                           { 4, 3, 7 }, { 5, 2, 1 }, { 5, 6, 2 }, 
                           { 4, 6, 5 }, { 4, 7, 6 }, { 4, 5, 1 },
                           { 4, 1, 0 }, { 7, 3, 6 }, { 7, 3, 2 } };
    Face * F;
    for ( int i = 0; i < 12; i++ ) 
    {
        F = new Face( Vertices[ idx[ i ][ 0 ] ], 
                      Vertices[ idx[ i ][ 1 ] ], 
                      Vertices[ idx[ i ][ 2 ] ]  );
        
        F->ComputeNormal();
        Faces.push_back( F );
    }
    NFaces = 12;
}

/**
 * @brief join vertices to make faces
 */
void Cube::createEdges( void )
{
    Edges.push_back( new Edge ( Vertices[ 0 ], Vertices[ 1 ] ) );
    Edges.push_back( new Edge ( Vertices[ 1 ], Vertices[ 2 ] ) );
    Edges.push_back( new Edge ( Vertices[ 2 ], Vertices[ 3 ] ) );
    Edges.push_back( new Edge ( Vertices[ 3 ], Vertices[ 0 ] ) );
    Edges.push_back( new Edge ( Vertices[ 4 ], Vertices[ 5 ] ) );
    Edges.push_back( new Edge ( Vertices[ 5 ], Vertices[ 6 ] ) );
    Edges.push_back( new Edge ( Vertices[ 6 ], Vertices[ 7 ] ) );
    Edges.push_back( new Edge ( Vertices[ 7 ], Vertices[ 4 ] ) );
    Edges.push_back( new Edge ( Vertices[ 0 ], Vertices[ 4 ] ) );
    Edges.push_back( new Edge ( Vertices[ 1 ], Vertices[ 5 ] ) );
    Edges.push_back( new Edge ( Vertices[ 2 ], Vertices[ 6 ] ) );
    Edges.push_back( new Edge ( Vertices[ 3 ], Vertices[ 7 ] ) );

    /* Triangles */
    Edges.push_back( new Edge ( Vertices[ 0 ], Vertices[ 2 ] ) );
    Edges.push_back( new Edge ( Vertices[ 4 ], Vertices[ 6 ] ) );
    Edges.push_back( new Edge ( Vertices[ 4 ], Vertices[ 3 ] ) );
    Edges.push_back( new Edge ( Vertices[ 5 ], Vertices[ 2 ] ) );
    Edges.push_back( new Edge ( Vertices[ 0 ], Vertices[ 5 ] ) );
    Edges.push_back( new Edge ( Vertices[ 3 ], Vertices[ 6 ] ) );
}

/**
 * @brief Clone cube
 * @return newly created cube
 */
iObj * Cube::Clone() { return new Cube( * this ); }