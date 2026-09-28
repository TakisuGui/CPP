#include<bits/stdc++.h>
#include "1_List.h" 
using namespace std;


template<class T>
class DulNode
{
    T data;
    DulNode<T>* prior;
    DulNode<T>* next;
};


template<class T>
class DulLinkeddList: List<T>
{
private:
    DulNOde<T>* head;
public:
    DulLinkeddList();
    ~DulLinkeddList();
    bool isempty();
    T getelem(int i);
    int locateelem(T e);
    int Length();
    Status Insert(int i,T e);
    Status Delete(int i,T& e);
    Status Insert(T e);
};


template<class T>
Status DulLinkeddList<T>:: Insert(int i,T e)
{
    DulNode<T>* p,* s;
    p=head;
    int j=0;
    while(p&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(!p||j>i-1) return Error;
    s=new DulNode<T>;
    s->data=e;
    s->next=p->next;
    if(p->next) p->next->prior=s;
    p->next=s;
    s->prior=p;
    return OK;
};

template<class T>
Status DulLinkeddList<T>:: Delete(int i,T& e)
{
    DulNode<T>* p,* q;
    p=head;
    int j=0;
    while(p&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(!p||j>i-1) return Error;
    q=p->next;
    p->next=q->next;
    q->next->prior=p;
    e=q->data;
    delete q;
    return OK;
};