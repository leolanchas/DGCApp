//
//
//  @ Project : DgcApp
//  @ File Name : Layer.cpp
//  @ Date : 15/03/2012
//  @ Author : Leonardo Lanchas
//
//


#include "Layer.h"
#include "Object.h"

Layer::Layer() { visible = true; SetObj( NULL ); }

Layer::Layer( iObj * o ) { visible = true; SetObj( o ); }

Layer::~Layer() { delete Obj; }

/**
 * @brief Assign object to layer
 * @param O iObj *
 */
void Layer::SetObj( iObj * O ) { Obj = O; }

/**
 * @brief returns a pointer to the layer object
 * @return iObj * (object)
 */
iObj * Layer::getObj( void ) { return Obj; }

/**
 * @brief returns the object edges so the canvas is able to paint them
 * @return ( vector < Edge * > * ) if the object is visible. NULL in other case.
 */
vector < Edge * > * Layer::GetState()
{
    Object * o = dynamic_cast < Object * > ( Obj );
    
    if ( o and visible ) return o->getEdges();
    
    return NULL;
}

/**
 * @brief updates state and notifies
 */
void Layer::SetState() { Notify(); }

/**
 * @brief Interfaces iObj::FacePoints( int, punto3d *, punto3d *, punto3d * )
 * @param FaceIndex Face number
 * @param P1 punto3d
 * @param P2 punto3d
 * @param P3 punto3d
 */
void Layer::FacePoints( int FaceIndex, punto3d * P1, punto3d * P2, punto3d * P3 )
{
    Obj->FacePoints( FaceIndex, P1, P2, P3 );
}

/**
 * @brief Interfaces Face * iObj::getNFace( int N );
 * @param N (int) Face number
 * @return Face *
 */
Face * Layer::getNFace( int N ) { return Obj->getNFace( N ); }

/**
 * @brief Interfaces int iObj::getNumFaces( void ); returns the number of faces
 * of the object
 * @return int.
 */
int Layer::getObjNumFaces( void ) { return Obj->getNumFaces(); }

/**
 * @brief enables visibility in layer or not
 * @param b bool (visible?)
 */
void Layer::ToggleVisible( bool b ) { visible = b; }

/**
 * @brief changes visibility in layer
 */
void Layer::ToggleVisible( void ) { visible = ! visible; }

/**
 * @return (bool) if object is visible or not
 */
bool Layer::isVisible( void ) { return visible; }

/**
 * @brief Sets layer color
 * @param C QColor
 */
void Layer::setColor( QColor C ) { Color = C; }

/**
 * @brief returns Layer Color
 * @return QColor
 */
QColor Layer::getColor( void ) { return Color; }

/**
 * @brief Interfaces iObj::Escalation( double sx, double sy, douvle sz )
 */
void Layer::Escalation( double sx, double sy, double sz ) { Obj->Escalation( sx, sy, sz ); }

/**
 * @brief Interfaces iObj::Escalation( double tx, double ty, douvle tz )
 */
void Layer::Translation( double tx, double ty, double tz ){ Obj->Translation( tx, ty, tz ); }

/**
 * brief Interfaces iObj::RotationX( double ang )
 */
void Layer::RotationX( double ang ) { Obj->RotationX( ang ); }

/**
 * brief Interfaces iObj::RotationY( double ang )
 */
void Layer::RotationY( double ang ) { Obj->RotationY( ang ); }

/**
 * brief Interfaces iObj::RotationZ( double ang )
 */
void Layer::RotationZ( double ang ) { Obj->RotationZ( ang ); }

/**
 * brief Interfaces iObj::selfRotation( double ang )
 */
void Layer::selfRotation( double ang ) { Obj->selfRotation( ang ); }