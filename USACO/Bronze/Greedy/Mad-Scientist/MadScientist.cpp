#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
void setIO(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
int main()
{
    setIO("breedflip");
    int n;
    cin>>n;
    string s1, s2;
    cin>>s1>>s2;
    assert(s1.size() == n && s2.size() == n);
    int flip = false;
    int cnt = 0;
    for(int i = 0; i<n; i++)
    {
        if(s1[i] == s2[i])
        {
            cnt += flip;
            flip = false;
        }
        else
        {
            flip = true;
        }
    }
    cnt += flip;
    cout<<cnt<<'\n';
}