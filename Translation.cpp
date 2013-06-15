//
//
//  @ Project : DgcApp
//  @ File Name : Translation.cpp
//  @ Date : 15/03/2012
//  @ Author : Leonardo Lanchas
//
//


#include "Translation.h"

Translation::Translation( double tx, double ty, double tz )
{
    this->tx = tx; this->ty = ty; this->tz = tz;
}

Translation::~Translation() { }

void Translation::Exec()
{
    
}

void Translation::SetLayer( Layer * L ) { this->L = L; }