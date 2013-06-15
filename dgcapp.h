/* 
 * File:   dgcapp.h
 * Author: Leo
 *
 * Created on 8 de marzo de 2012, 12:11
 */

#ifndef _DGCAPP_H
#define	_DGCAPP_H

#include <QDialog>
#include <QColorDialog>

#include "ui_dgcUi.h"
#include "iObj.h"
#include "Canvas.h"
#include "Layer.h"

#include <map>
#include <vector>
using namespace std;

class Layer;
class iObj;

class dgcapp : public QDialog
{
    Q_OBJECT
    
public:
    dgcapp();
    virtual ~dgcapp();
    
    iObj * CreateObj( int );
    void RegisterObj( iObj * );
    
public slots:
    Canvas * getCanvas( int );
    int getCurrentTransform( void );
    int getCurrentLayer( void );
    int getCurrentShading( void );
    bool isBorderSelected( void );
    void Draw( void );
    
    void erase ( void );
    void deleteLayer( int );
    
    void resetRev( void );
    int getRevNumP( void );
    float getRevIX( int );
    float getRevIY( int );
    void setRevPoint( float, float, float, float );
    void revEraseLine( void );
    
    int getIntensity( void );
    int getLightX( void );
    int getLightY( void );
    int getLightZ( void );
    
    int getNMerid( void );
    
    QColor getRefColor( void );
    
private slots:
    void ToggleLayer( QListWidgetItem * item );
    void SetColor( void );
    void SetRefColor( void );
    
private:
    Canvas * LAir, * LPersp, * LFront, * LLat;
    Ui::DgcUi widget;
    
    map < int, iObj * > regObj;  // registered Objects
    vector < Layer * > ScreenLayers; // Objects in Canvas
    
    struct rev drawing; // revolution object
    
    QColor C; // Reflection Color
};

#endif	/* _DGCAPP_H */