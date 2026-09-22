#include <bits/stdc++.h>
#include "2_ordered_Stack.h"
using namespace std;


int priority(char op)
{
    if(op=='+'||op =='-') return 1;
    if(op=='*'||op =='/') return 2;
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

int eva(const string& s)
{
    SqStack<int> nums,ops;
    for(int i=0;i<s.size();i++)
    {
        
    }
}

void solve()
{
    string s; cin>>s;
    cout<<eva(s)<<endl;
}

signed main()
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