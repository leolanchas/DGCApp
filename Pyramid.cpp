//
//
//  @ Project : DgcApp
//  @ File Name : Pyramid.cpp
//  @ Date : 15/03/2012
//  @ Author : Leonardo Lanchas
//
//


#include "Pyramid.h"

/**
 * @brief Creates a pyramid, with its edges, vertices, faces and self axis.
 */
Pyramid::Pyramid()
{
    Name = "Pyramid";
    
    punto3d * P0 = new punto3d; // 00
    P0->x = -50; P0->y = 70; P0->z = -70; P0->h = 1.;
    Vertices.push_back( P0 );
    
    punto3d * P1 = new punto3d; // 11
    P1->x = 10; P1->y = -55; P1->z = -70; P1->h = 1.;
    Vertices.push_back( P1 );
    
    punto3d * P2 = new punto3d; // 22
    P2->x = 50; P2->y = 100; P2->z = -70; P2->h = 1.;
    Vertices.push_back( P2 );
    
    int xMa = 50, yMa = 100, xMe = -50, yMe = -55;
    
    punto3d * P3 = new punto3d; // top
    P3->x = xMe + ( xMa - xMe ) / 2.; 
    P3->y = yMe + ( yMa - yMe ) / 2.; 
    P3->z = 100; // top
    P3->h = 1.;
    Vertices.push_back( P3 );

    createEdges();

    NEdges    = 6; // + triangles
    NVertices = 4;
    
    createSelfAxis( 0 );
    
    createFaces();
}

/**
 * @brief Copy constructor
 * @param P Pyramid &
 */
Pyramid::Pyramid( const Pyramid & P )
{
    for ( int i = 0; i < P.NVertices; i++ ) 
    {
        punto3d * p = new punto3d;
        p->x = P.Vertices[ i ]->x; p->y = P.Vertices[ i ]->y;
        p->z = P.Vertices[ i ]->z; p->h = P.Vertices[ i ]->h;
        Vertices.push_back( p );
    }
    
    NFaces    = P.NFaces;
    NEdges    = P.NEdges;
    NVertices = P.NVertices;
    Name      = P.Name;
    
    createEdges();
    createSelfAxis( 0 );
    createFaces();
}

Pyramid::~Pyramid() { }

/**
 * @brief joins vertices to create edges
 */
void Pyramid::createEdges( void )
{
    Edges.push_back( new Edge ( Vertices[ 0 ], Vertices[ 1 ] ) );
    Edges.push_back( new Edge ( Vertices[ 1 ], Vertices[ 2 ] ) );
    Edges.push_back( new Edge ( Vertices[ 2 ], Vertices[ 0 ] ) );
    Edges.push_back( new Edge ( Vertices[ 0 ], Vertices[ 3 ] ) );
    Edges.push_back( new Edge ( Vertices[ 1 ], Vertices[ 3 ] ) );
    Edges.push_back( new Edge ( Vertices[ 2 ], Vertices[ 3 ] ) );
}

/**
 * Creates faces and computes their normal
 */
void Pyramid::createFaces( void )
{
    int idx[ 4 ][ 3 ] = {  { 0, 1, 2 }, { 0, 1, 3 }, { 0, 2, 3 }, { 1, 2, 3 } };
    
    Face * F;
    for ( int i = 0; i < 4; i++ ) 
    {
        F = new Face( Vertices[ idx[ i ][ 0 ] ], 
                      Vertices[ idx[ i ][ 1 ] ], 
                      Vertices[ idx[ i ][ 2 ] ] );
        
        F->ComputeNormal();
        Faces.push_back( F );
    }
    NFaces = 4;
}

/**
 * Clone pyramid
 * @return newly pyramid
 */
iObj * Pyramid::Clone() { return new Pyramid( * this ); }