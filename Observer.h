//
//
//  @ Project : DgcApp
//  @ File Name : Observer.h
//  @ Date : 15/03/2012
//  @ Author : Leonardo Lanchas
//
//


#if !defined(_OBSERVER_H)
#define _OBSERVER_H


class Observer
{
public:
    virtual void Update() = 0;
    virtual ~Observer() { };
};

#endif  //_OBSERVER_H
