//
//
//  @ Project : DgcApp
//  @ File Name : Rotation.h
//  @ Date : 15/03/2012
//  @ Author : Leonardo Lanchas
//
//


#if !defined(_ROTATION_H)
#define _ROTATION_H

#include "iCmd.h"
#include "Layer.h"

class Rotation : public iCmd
{
public:
    Rotation();
    ~Rotation();
    void Exec();
    void SetLayer( Layer * L );
    
private:
    Layer * L;
};

#endif  //_ROTATION_H
