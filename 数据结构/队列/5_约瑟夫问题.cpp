#include <bits/stdc++.h>
#include "3_CircularQueue.h"
using namespace std;
#define endl "\n"


void solve()
{
    int n,m; cin>>n>>m; // n个人 轮到第m个人淘汰;
    Circular_Queue<int> q;
    for(int i=1;i<=n;i++) q.Push(i);
    int cnt=1;

    while(q.Length()!=1)
    {
        int f=q.Top(); q.Pop_front();
        if(cnt!=m)
        {
            cnt++;
            q.Push(f);
        }
        else cnt=1;
    }
    cout<<q.Top()<<endl;
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