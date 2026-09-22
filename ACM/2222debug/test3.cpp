#include<bits/stdc++.h>
using namespace std;
typedef int Status;
#define OK 1
#define ERROR 0

template<class T>
class Node
{
public:
    T data;
    Node<T>* next;
};


template<class T>
class List
{
public:
    virtual Status Insert(T e)=0;
    virtual void Delete(Node<T>* i)=0;
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
    virtual void Delete(Node<T>* i);
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
void linkedlist<T>:: Delete(Node<T>* i)
{
    Node<T>* p,* q;
    p=head;
    while(p&&p->next!=i)
    {
        p=p->next;
    }
    if(p==nullptr) return;

    q=p->next;
    p->next=q->next;
    delete q;
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
    
    Node<int>* p=lis.head->next;
    int k; cin>>k;
    while(p)
    {
        Node<int>* nex=p->next;
        if(p->data==k) lis.Delete(p);
        p=nex;
    }
    

    p=lis.head->next;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}