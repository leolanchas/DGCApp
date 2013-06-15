//
//
//  @ Project : DgcApp
//  @ File Name : iCmd.h
//  @ Date : 15/03/2012
//  @ Author : Leonardo Lanchas
//
//


#if !defined(_ICMD_H)
#define _ICMD_H

#include "Layer.h"

class iCmd
{
public:
    virtual void Exec() = 0;
    virtual void SetLayer( Layer * L ) = 0;
    virtual ~iCmd() { } ;
};

#endif  //_ICMD_H