#ifndef STRING_H
#define STRING_H

#include <bits/stdc++.h>
using namespace std;
typedef int Status;
#define OK 1
#define ERROR 0


class String
{
public:
    String(){};
    virtual ~String(){};

    virtual void Assign(const char s[])=0;                         // 赋值
    virtual void Copy(const String& str)=0;                        // 拷贝
    virtual int Compare(const String& s) const=0;                  // 比较：返回 <0 / 0 / >0
    virtual int Length() const=0;                                  // 求长度
    virtual void Concat(const String& s1,const String& s2)=0;    // 连接：this = s1 + s2
    virtual Status Sub(int pos,int len,String& sub)=0;             // 求子串
    virtual Status Insert(int pos,const String& t)=0;              // 插入
    virtual Status Delete(int pos,int len)=0;                      // 删除
};


#endif 