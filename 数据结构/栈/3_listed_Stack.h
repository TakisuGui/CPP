#ifndef LISTED_STACK_H
#define LISTED_STACK_H

#include <bits/stdc++.h>
#include "1_Stack.h"
using namespace std;
const int N=1e5+10;

template<class T>
class Node
{
public:
    T data;
    Node<T>* next;
};


template<class T>
class LinkedStack
{
public:
    Node<T>* top; // top->next 才是真正的栈顶
public:
    LinkedStack();
    ~LinkedStack();
    bool isempty();
    int Length();
    T Top();
    bool Pop();
    bool Push(T e);
    void display();
};

template<class T>
LinkedStack<T>:: LinkedStack()
{
   top=new Node<T>;
   top->next=NULL;
}

template<class T>
LinkedStack<T>:: ~LinkedStack()
{
    Node<T>* p;
    while(top)
    {
        p=top;
        top=top->next;
        delete p;
    }
}

template<class T>
bool LinkedStack<T>:: Push(T e)
{
    Node<T>* p=new Node<T>;
    if(!p) return false;
    p->data=e;
    p->next=top->next;
    top->next=p;
    return true;
}

template<class T>
bool LinkedStack<T>:: Pop()
{
    Node<T>* p;
    if(top->next==NULL) return false;
    p=top->next;
    top->next=p->next;
    delete p;
    return true;
}

template<class T>
T LinkedStack<T>:: Top()
{
    return top->next->data;
}

template<class T>
int LinkedStack<T>:: Length()
{
    Node<T>* p=top->next;
    int i=0;
    while(p)
    {
        i++;
        p=p->next;
    }
    return i;
}

template<class T>
bool LinkedStack<T>:: isempty()
{
    return top->next==NULL;
}

template<class T>
void LinkedStack<T>:: display()
{
    Node<T>* p=top->next;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

#endif 