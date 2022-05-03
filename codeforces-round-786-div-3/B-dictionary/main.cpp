#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using lli = long long int;
map<string, int>m;
void precalc()
{
    vector<char>alphabet;
    for(int i = 0; i<26; i++)
    {
        int x = 'a';
        x += i;
        char c = x;
        alphabet.push_back(c);
    }
    vector<string>v;
    for(int i = 0; i<26; i++)
    {
        for(int j = 0; j<26; j++)
        {
            if(i!=j)
            {
                string s = "";
                s += alphabet[i];
                s += alphabet[j];
                // cout<<s<<'\n';
                v.push_back(s);
            }
        }
    }
    sort(v.begin(), v.end());
    int cnt = 1;
    for(auto x: v)
    {
        m[x] = cnt;
        cnt++;
    }
}
int main()
{
    int t;
    cin>>t;
    precalc();
    while(t--)
    {
        string s;
        cin>>s;
        // if
        cout<<m[s]<<"\n";
    }
}
