#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include "1_Queue.h"
using namespace std;
const int N=1e5+10;


template<class T>
class Node
{
    T data;
    Node<T>* next;
};


template<class T>
class Linked_Queue: public Queue<T>
{
public:
    Node<T>* front;
    Node<T>* rear;
public:
    Linked_Queue();
    ~Linked_Queue();
    bool isempty()=0;
    int Length()=0;
    Status Push(T e)=0;
    Status Pop_front()=0;
    T Top();
    void display()=0;
};


template<class T>
Linked_Queue<T>:: Linked_Queue()
{
    front=new Node<T>;
    front->next=NULL;
    rear=front;
}

template<class T>
Linked_Queue<T>:: ~Linked_Queue()
{
    Node<T>* p;
    while(front)
    {
        p=front;
        front=front->next;
        delete p;
    }
}

template<class T>
Status Linked_Queue<T>:: Push(T e)
{
   Node<T>* p=new Node<T>;
   p->data=e;
   rear->next=p;
   rear=p;
   return OK;
}

template<class T>
Status Linked_Queue<T>:: Pop_front()
{
    Node<T> *p;
    if(rear==front) return ERROR;
    p=front->next;
    front->next=p->next;
    if(rear==front) rear=front;
    delete p;
    return OK;
}

template<class T>
int Linked_Queue<T>:: Length()
{
    int cnt=0;
    Node<T>* p=front->next;
    while(p!=rear)
    {
        p=p->next;
        cnt++;
    }
    return cnt;
}

template<class T>
bool Linked_Queue<T>:: isempty()
{
    return rear==front;
}

template<class T>
T Linked_Queue<T>:: Top()
{
    return front->next->data;
}

template<class T>
void Linked_Queue<T>:: display()
{
    Node<T>* p=front->next;
    while(p!=rear)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<p->data<<" ";
    cout<<endl;
}

#endif 