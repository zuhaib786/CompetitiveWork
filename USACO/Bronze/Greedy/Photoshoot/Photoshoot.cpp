#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int main()
{
    // star --> Good problem.
    int n;
    cin>>n;
    n/=2;
    string s;
    cin>>s;
    string comp;
    for(int i = 0; i<n; i++)
    {
        string k="";
        k += s[2*i];
        k += s[2*i + 1];
        if(k == "GG" || k == "HH")
        {
            continue;
        }
        else if(k == "HG")
        {
            if(comp.size() == 0 || comp[comp.size() - 1]=='B')
            comp += "A";//desirable
        }
        else
        {
            if(comp.size() == 0 || comp[comp.size() - 1]=='A')
            comp += "B";// undesirable;
        }
        // cout<<i<<" "<<k<<" " <<comp<<'\n';
    }
    if(comp[comp.size() - 1]=='A')
    {
        comp = comp.substr(0, comp.size() - 1);
    }
   cout<<comp.size()<<'\n';
}