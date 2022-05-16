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
    setIO("bcount");
    int n, q;
    cin>>n>>q;
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    int ps1[n + 1], ps2[n + 1], ps3[n + 1];
    memset(ps1, 0, sizeof(ps1));
    memset(ps2, 0, sizeof(ps2));
    memset(ps3, 0, sizeof(ps3));
    for(int i = 0; i<n; i++)
    {
        ps1[i + 1] = ps1[i] + (arr[i] == 1);
        ps2[i + 1] = ps2[i] + (arr[i] == 2);
        ps3[i + 1] = ps3[i] + (arr[i] == 3);
    }
    while(q--)
    {
        int a, b;
        cin>>a>>b;
        a--;
        cout<<ps1[b] - ps1[a]<<" "<<ps2[b] - ps2[a]<<" "<<ps3[b] - ps3[a]<<'\n';
    }
    return 0;
    
}