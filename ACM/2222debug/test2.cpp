#include<bits/stdc++.h>
using namespace std;
typedef int Status;
#define OK 1
#define ERROR 0

template<class T>
class List
{
public:
    virtual Status Insert(T e)=0;
};


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
    
    virtual Status Insert(T e);
   
    void Reverse();

};

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

template<class T>
void linkedlist<T>:: Reverse()
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
}


int main()
{
    int n; cin>>n;
    linkedlist<int> lis;
    for(int i=1;i<=n;i++) 
    {
        int x; cin>>x;
        lis.Insert(x);
    }
    
    lis.Reverse();
    
    Node<int>* p=lis.head->next;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
    return 0;
}