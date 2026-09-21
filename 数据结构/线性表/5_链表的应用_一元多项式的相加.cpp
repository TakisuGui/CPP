#include<bits/stdc++.h>
#include "4_linkedlist.h"
using namespace std;


template<class T>
class sortedlinkedlist: public linkedlist<T>
{
public: 
    sortedlinkedlist()=default;
    ~sortedlinkedlist()=default;

    Status Insert(T e);

    virtual void Merge(sortedlinkedlist<T>& la,sortedlinkedlist<T>& lb);
};

template<class T>
Status sortedlinkedlist<T>:: Insert(T e)
{
    Node<T>* p,* s,* pre;
    pre=this->head;
    p=pre->next;
    if(p)
    {
        while(p&&p->data<e)
        {
            pre=p;
            p=p->next;
        }
    }

    s=new Node<T>;
    s->data=e;
    s->next=p;
    pre->next=s;
    return OK;
}

template<class T>
void sortedlinkedlist<T>:: Merge(sortedlinkedlist<T>& la,sortedlinkedlist<T>& lb)
{
    Node<T>* pa,* pb,* pc,* p;
    pa=la.head->next,pb=lb.head->next; pc=this->head;

    while(pa&&pb)
    {
        if(pa->data<pb->data)
        {
            p=new Node<T>(); p->data=pa->data;
            pc->next=p; pc=pc->next; pa=pa->next;
        }
        else
        {
            p=new Node<T>(); p->data=pb->data;
            pc->next=p; pc=pc->next; pb=pb->next;
        }
    }

    while(pa)
    {
        p=new Node<T>(); p->data=pa->data;
        pc->next=p; pc=pc->next; pa=pa->next;
    }
    while(pb)
    {
        p=new Node<T>(); p->data=pb->data;
        pc->next=p; pc=pc->next; pb=pb->next;
    }
}


class Polydata
{
public:
    float coef; // 系数
    int expn;   // 指数
public:
    Polydata(){};
    Polydata(float c,int a): coef(c),expn(a){};
    ~Polydata(){};

    bool operator<(const Polydata& a) const;
    bool operator==(const Polydata& a) const;
};

bool Polydata:: operator<(const Polydata& a) const
{
    if(this->expn<a.expn) return true;
    else return false;
}
bool Polydata:: operator==(const Polydata& a) const
{
    if(this->expn==a.expn) return true;
    else return false;
}


class Ploynomial: public sortedlinkedlist<Polydata>
{
public:
    Ploynomial()
    {
        this->head->data.coef=0;
        this->head->data.expn=-1000000000;
    }
    ~Ploynomial()=default;

    void Add(Ploynomial& la,Ploynomial& lb);

    Status Insert(Polydata e);
};

Status Ploynomial:: Insert(Polydata e)
{
    Node<Polydata>* p,* s,* pre;
    pre=this->head;
    p=pre->next;
    if(p)
    {
        while(p&&p->data<e)
        {
            pre=p;
            p=p->next;
        }
    }

    if(p&&(p->data.expn==e.expn))
    {
        int a=p->data.coef+e.coef;
        if(a) p->data.coef=a;
        else 
        {
            pre->next=p->next;
            delete p;
        }
    }
    else
    {
        s=new Node<Polydata>;
        s->data=e;
        s->next=p;
        pre->next=s;
    }
    return OK;
}

void Ploynomial:: Add(Ploynomial& la,Ploynomial& lb)
{
    Node<Polydata>* pa,* pb;
    pa=la.head->next,pb=lb.head->next;

    while(pa&&pb)
    {
        if(pa->data.expn<pb->data.expn)
        {
            this->Insert(pa->data);
            pa=pa->next;
        }
        else if(pa->data.expn>pb->data.expn)
        {
            this->Insert(pb->data);
            pb=pb->next;
        }
        else
        {
            float a=pa->data.coef+pb->data.coef;
            if(fabs(a)>1e-9) 
            {
                Polydata p(a,pa->data.expn);
                this->Insert(p);
            }
            pa=pa->next,pb=pb->next;
        }
    }

    while(pa)
    {
        this->Insert(pa->data);
        pa=pa->next;
    }
    while(pb)
    {
        this->Insert(pb->data);
        pb=pb->next;
    }
}



