//
//
//  @ Project : DgcApp
//  @ File Name : Subject.h
//  @ Date : 15/03/2012
//  @ Author : Leonardo Lanchas
//
//


#if !defined(_SUBJECT_H)
#define _SUBJECT_H

#include "Observer.h"

#include <map>
using namespace std;

class Subject
{
public:
    Subject();
    ~Subject();
    
    void Adscribe( Observer * );
    void Notify();
    void Remove( Observer * );
    
private:
    map < int, Observer * > ls;
};

#endif  //_SUBJECT_H
