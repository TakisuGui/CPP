#ifndef LISTCPP_LIST_H
#define LISTCPP_LIST_H

#include<bits/stdc++.h>
using namespace std;
typedef int Status;
#define OK 1
#define ERROR 0

template<class T>
class List
{
public:
    virtual bool isempty()=0;
    virtual T getelem(int i)=0;
    virtual int locateelem(T e)=0;
    virtual int Length()=0;
    virtual Status Insert(int i,T e)=0;
    virtual Status Delete(int i,T& e)=0;
    virtual Status Insert(T e)=0;
};

#endif 