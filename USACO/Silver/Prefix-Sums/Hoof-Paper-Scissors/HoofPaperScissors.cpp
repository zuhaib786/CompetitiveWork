#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
void setIO(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w",stdout);
}
int main()
{
    setIO("hps");
    int n;
    cin>>n;
    int P[n + 1], H[n + 1], S[n + 1];
    memset(P, 0, sizeof(P));
    memset(H, 0, sizeof(H));
    memset(S, 0, sizeof(S));
    for(int i = 0; i<n; i++)
    {
        char k;
        cin>>k;
        P[i + 1] = P[i] + (k == 'P');
        H[i + 1] = H[i] + (k == 'H');
        S[i + 1] = S[i] + (k == 'S');
    }
    int ans = 0;
    for(int i = 0; i<n + 1; i++)
    {
        int mx1 = max({P[i], S[i], H[i]});
        int mx2 = max({P[n] - P[i], S[n] - S[i], H[n] -H[i]});
        ans = max(ans, mx1 + mx2);
    }
    cout<<ans<<'\n';
}