// 打印多项式
void PrintPoly(const char* name,Ploynomial& p)
{
    cout<< name<<" = ";
    Node<Polydata>* cur=p.head->next;
    if (!cur) { cout<<"0"; }
    while(cur)
    {
        cout<<cur->data.coef<<"x^"<<cur->data.expn;
        if(cur->next) cout<<" + ";
        cur=cur->next;
    }
    cout<<endl;
}


int main()
{
    // ---------- 测试 1：基本有序插入 ----------
    cout << "===== 测试 1：有序插入 =====" << endl;
    Ploynomial p1;
    p1.Insert(Polydata(3, 2));   // 3x^2
    p1.Insert(Polydata(1, 0));   // 1x^0
    p1.Insert(Polydata(5, 4));   // 5x^4
    p1.Insert(Polydata(2, 1));   // 2x^1
    PrintPoly("p1", p1);
    // 期望：1x^0 + 2x^1 + 3x^2 + 5x^4

    // ---------- 测试 2：同类项合并 ----------
    cout << "\n===== 测试 2：同类项合并 =====" << endl;
    Ploynomial p2;
    p2.Insert(Polydata(3, 2));
    p2.Insert(Polydata(4, 2));   // 与 3x^2 合并成 7x^2
    p2.Insert(Polydata(1, 1));
    PrintPoly("p2", p2);
    // 期望：1x^1 + 7x^2

    // ---------- 测试 3：合并后系数为 0，删除节点 ----------
    cout << "\n===== 测试 3：系数抵消 =====" << endl;
    Ploynomial p3;
    p3.Insert(Polydata(5, 3));
    p3.Insert(Polydata(-5, 3));  // 5x^3 + (-5x^3) = 0，节点应被删除
    p3.Insert(Polydata(2, 1));
    PrintPoly("p3", p3);
    // 期望：2x^1

    // ---------- 测试 4：多项式加法 ----------
    cout << "\n===== 测试 4：多项式加法 =====" << endl;
    Ploynomial A, B, C;

    // A = 3x^0 + 2x^1 + 5x^3
    A.Insert(Polydata(3, 0));
    A.Insert(Polydata(2, 1));
    A.Insert(Polydata(5, 3));

    // B = 1x^1 + 4x^2 + (-5)x^3
    B.Insert(Polydata(1, 1));
    B.Insert(Polydata(4, 2));
    B.Insert(Polydata(-5, 3));

    PrintPoly("A", A);
    PrintPoly("B", B);

    C.Add(A, B);
    PrintPoly("C = A + B", C);
    // 期望：3x^0 + 3x^1 + 4x^2
    //   x^0: 3
    //   x^1: 2 + 1 = 3
    //   x^2: 4
    //   x^3: 5 + (-5) = 0（消失）

    // ---------- 测试 5：A、B 不应被修改 ----------
    cout << "\n===== 测试 5：加法后 A、B 应不变 =====" << endl;
    PrintPoly("A", A);
    PrintPoly("B", B);
    // 期望和测试 4 中一样

    // ---------- 测试 6：空多项式相加 ----------
    cout << "\n===== 测试 6：空多项式 =====" << endl;
    Ploynomial E1, E2, E3;
    E3.Add(E1, E2);
    PrintPoly("E3 = E1 + E2", E3);
    // 期望：0

    // ---------- 测试 7：一个空 + 一个非空 ----------
    cout << "\n===== 测试 7：空 + 非空 =====" << endl;
    Ploynomial F1, F2, F3;
    F2.Insert(Polydata(7, 5));
    F2.Insert(Polydata(2, 1));
    F3.Add(F1, F2);
    PrintPoly("F3 = 0 + F2", F3);
    // 期望：2x^1 + 7x^5

    // ---------- 测试 8：重复调用 Add，this 应被清空 ----------
    cout << "\n===== 测试 8：重复 Add，this 应被清空 =====" << endl;
    Ploynomial G1, G2, G3;
    G1.Insert(Polydata(1, 1));
    G2.Insert(Polydata(2, 2));
    G3.Add(G1, G2);
    PrintPoly("G3 第一次", G3);
    // 期望：1x^1 + 2x^2

    G3.Add(G2, G1);   // 再算一次，G3 原有内容应被清空
    PrintPoly("G3 第二次", G3);
    // 期望：1x^1 + 2x^2（而不是 1x^1 + 2x^2 + 1x^1 + 2x^2）

    return 0;
}