#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include<bits/stdc++.h>
#include "1_List.h" 
using namespace std;


template<class T>
class Node
{
public:
    T data;
    Node<T>* next;
};

template<class T>
class linkedlist: public List<T>
{
public:
    Node<T>* head;
public:
    linkedlist();
    ~linkedlist();

    bool isempty();
    T getelem(int i);
    int locateelem(T e);
    int Length();
    virtual Status Insert(int i,T e);
    virtual Status Delete(int i,T& e);
    virtual Status Insert(T e);

    bool Inputlist();
    bool Inputlist_R();
    bool Reverse();
    void Union(linkedlist<T>& lb);
};


// 1. 初始化和销毁
template<class T>
linkedlist<T>:: linkedlist()
{
    head=new Node<T>;
    head->next=nullptr;
}

template<class T>
linkedlist<T>:: ~linkedlist()
{
    Node<T>* p;
    while(head!=nullptr)
    {
        p=head;
        head=head->next;
        delete p;
    }
}


// 2. 获取单链表中指定元素位置
template<class T>
T linkedlist<T>:: getelem(int i)
{
    T e;
    Node<T> *p;
    p=head->next;
    int j=1;
    while(p&&j<i)
    {
        p=p->next; j++;
    }

    if(!p||j>i) return e;
    return p->data;
};


// 3. 插入元素
template<class T>
Status linkedlist<T>:: Insert(int i, T e)
{
    Node<T>* p; Node<T>* s;
    p=head;
    int j=0;
    while(p&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(!p||j>i-1) return false;

    s=new Node<T>;
    s->data=e; s->next=p->next;
    p->next=s;
    return true;
}


// 4. 删除元素
template<class T>
Status linkedlist<T>:: Delete(int i, T& e)
{
    Node<T>* p; Node<T>* q;
    p=head;
    int j=0;
    while(p&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(!p||j>i-1) return false;

    q=p->next;
    p->next=q->next;
    e=q->data;
    delete q;
    return true;
}

// 5.1 逆序建表(头插)
template<class T>
bool linkedlist<T>:: Inputlist_R()
{
    Node<T>* p;
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        p=new Node<T>;
        if(!p) return false;
        cin>>p->data;
        p->next=head->next;
        head->next=p;
    }
    return true;
};

// 5.2 正序建表(尾插)
template<class T>
bool linkedlist<T>:: Inputlist()
{
    Node<T> *p; Node<T>* last;
    last=head;
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        p=new Node<T>;
        cin>>p->data;
        (*last).next=p;
        last=p;
    }
    (*last).next=nullptr;
    return true;
}


// 6. 合并
template<class T>
void linkedlist<T>:: Union(linkedlist<T>& lb)
{
    int lb_len=lb.Length();
    T e;

    for(int i=1;i<=lb_len;i++)
    {
        e=lb.getelem(i);
        if(this->locateelem(e)==0) this->Insert(e);
    }
}


// 7. 定位
template<class T>
int linkedlist<T>:: locateelem(T key)
{
    Node<T> *p; int i=1;
    p=head->next;
    while(p&&!(p->data==key))
    {
        p=p->next; i++;
    }
    if (!p) return -1;
    return i;
}


// 8. 反转
template<class T>
bool linkedlist<T>:: Reverse()
{
    Node<T> *p; Node<T>* q; Node<T> *r;
    p=head->next;
    if(p==NULL) return false;
    q=p->next;
    if(q==NULL) return false;
    r=q->next;

    while(r!=NULL)
    {
        (*q).next=p;
        p=q;
        q=r;
        r=q->next;
    }
    (*q).next=p;
    (*(head->next)).next=NULL;
    head->next=q;
    return true;
}


// 9. 长度
template<class T>
int linkedlist<T>:: Length()
{
    Node<T> *p;
    int i=0;
    p=head->next;
    while(p)
    {  
        p=p->next; i++;
    }
    return i;
}


// 10. 空
template<class T>
bool linkedlist<T>:: isempty()
{
    if(head->next) return false;
    else return true;
}


// 11. 尾插
template<class T>
Status linkedlist<T>::Insert(T e)
{
    Node<T>* last=head;
    while (last->next) last=last->next;
    Node<T>* s=new Node<T>();
    s->data=e;
    s->next=nullptr;
    last->next=s;
    return OK;
}


#endif