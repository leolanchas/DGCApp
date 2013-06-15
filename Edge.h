//
//
//  @ Project : DgcApp
//  @ File Name : Edge.h
//  @ Date : 15/03/2012
//  @ Author : Leonardo Lanchas
//
//


#if !defined(_EDGE_H)
#define _EDGE_H

#include "punto3d.h"

#include <QColor>

#include <vector>

class Edge
{
public:
    Edge( punto3d * v1, punto3d * v2 );
    Edge( const Edge & );
    ~Edge();
    
    punto3d * GetIni();
    punto3d * GetEnd();

private:
    punto3d * Ini;
    punto3d * End;
};

#endif  //_EDGE_H