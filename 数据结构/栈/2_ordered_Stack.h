#ifndef ORDERED_STACK_H
#define ORDERED_STACK_H

#include <bits/stdc++.h>
#include "1_Stack.h"
using namespace std;
const int N=1e5+10;


template<class T>
class SqStack:public Stack<T>
{
    T* base; // 栈底指针 指向栈的起始位置
    T* top;
    int stacksize;
public:
    SqStack();
    ~SqStack();
    bool isempty();
    int Length();
    T Top();
    bool Pop();
    bool Push(T e);
    void display();
};

template<class T>
SqStack<T>:: SqStack()
{
    base=new T[N];
    top=base;
    stacksize=N;
}

template<class T>
SqStack<T>:: ~SqStack()
{
    delete []base;
}

template<class T>
bool SqStack<T>:: Push(T e)
{
    if(top-base>=stacksize) return false;
    *top=e;
    top++;
    return true;
}

template<class T>
bool SqStack<T>:: Pop()
{
    if(top==base) return false;
    top--;
    return true;
}

template<class T>
T SqStack<T>:: Top()
{
    return *(top-1);
}

template<class T>
int SqStack<T>:: Length()
{
    return (top-base);
}

template<class T>
bool SqStack<T>:: isempty()
{
    return (top==base);
}

template<class T>
void SqStack<T>:: display()
{
    int n=this->Length();
    for(int i=n;i>0;i--) cout<<*(base+i-1)<<" ";
    cout<<endl;
}

#endif 