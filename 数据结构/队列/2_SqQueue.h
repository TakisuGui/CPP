#ifndef SQ_QUEUE_H
#define SQ_QUEUE_H

#include "1_Queue.h"
using namespace std;
const int N=1e5+10;


template<class T>
class SqQueue: public Queue<T>
{
public:
    T* base;
    int front;
    int rear;
    int queuesize;
public:
    SqQueue();
    ~SqQueue();
    bool isempty();
    int Length();
    Status Push(T e);
    Status Pop_front();
    T Top();
    void display();
};


template<class T>
SqQueue<T>:: SqQueue()
{
    base=new T[N];
    front=rear=0;
    queuesize=N;
}

template<class T>
SqQueue<T>:: ~SqQueue()
{
    delete[] base;
}

template<class T>
Status SqQueue<T>:: Push(T e)
{
   if(rear>=queuesize) return ERROR;
   base[rear++]=e;
   return OK;
}

template<class T>
Status SqQueue<T>:: Pop_front()
{
    if(rear==front) return ERROR;
    front++;
    return OK;
}

template<class T>
int SqQueue<T>:: Length()
{
    return rear-front;
}

template<class T>
bool SqQueue<T>:: isempty()
{
    return rear==front;
}

template<class T>
T SqQueue<T>:: Top()
{
    return base[front];
}

template<class T>
void SqQueue<T>:: display()
{
    for(int i=front;i<rear;i++) cout<<base[i]<<"  ";
    cout<<endl;
}

#endif 