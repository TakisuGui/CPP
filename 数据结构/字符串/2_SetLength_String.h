#ifndef SETLENGTH_STRING_H
#define SETLENGTH_STRING_H

#include "1_String.h"
using namespace std;
const int N=1e5+10;


class SetLength_String: public String
{
public:
    char data[N];
    int length;
public:
    SetLength_String(const char s[]="");
 
    void Assign(const char s[]);                          
    void Copy(const String& s);                        
    int Compare(const String& s) const;                   
    int Length() const;                         
    void Concat(const String& s1, const String& s2); 
    Status Sub(int pos,int len,String& sub);         
    Status Insert(int pos,const String& t);
    Status Delete(int pos,int len);                                    
};


SetLength_String::SetLength_String(const char s[])
{
    int i=0;
    while(s[i]!='\0'&&i<N-1)
    {
        data[i]=s[i];
        i++;
    }
    data[i]='\0';
    length=i;
}

void SetLength_String:: Assign(const char s[])
{
    int i=0;
    while(s[i]!='\0'&&i<N-1)
    {
        data[i]=s[i];
        i++;
    }
    data[i]='\0';
    length=i;
}

void SetLength_String:: Copy(const String& str) 
{
    const SetLength_String* sstr = dynamic_cast<const SetLength_String*>(&str);

    int i=0;
    while (i<sstr->length)
    {
        data[i]=sstr->data[i];
        i++;
    }
    data[i]='\0';
    length=i;
}

int SetLength_String:: Compare(const String& s) const
{
    const SetLength_String* sstr = dynamic_cast<const SetLength_String*>(&s);
    if (sstr == nullptr) return 1;

    int ans=0,i=0;
    int n=min(sstr->length,this->length);
    while(i<n&&data[i]==sstr->data[i]) i++;
    if(i==n)
    {
        if(this->length>n) ans=1;
        else if(this->length<n) ans=-1;
    }
    else
    {
        if(data[i]>sstr->data[i]) ans=1;
        if(data[i]<sstr->data[i]) ans=-1;
    }
    return ans;
}

int SetLength_String:: Length() const
{
    return length;
}

void SetLength_String:: Concat(const String& s1, const String& s2)
{
    const SetLength_String* ss1 = dynamic_cast<const SetLength_String*>(&s1);
    const SetLength_String* ss2 = dynamic_cast<const SetLength_String*>(&s2);
    if (ss1 == nullptr || ss2 == nullptr) return;

    for(int i=0;i<ss1->length;i++) data[i]=ss1->data[i];
    for(int i=0;i<ss2->length;i++) data[ss1->length+i]=ss2->data[i];
    length=ss1->length+ss2->length;
}

Status SetLength_String:: Sub(int pos,int len,String& sub)
{
    SetLength_String* ssub = dynamic_cast<SetLength_String*>(&sub);

    for(int i=0;i<len;i++) ssub->data[i]=data[pos+i];
    ssub->length=len;
    ssub->data[len]='\0';
    return OK;
}

Status SetLength_String:: Insert(int pos, const String& t)
{
    const SetLength_String* st = dynamic_cast<const SetLength_String*>(&t);
    if (st == nullptr) return ERROR;
    if (pos < 0 || pos >= length) return ERROR;

    if(pos<0||pos>length) return ERROR;
    if(length+st->length>N) return ERROR;
    else
    {
        for(int i=length-1;i>=pos;i--) data[st->length+i]=data[i];
        for(int i=0;i<st->length;i++) data[pos+i]=st->data[i];
        length+=st->length;
        return OK;
    }
}

Status SetLength_String:: Delete(int pos,int len)
{
    if(pos<0||pos>length-len+1) return ERROR;
    for(int i=pos;i<=length-len;i++) data[i]=data[i+len];
    length-=len;
    return OK;
}

#endif 