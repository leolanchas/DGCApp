//
//
//  @ Project : DgcApp
//  @ File Name : Cube.h
//  @ Date : 15/03/2012
//  @ Author : Leonardo Lanchas
//
//


#if !defined(_CUBE_H)
#define _CUBE_H

#define CUBE 0

#include "Object.h"

class Cube : public Object
{
public:
    Cube( int h = 50, int w = 50, int d = 50 );
    Cube( const Cube & C );
    ~Cube();
    
    void createFaces( void );
    void createEdges( void );
    
    iObj * Clone();
};

#endif  //_CUBE_H
