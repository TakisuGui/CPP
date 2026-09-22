#ifndef STACK_H
#define STACK_H

#include <bits/stdc++.h>
using namespace std;
typedef int Status;
#define OK 1
#define ERROR 0

template<class T>
class Stack
{
public:
    virtual bool isempty()=0;
    virtual int Length()=0;
    virtual  T Top()=0;
    virtual bool Pop()=0;
    virtual bool Push(T e)=0;
    virtual void display()=0;
};

#endif 