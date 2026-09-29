#include "2_SetLength_String.h"
using namespace std;
#define endl "\n"


void solve()
{
    SetLength_String n,m;
    string text,goal; 
    getline(cin, text);
    getline(cin, goal);
    n.Assign(text.c_str()); m.Assign(goal.c_str());

    for(int i=0;i<=n.length-m.length;i++)
    {
        if(n.data[i]==m.data[0])
        {
            bool pass=true;
            for(int j=0;j<m.length;j++)
            {
                if(n.data[i+j]!=m.data[j]) 
                {
                    pass=false;
                    break;
                }
            }
            if(pass)
            {
                cout<<i<<endl;
                return;
            }
        }
    }
    cout<<-1<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin>>t;
    cin.ignore();
    while(t--)
    {
        solve();
    }

    return 0;
}