//
//
//  @ Project : DgcApp
//  @ File Name : RevObj.cpp
//  @ Date : 15/03/2012
//  @ Author : Leonardo Lanchas
//
//


#include "RevObj.h"
#include "Sup_Revolucion.h"

/**
 * @brief Default simple rev object
 * @param NM (int) number of meridians
 */
RevObj::RevObj( int NM )
{
    struct rev drawing; drawing.num_p = 0;

    drawing.lista_P[ drawing.num_p ].x = 111;
    drawing.lista_P[ drawing.num_p ].y = 80;
    drawing.lista_P[ drawing.num_p ].z = 0;
    drawing.num_p++;
    
    drawing.lista_P[ drawing.num_p ].x = 122;
    drawing.lista_P[ drawing.num_p ].y = 100;
    drawing.lista_P[ drawing.num_p ].z = 0;
    drawing.num_p++;
    
    drawing.lista_P[ drawing.num_p ].x = 145;
    drawing.lista_P[ drawing.num_p ].y = 115;
    drawing.lista_P[ drawing.num_p ].z = 0;
    drawing.num_p++;
    
    drawing.lista_P[ drawing.num_p ].x = 122;
    drawing.lista_P[ drawing.num_p ].y = 130;
    drawing.lista_P[ drawing.num_p ].z = 0;
    drawing.num_p++;
    
    drawing.lista_P[ drawing.num_p ].x = 111;
    drawing.lista_P[ drawing.num_p ].y = 190;
    drawing.lista_P[ drawing.num_p ].z = 0;
    drawing.num_p++;

    init( & drawing, NM ); // compute its parameters
}

/**
 * @brief creates a rev object from user defined border
 * @param R border punto3d list (punto3d array)
 * @param NM (int) number of meridians
 */
RevObj::RevObj( struct rev * R, int NM ) { init( R, NM ); }

/**
 * @brief computes object params and creates its faces and edges
 * @param R struct rev *
 * @param numrev (int) number of revolutions
 */
void RevObj::init( struct rev * R, int numrev )
{
    char error = '-';
    struct punto3d aux, aux1, * res = NULL;
    
    // rotate on Y axis
    aux.x  = 0; aux.y  = 0; aux.z  = 0;
    aux1.x = 0; aux1.y = 1; aux1.z = 0;
    
    res = Sup_Revolucion( R->num_p, R->lista_P, numrev, & aux, & aux1, error );

    int puntosrot = numrev * R->num_p; // total vertices
    
    if ( res )
    {
        Points = R->num_p;
    
        for ( int i = 0; i < Points; i++ )
        {
            punto3d * p = new punto3d;

            p->x = R->lista_P[ i ].x; p->y = R->lista_P[ i ].y;
            p->z = R->lista_P[ i ].z; p->h = 1;

            Meridians.push_back( p );
            Vertices.push_back( p );
        }

        NMerid    = numrev;
        NVertices = Points;
        NEdges    = 0;
        Name      = "Rev";
        
        for ( int i = 0; i < puntosrot; i++ )
            if ( i > R->num_p - 1 ) { res[ i ].h = 1; addVertex( & res[ i ] ); }

        createEdges();        
        createFaces();
        
        //free( res );
    }
}

/**
 * @brief Copy Constructor
 * @param R RevObject &
 */
RevObj::RevObj( const RevObj & R )
{
    
    for ( int i = 0; i < R.NVertices; i++ )
    {
        punto3d * p = new punto3d;
        p->x = R.Vertices[ i ]->x; p->y = R.Vertices[ i ]->y;
        p->z = R.Vertices[ i ]->z; p->h = R.Vertices[ i ]->h;
        Vertices.push_back( p );
    }
    
    //Faces = R.Faces; Vertices = R.Vertices; Edges = R.Edges;
        
    NFaces    = R.NFaces;
    NEdges    = R.NEdges;
    NVertices = R.NVertices;
    
    Meridians = R.Meridians;
    NMerid    = R.NMerid;
    Points    = R.Points;
    Name      = R.Name;
    
    createEdges();
    createFaces();
}

RevObj::~RevObj() { }

/**
 * @brief Creates vertices and computes its normal
 */
void RevObj::createFaces()
{
    NFaces = 0;
    int vertact = 0;
    
    for( int i = 0; i < NMerid; i++ )
    {
        for ( int j = 0; j < Points - 1; j++ )
        {
            int delta = 0;
            if ( i < NMerid - 1 ) delta = vertact + Points;
            
            Face * F1 = new Face( Vertices[ vertact + j ], 
                                  Vertices[ delta + 1 + j ], 
                                  Vertices[ delta + j ],
                    /* indexes */
                                  vertact + j, delta + 1 + j, delta + j );
            
            Face * F2 = new Face( Vertices[ vertact + j ], 
                                  Vertices[ vertact + 1 + j ], 
                                  Vertices[ delta + 1 + j ],
                    /* indexes */
                                  vertact + j, vertact + 1 + j, delta + 1 + j );

            /* F1 & F2 */
            Faces.push_back( F1 );
            Faces.push_back( F2 );
        }
        vertact = vertact + Points;
    }
    NFaces = Faces.size();
}

/**
 * Joins vertices 
 */
void RevObj::createEdges()
{
    int point = 0, delta = 0;
    
    for (int i = 0; i < NMerid; i++ )
    {
        for (int j = 0; j < Points; j++ )
        {
            if ( i < NMerid - 1 ) delta = point + Points; else delta = j;
            
            if ( j < Points - 1 ) // create triangular faces
            {
                Edges.push_back( new Edge( Vertices[ point ], Vertices[ point + 1 ] ) );
                Edges.push_back( new Edge( Vertices[ point ], Vertices[ delta ] ) );
                Edges.push_back( new Edge( Vertices[ point ], Vertices[ delta + 1 ] ) );
                NEdges += 3;
            }
            else // join with the first one
            {
                Edges.push_back( new Edge( Vertices[ point ], Vertices[ delta ] ) );
                NEdges++;
            }
            point++;
        }
    }
}

/**
 * @brief Clones default revolution object
 * @return new default Rev Object
 */
iObj * RevObj::Clone() { return new RevObj( * this ); }