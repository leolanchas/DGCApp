//
//
//  @ Project : DgcApp
//  @ File Name : Object.h
//  @ Date : 15/03/2012
//  @ Author : Leonardo Lanchas
//
//


#if !defined(_OBJECT_H)
#define _OBJECT_H

#include "iObj.h"
#include "Face.h"
#include "Edge.h"

#include <QString>

#include <vector>
#include <cmath>
using namespace std;


class Object : public iObj
{
public:
    Object();
    ~Object();
    
    virtual void createFaces( void ) = 0;
    virtual void createEdges( void ) = 0;
    
    void addVertex( punto3d * );
    
    void setName( QString );
    QString getName( void );
    
    int getNumFaces();
    vector < Edge * > * getEdges();
    
    void createSelfAxis( int );
    
    void Escalation( double sx, double sy, double sz );
    void Translation( double tx, double ty, double tz );
    void RotationX( double ang );
    void RotationY( double ang );
    void RotationZ( double ang );
    void selfRotation( double );
    
    void FacePoints( int, punto3d *, punto3d *, punto3d * );
    
    Face * getNFace( int );

protected:
    void computeTransformation( double T[ 4 ][ 4 ] );
    
    QString Name;
    
    vector < Face * > Faces;
    vector < Edge * > Edges;
    vector < punto3d * > Vertices;
    float ** zBuffer;
    int NFaces, NEdges, NVertices;
};

#endif  //_OBJECT_H
