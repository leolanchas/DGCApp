//
//
//  @ Project : DgcApp
//  @ File Name : punto3d.h
//  @ Date : 15/03/2012
//  @ Author : Leonardo Lanchas
//
//


#if !defined(_PUNTO3D_H)
#define _PUNTO3D_H


struct punto3d { float x, y, h, z; };

struct rev
{
    struct punto3d lista_P[ 1000 ]; // points list
    int num_p; // number of points of the first meridian
};

#endif  //_PUNTO3D_H
