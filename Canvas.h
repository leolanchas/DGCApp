#ifndef Canvas_H
#define Canvas_H

#include <QtGui/QWidget>
#include <QtGui/QLabel>
#include <QPainter>
#include <QColor>

#include "Layer.h"
#include "Face.h"

#define Air   1
#define Persp 2
#define Front 3
#define Lat   4

class Canvas : public QWidget, public Observer
{
    Q_OBJECT  

public:
    Canvas( QWidget * parent = 0 );
    ~Canvas();
    
    void SetLabel( QLabel * );
    
    void SetInitialCoords( int, int );
    void SetFinalCoords( int, int );
    void UpdateCoords( int, int );
    
    void SetSubject( vector < Layer * > * S );
    
public slots:
    void ToggleAxis( void );
    void Update();

protected:
    void paintEvent( QPaintEvent * );
    void mouseMoveEvent( QMouseEvent * );
    void mousePressEvent( QMouseEvent * );
    void mouseReleaseEvent( QMouseEvent * );

private:
    void ZBuffer( QPainter * );
    void fill( QPainter *, float **, float, float, float, float, float, float,
               Face *, QColor, bool, punto3d *, int );
    
    QColor lightColor ( float, float, float, Normal, QColor, punto3d *, int );
    float Difuse ( Normal, float, float, float, punto3d *, int );
    
    struct Coords
    {
        float x, y;
        bool operator < ( const Coords & c ) const { return c.y < y; }
    };
    
    int x, y, j, k;
    
    QLabel * L;
    QString LabelText;
    
    bool axis, pressed;
    vector < Layer * > * Lay;
    vector < vector < Edge * > * > Edges;
    vector < QColor > C;
};

#endif