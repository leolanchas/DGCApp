//
//
//  @ Project : DgcApp
//  @ File Name : Pyramid.h
//  @ Date : 15/03/2012
//  @ Author : Leonardo Lanchas
//
//


#if !defined(_PYRAMID_H)
#define _PYRAMID_H

#define PYRAMID 1

#include "Object.h"

class Pyramid : public Object
{
public:
    Pyramid();
    Pyramid( const Pyramid & );
    ~Pyramid();
    
    void createFaces( void );
    void createEdges( void );

    iObj * Clone();
};

#endif  //_PYRAMID_H
