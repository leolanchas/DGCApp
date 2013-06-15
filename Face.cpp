#include "Face.h"
#include <cmath>
using namespace std;

/**
 * @brief Creates a new Face. Its normal and its indexes are 0
 */
Face::Face()
{
    P1->h = P2->h = P3->h = 1.;
    P1->x = P1->y = P1->z = P2->x = P2->y = P2->z = P3->x = P3->y = P3->z = 0.;
    D = 0.;
    i = j = k = 0;
    N.x = N.y = N.z = 0.;
}

/**
 * @brief Creates a new Face. Its normal is calculated. Its index is 0
 * @param P first point (punto3d -> struct { float x, y, z })
 * @param Q second point (punto3d -> struct { float x, y, z })
 * @param R third point (punto3d -> struct { float x, y, z })
 */
Face::Face( punto3d * P, punto3d * Q, punto3d * R )
{
    D = 0.;
    i = j = k = 0;
    N.x = N.y = N.z = 0.;
    SetPoint( P, Q, R );
    ComputeNormal();
}

/**
 * @brief Creates a new Face. Its normal is calculated.
 * @param P first point (punto3d -> struct { float x, y, z })
 * @param Q second point (punto3d -> struct { float x, y, z })
 * @param R third point (punto3d -> struct { float x, y, z })
 * @param i x index
 * @param j y index
 * @param k z index
 */
Face::Face( punto3d * P, punto3d * Q, punto3d * R, int i, int j, int k )
{
    D = 0.;
    i = j = k = 0;
    N.x = N.y = N.z = 0.;
    SetPoint( P, Q, R );
    SetIndex( i, j, k );
    ComputeNormal();
}

/**
 * @brief Copy constructor
 * @param F Face &
 */
Face::Face( const Face& F )
{
    P1->x = F.P1->x; P1->y = F.P1->y; P1->z = F.P1->z; P1->h = F.P1->h;
    P2->x = F.P2->x; P2->y = F.P2->y; P2->z = F.P2->z; P2->h = F.P2->h;
    P3->x = F.P3->x; P3->y = F.P3->y; P3->z = F.P3->z; P3->h = F.P3->h;
    
    i = F.i; j = F.j; k = F.k;
    D = F.D;
    N.x = F.N.x; N.y = F.N.y; N.z = F.N.z;
}

Face::~Face() { }

/**
 * @brief Assign face points.
 * @param P first punto3d
 * @param Q seconf punto3d
 * @param R third punto3d
 */
void Face::SetPoint( punto3d * P, punto3d * Q, punto3d * R )
{
    P1 = P; P2 = Q; P3 = R;
}

/**
 * @brief initialize indexes
 * @param i x
 * @param j y
 * @param k z
 */
void Face::SetIndex( int i, int j, int k ) 
{
    this->i = i; this->j = j; this->k = k;
}

/**
 * @brief Returns (pointers as parameters) the value of a given face points
 * @param A pointer to the first point
 * @param B pointer to the second point
 * @param C pointer to the third point
 */
void Face::Points( punto3d * A, punto3d * B, punto3d * C )
{
    A->x = P1->x; A->y = P1->y; A->z = P1->z; A->h = P1->h;
    B->x = P2->x; B->y = P2->y; B->z = P2->z; B->h = P2->h;
    C->x = P3->x; C->y = P3->y; C->z = P3->z; C->h = P3->h;
}

/**
 * @brief returns D (plane equation).
 * @return (float)
 */
float Face::getD( void ) { return D; }

/**
 * @brief returns Face normal
 * @return  Struct Normal (struct Normal { float x, y, z; })
 */
Normal Face::getNormal() { return N; }

/**
 * @brief computes Face normal (Every time it is updated)
 */
void Face::ComputeNormal()
{
    float x1, y1, z1, x2, y2, z2, x3, y3, z3, PvecYZ, PvecXZ, PvecXY;
    float P1x, P1y, P1z, P2x, P2y, P2z;
    
    // Faces' vertices
    x1 = this->P1->x; x2 = this->P2->x; x3 = this->P3->x;
    y1 = this->P1->y; y2 = this->P2->y; y3 = this->P3->y;
    z1 = this->P1->z; z2 = this->P2->z; z3 = this->P3->z;

    // Face's Plane Vectors
    P1x = x2 - x1; P1y = y2 - y1; P1z = z2 - z1;
    P2x = x3 - x1; P2y = y3 - y1; P2z = z3 - z1;
    
    // Vector Product
    //
    // |i       j       k |
    // |x1      y1      z1|
    // |x2      y2      z2|

    PvecYZ = ( P1y * P2z ) - ( P2y * P1z );
    PvecXZ = ( P1z * P2x ) - ( P2z * P1x );
    PvecXY = ( P1x * P2y ) - ( P2x * P1y );

    // Compute module
    double mod = sqrt( PvecYZ * PvecYZ + PvecXZ * PvecXZ + PvecXY * PvecXY );
    PvecYZ /= mod; PvecXZ /= mod; PvecXY /= mod;

    // Normal
    this->N.x = PvecYZ; this->N.y = PvecXZ; this->N.z = PvecXY;

    // D term
    this->D = - ( PvecYZ * x1 ) - ( PvecXZ * y1 ) - ( PvecXY * z1 );
}