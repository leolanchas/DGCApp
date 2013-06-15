//
//
//  @ Project : DgcApp
//  @ File Name : Face.h
//  @ Date : 15/03/2012
//  @ Author : Leonardo Lanchas
//
//


#if !defined(_FACE_H)
#define _FACE_H

#include "punto3d.h"
#include "Normal.h"

class Face
{
public:
    Face();
    Face( punto3d *, punto3d *, punto3d * );
    Face( punto3d *, punto3d *, punto3d *, int i, int j, int k );
    Face( const Face & );
    ~Face();
    
    void SetPoint( punto3d *, punto3d *, punto3d * );
    void SetIndex ( int, int, int );
    
    void Points( punto3d *, punto3d *, punto3d * );
    
    float getD( void );
    Normal getNormal( void );
    
    void ComputeNormal( void );
    
private:
    punto3d * P1, * P2, * P3;
    int i, j, k;
    float D;
    Normal N;
};

#endif  //_FACE_H
