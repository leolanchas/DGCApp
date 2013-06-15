//
//
//  @ Project : DgcApp
//  @ File Name : Subject.cpp
//  @ Date : 15/03/2012
//  @ Author : Leonardo Lanchas
//
//


#include "Subject.h"

Subject::Subject() { }

/**
 * @brief deletes all observers by calling their destructors
 */
Subject::~Subject()
{
    map < int, Observer * >::iterator it = ls.begin();
    for ( ; it != ls.end(); it++ ) it->second->~Observer();
}

/**
 * @brief add observer to the list in order to notify them the changes
 * @param O Observer * (Observer.h)
 */
void Subject::Adscribe( Observer * O ) { ls[ ( int ) O ] = O; }

/**
 * @brief call Canvas::Update()
 */
void Subject::Notify()
{
    map < int, Observer * >::iterator it = ls.begin();
    for ( ; it != ls.end(); it++ ) it->second->Update();
}

/**
 * delete Observer O
 * @param O Observer *
 */
void Subject::Remove( Observer * O )
{
    delete ls[ ( int ) O ];
    ls[ ( int ) O ] = NULL;
    ls.erase( ( int ) O );
}