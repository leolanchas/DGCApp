//
//
//  @ Project : DgcApp
//  @ File Name : RevObj.h
//  @ Date : 15/03/2012
//  @ Author : Leonardo Lanchas
//
//


#if !defined(_REVOBJ_H)
#define _REVOBJ_H

#define REVOBJ 2

#include "Object.h"

class RevObj : public Object
{
public:
    RevObj( int );
    RevObj( struct rev *, int );
    RevObj( const RevObj & R );
    ~RevObj();
    
    void createFaces( void );
    void createEdges( void );
    
    iObj * Clone();
    
private:
    void init( struct rev *, int );
    
    vector < punto3d * > Meridians;
    int NMerid;
    int Points;
};

#endif  //_REVOBJ_H
