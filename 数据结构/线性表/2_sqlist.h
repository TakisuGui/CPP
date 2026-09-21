#ifndef SQLIST_H
#define SQLIST_H


#include<bits/stdc++.h>
#include "1_List.h" 
using namespace std;
const int N=1e3+10;


template<class T>
class Sqlist: public List<T>
{
public:
    T* elem;
    int length;
    int listsize; // 可以容纳最大元素个数
public:
    Sqlist();
    ~Sqlist();

    bool isempty();
    T getelem(int i);
    int locateelem(T e);
    int Length();
    bool Insert(int i,T e);
    bool Delete(int i,T& e);
    void Union(Sqlist<T>& lb);
    bool Push_back(T e);
    Status Reverse();

    void Inputlist();
    void Outputlist();
};

// 1. 初始化和销毁
template<class T>
Sqlist<T>:: Sqlist()
{
    elem=new T[N];
    length=0;
    listsize=N;
}
template<class T>
Sqlist<T>:: ~Sqlist()
{
    delete[] elem;
};


// 2. 插入元素
template<class T>
bool Sqlist<T>:: Insert(int i,T e)
{
    T* p;
    if(i<1||i>length+1) return false;

    if(length>=listsize)
    {
        T* newbase=new T[listsize+N];
        if(!newbase) return false;
        p=elem; elem=newbase;

        for(int i=0;i<length;i++) elem[i]=p[i];
        listsize+=N;
    }

    T* q=&(elem[i-1]);
    for(int p=&elem[length-1];p>=q;p--) *(p+1)=*p;
    *q=e;
    length++;
    return true;
}


// 3. 删除元素
template<class T>
bool Sqlist<T>:: Delete(int i,T& e)
{
    T* p; T* q;
    if(i<1||i>length) return false;

    p=&elem[i-1];
    e=*p;
    for(T* i=p;i<elem+length-1;i++) *i=*(i+1);
    length--;
    return true;
}


// 4. 合并
template<class T>
void Sqlist<T>:: Union(Sqlist<T>& lb)
{
    int lb_len=lb.length;
    int e;

    for(int i=1;i<=lb_len;i++)
    {
        e=lb.getelem(i);
        if(this->locateelem(e)==0) this->Insert(e);
    }
}


// 5. 归并
template<class T>
void Merge(Sqlist<T> la,Sqlist<T> lb,Sqlist<T>& lc)
{
    int i=1,j=1,k=0;
    int la_len=la.length,lb_len=lb.length;
    int ai,bj;

    while((i<=la_len)&&(j<=lb_len))
    {
        ai=la.getelem(i);
        bj=lb.getelem(j);

        if(ai<=bj) lc.Insert(++k,ai),i++;
        else lc.Insert(++k,bj),j++;
    }

    while(i<=la_len)
    {
        ai=la.getelem(i);
        lc.Insert(++k,ai);
        i++;
    }
    while(j<=lb_len)
    {
        bj=lb.getelem(j);
        lc.Insert(++k,bj);
        j++;
    }
}


// 6. 空
template<class T>
bool Sqlist<T>:: isempty()
{
    return length==0;
}


// 7. 获取指定位置元素
template<class T>
T Sqlist<T>:: getelem(int i)
{
    return elem[i-1];
}


// 8. 获取指定值的下标
template<class T>
int Sqlist<T>:: locateelem(T e)
{
    int i;
    for(i=length;i>0;i--)
    {
        if(elem[i-1]==e) break;
    }
    return i;
}


// 9. 长度
template<class T>
int Sqlist<T>:: Length(){
    return length;
}


// 10. 尾插
template<class T>
bool Sqlist<T>:: Push_back(T e)
{
    T *p;
    if(length>=listsize)
    {
        T* newbase=new T[ListSize+ListIncrease];
        if(!newbase) return false;
        p=elem;
        elem=newbase;
        for(int i=0;i<length;i++) elem[i]=p[i];
        listsize+=ListIncrease;
    }

    elem[length]=e;
    length++;
    return OK;
}


// 11. 输入
template<class T>
void Sqlist<T>:: Inputlist()
{
    int i,n; T key;
    cin>>n;
    for(i = 0;i<n;i++)
    {
        cin>>key;
        Insert(key);
    }
}


// 12. 输出
template<class T>
void Sqlist<T>:: Outputlist()
{
    int i;
    for (i=0;i<length;i++)  cout<<elem[i]<<"->";
    cout<<endl;
}

#endif