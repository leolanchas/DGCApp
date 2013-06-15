//
//
//  @ Project : DgcApp
//  @ File Name : iObj.h
//  @ Date : 15/03/2012
//  @ Author : Leonardo Lanchas
//
//


#if !defined(_IOBJ_H)
#define _IOBJ_H

#include <QString>
#include "punto3d.h"
#include "Face.h"

class iObj
{
public:
    virtual iObj * Clone() = 0;
    
    virtual void Escalation( double sx, double sy, double sz ) = 0;
    virtual void Translation( double tx, double ty, double tz ) = 0;
    virtual void RotationX( double ang ) = 0;
    virtual void RotationY( double ang ) = 0;
    virtual void RotationZ( double ang ) = 0;
    virtual void selfRotation( double ) = 0;
    
    virtual void FacePoints( int FaceIndex, punto3d *, punto3d *, punto3d * ) = 0;
    
    virtual int getNumFaces( void ) = 0;
    virtual Face * getNFace( int N ) = 0;
    
    virtual QString getName( void ) = 0;
    
    virtual ~iObj() { };
};

#endif  //_IOBJ_H
