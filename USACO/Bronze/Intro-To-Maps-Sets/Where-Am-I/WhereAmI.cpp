#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli , lli>;
void setIO(string name = "")
{
    if(name.size())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
int main()
{
    setIO("whereami");
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i = 1; i<=s.size(); i++)
    {
        set<string>st;
        string under = "";
        bool poss = true;
        for(int j = s.size() - 1;  j >= 0; j--)
        {
            under  = s[j] + under;
            if(under.size() > i)
            {
                under.pop_back();
            }
            // cout<<under<<' '<<i<<'\n';
            if(st.find(under) != st.end())
            {
                poss = false;
                break;
            }
            st.insert(under);
        }
        if(poss)
        {
            cout<<i<<'\n';
            break;
        }
    }
}