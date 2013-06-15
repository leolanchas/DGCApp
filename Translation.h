//
//
//  @ Project : DgcApp
//  @ File Name : Translation.h
//  @ Date : 15/03/2012
//  @ Author : Leonardo Lanchas
//
//


#if !defined(_TRANSLATION_H)
#define _TRANSLATION_H

#include "iCmd.h"
#include "Layer.h"

class Translation : public iCmd
{
public:
    Translation( double, double, double );
    ~Translation();
    
    void Exec();
    void SetLayer( Layer * L );
    
private:
    Layer * L;
    
    double tx, ty, tz;
};

#endif  //_TRANSLATION_H
