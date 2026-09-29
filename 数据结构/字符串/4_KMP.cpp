#include "2_SetLength_String.h"
using namespace std;
#define endl "\n"


vector<int> get_next(SetLength_String s)
{
    if(s.length==1) return {-1};

    vector<int> next(s.length);
    next[0]=-1,next[1]=0;

    int i=2,cn=0; 
    while(i<s.length)
    {
        if(s.data[i-1]==s.data[cn])
        {
            next[i]=cn+1;
            cn++;
            i++;
        }
        else if(cn>0) cn=next[cn];
        else next[i]=0,i++;
    }

    return next;
}

void solve()
{
    SetLength_String n,m;
    string text,goal; 
    getline(cin, text);
    getline(cin, goal);
    n.Assign(text.c_str()); m.Assign(goal.c_str());

    int x=0,y=0;
    vector<int> next_s2=get_next(m);

    while(x<n.length&&y<m.length)
    {
        if(n.data[x]==m.data[y])
        {
            x++; y++;
        }
        else if(y==0)
        {
            x++;
        }
        else y=next_s2[y];
    }

    cout<<((y==m.length) ? x-y : -1)<<endl;
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