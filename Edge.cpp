//
//
//  @ Project : DgcApp
//  @ File Name : Edge.cpp
//  @ Date : 15/03/2012
//  @ Author : Leonardo Lanchas
//
//


#include "Edge.h"
#include "punto3d.h"

/**
 * @brief creates a new edge
 * @param v1 vertex 1 (struct punto3d { float x, y, x })
 * @param v2 vertex 2 (struct punto3d { float x, y, x })
 */
Edge::Edge( punto3d * v1, punto3d * v2 ) { Ini = v1; End = v2; }

/**
 * @brief copy constructor
 * @param E Edge &
 */
Edge::Edge( const Edge & E )
{
    Ini = new punto3d; End = new punto3d;
    Ini->x = E.Ini->x; Ini->y = E.Ini->y; Ini->z = E.Ini->z; Ini->h = E.Ini->h;
    End->x = E.End->x; End->y = E.End->y; End->z = E.End->z; End->h = E.End->h;
}

Edge::~Edge() { }

/**
 * 
 * @return returns initial point of the edge
 */
punto3d * Edge::GetIni() { return Ini; }

/**
 * 
 * @return returns final point of the edge
 */
punto3d * Edge::GetEnd() { return End; }