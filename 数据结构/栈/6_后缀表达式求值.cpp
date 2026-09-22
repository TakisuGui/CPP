#include <bits/stdc++.h>
#include "2_ordered_Stack.h"
using namespace std;
#define endl "\n"


int priority(char op)
{
    if(op=='+'||op =='-') return 1;
    if(op=='*'||op =='/') return 2;
    if(op=='~') return 3;
    return 0; // '(' 视为 0，不入此判断
}

int calc(int a,int b,char op)
{
    switch(op)
    {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
    }
    return 0;
}

bool isUnaryMinus(const string& s,int i)
{
    if(s[i]!='-') return false;
    if(i==0) return true;
    char prev=s[i-1];
    return prev=='(' || prev=='+' || prev =='-'|| prev =='*' || prev=='/';
}


string infixToPostfix(const string& s)
{
    SqStack<char> ops;
    string ans;
    for(int i=0;i<s.size();i++)
    {
        char c=s[i];
        if(isdigit(c))
        {
            while(i<s.size() && isdigit(s[i]))
            {
                ans+=s[i++];
            }
            i--;
            ans+=' ';
        }
        else if(isUnaryMinus(s,i))
        {
            ops.Push('~');
        }
        else if(c=='(') ops.Push(c);
        else if(c==')')
        {
            while(ops.Top()!='(')
            {
                ans+=ops.Top(); ans+=' ';
                ops.Pop(); 
            }
            ops.Pop();
        }
        else
        {
            while(!ops.isempty() && ops.Top()!='(' && priority(ops.Top())>=priority(c))
            {
                ans+=ops.Top(); ans+=' ';
                ops.Pop();
            }
            ops.Push(c);
        }
    }

    while(!ops.isempty())
    {
       ans+=ops.Top(); ans+=' ';
        ops.Pop();
    }
    return ans;
}


int eva(const string& s)
{
    SqStack<int> nums;
    stringstream ss(s);
    string token;
    while(ss>>token)
    {
        if(token == "~")
        {
            int a=nums.Top(); nums.Pop();
            nums.Push(-a);
        }
        else if(token.size()==1 && string("+-*/").find(token[0])!=string::npos) // 是否为运算符
        {
            int b=nums.Top(); nums.Pop();
            int a=nums.Top(); nums.Pop();
            nums.Push(calc(a,b,token[0]));
        }
        else nums.Push(stoi(token));
    }
    return nums.Top();
}

void solve()
{
    string s; cin>>s;
    cout<<eva(infixToPostfix(s))<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}