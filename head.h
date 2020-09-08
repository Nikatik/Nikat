#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#define n 8

using namespace std;

class my
{
    int x[n];
    public:
    my();
    my operator+(const my &);
    my operator*(int);
    friend my operator*(int,const my &);
    friend void print(const my&);
};


#endif // HEAD_H_INCLUDED
