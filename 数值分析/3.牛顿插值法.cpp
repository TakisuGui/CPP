#include<bits/stdc++.h>
using namespace std;


long double newtonInterp(const vector<long double>& x,const vector<long double>& y,long double x0) 
{
    int n=x.size();
    vector<vector<long double>> table(n,vector<long double>(n,0.0L));
    for (int i=0;i<n;i++) table[i][0]=y[i];

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            table[i][j]=(table[i][j-1]-table[i-1][j-1])/(x[i]-x[i-j]);
        }
    }

    long double ans=table[n-1][n-1];
    for (int i=n-2; i>=0;i--) ans=ans*(x0-x[i])+table[i][i];
    return ans;
}

void solve()
{
    cout<<"请输入点的数量"<<endl;
    int n; cin>>n;
    vector<long double> x(n),y(n);
    cout<<"请输入点的坐标"<<endl;
    for(int i=0;i<n;i++) cin>>x[i]>>y[i];
    cout<<"请输入求值点 x0"<<endl;
    long double x0; cin>>x0;

    cout<<fixed<<setprecision(10)<<newtonInterp(x,y,x0)<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}