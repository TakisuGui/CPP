#ifndef QUEUE_H
#define QUEUE_H

#include <bits/stdc++.h>
using namespace std;
typedef int Status;
#define OK 1
#define ERROR 0


template<class T>
class Queue
{
public:
    virtual bool isempty()=0;
    virtual int Length()=0;
    virtual Status Push(T e)=0;
    virtual Status Pop_front()=0;
    virtual void display()=0;
    virtual T Top()=0;
};


#endif 
