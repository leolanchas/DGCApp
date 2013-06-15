//
//
//  @ Project : DgcApp
//  @ File Name : Escalation.h
//  @ Date : 15/03/2012
//  @ Author : Leonardo Lanchas
//
//


#if !defined(_ESCALATION_H)
#define _ESCALATION_H

#include "iCmd.h"
#include "Layer.h"

class Escalation : public iCmd
{
public:
    Escalation();
    ~Escalation();
    void Exec();
    void SetLayer( Layer * L );
    
private:
    Layer * L;
};

#endif  //_ESCALATION_H
