//
//
//  @ Project : DgcApp
//  @ File Name : Layer.h
//  @ Date : 15/03/2012
//  @ Author : Leonardo Lanchas
//
//


#if !defined(_LAYER_H)
#define _LAYER_H

#include <QColor>

#include "Subject.h"
#include "iObj.h"
#include "Edge.h"

#include <vector>
using namespace std;

class Layer : public Subject
{
public:
    Layer();
    Layer( iObj * );
    ~Layer();
    
    void SetObj( iObj * );
    iObj * getObj( void );
    
    vector < Edge * > * GetState();
    void SetState( void );
    
    void FacePoints( int, punto3d *, punto3d *, punto3d * );
    int getObjNumFaces( void );
    Face * getNFace( int );
    
    void setColor( QColor );
    QColor getColor( void );
    
    void ToggleVisible( void );
    
    void Escalation( double sx, double sy, double sz );
    void Translation( double tx, double ty, double tz );
    void RotationX( double ang );
    void RotationY( double ang );
    void RotationZ( double ang );
    void selfRotation( double );
    
    void ToggleVisible( bool );
    bool isVisible( void );
    
private:
    iObj * Obj;
    bool visible;
    QColor Color;
};

#endif  //_LAYER_H