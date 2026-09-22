#include <bits/stdc++.h>
#include "2_ordered_Stack.h"
using namespace std;


string conversion(int num,int base)
{
    if(num==0) return "0";
    const char* digits="0123456789ABCDEF";
    SqStack<char> s;
    string ans;
    while(num)
    {
        s.Push(digits[num%base]);
        num=num/base;
    }
    while(!s.isempty())
    {
        ans+=s.Top();
        s.Pop();
    }
    return ans;
}

void solve()
{
    int n,base; cin>>n>>base;
    cout<<conversion(n,base)<<endl;
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
