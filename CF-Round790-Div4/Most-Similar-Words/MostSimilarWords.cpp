#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int diff(string word1, string word2)
{
    int ans = 0;
    for(int i = 0; i<word1.size(); i++)
    {
        ans += abs(word1[i] - word2[i]);
    }
    return ans;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    string words[n];
    for(int i = 0; i<n; i++)
    {
        cin>>words[i];
    }
    int mn = INT_MAX;
    for(int i = 0; i<n; i++)
    {
        for(int j = i + 1; j<n; j++)
        {
            mn = min(diff(words[i], words[j]), mn);
        }
    }
    cout<<mn<<'\n';
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }   
}

