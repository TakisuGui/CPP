#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include "1_Queue.h"
using namespace std;
const int N=1e5+10;


template<class T>
class Circular_Queue: public Queue<T>
{
public:
    T* base;
    int front;
    int rear;
    int queuesize;
public:
    Circular_Queue();
    ~Circular_Queue();
    bool isempty();
    int Length();
    Status Push(T e);
    Status Pop_front();
    T Top();
    void display();
};


template<class T>
Circular_Queue<T>:: Circular_Queue()
{
    base=new T[N];
    front=rear=0;
    queuesize=N;
}

template<class T>
Circular_Queue<T>:: ~Circular_Queue()
{
    delete[] base;
}

template<class T>
Status Circular_Queue<T>:: Push(T e)
{
   if((rear+1)%N==front) return ERROR;
   base[rear]=e;
   rear=(rear+1)%N;
   return OK;
}

template<class T>
Status Circular_Queue<T>:: Pop_front()
{
    if(rear==front) return ERROR;
    front=(front+1)%N;
    return OK;
}

template<class T>
int Circular_Queue<T>:: Length()
{
    return (rear-front+N)%N;
}

template<class T>
bool Circular_Queue<T>:: isempty()
{
    return rear==front;
}

template<class T>
T Circular_Queue<T>:: Top()
{
    return base[front];
}

template<class T>
void Circular_Queue<T>:: display()
{
    if(rear>=front)
    {
        for(int i=front;i<rear;i++) cout<<base[i]<<" ";
        cout<<endl;
    }
    else
    {
        for(int i=front;i<rear+N;i++) cout<<base[i%N]<<" ";\
        cout<<endl;
    }
}

#endif 