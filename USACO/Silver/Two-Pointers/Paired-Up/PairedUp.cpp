#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using vc = vector<lli>;
#define ff first
#define ss second
#define FOR(i, n, k) for(int i= 0; i<n; i+= k)
const int maxN = 1e5 + 5;
pii arr[maxN];
void setIO(string name)
{
    cin.tie(0)->sync_with_stdio(0);
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
int main()
{
    setIO("pairup");
    int n;
    cin>>n;
    FOR(i, n, 1)
    {
        cin>>arr[i].ss>>arr[i].ff;
    }
    sort(arr, arr + n);
    int i = 0, j = n - 1;
    lli mx = 0;
    while(i<=j)
    {
        if(i == j)
        {
            mx = max(mx, arr[i].ff + arr[i].ff);
            i++;
            j--;
            continue;
        }
        if(arr[i].ss > arr[j].ss)
        {
            mx = max(mx, arr[i].ff + arr[j].ff);
            arr[i].ss -= arr[j].ss;
            j--;
        }
        else if (arr[i].ss < arr[j].ss)
        {
            mx = max(mx, arr[i].ff + arr[j].ff);
            arr[j].ss -= arr[i].ss;
            i++;
        }
        else
        {
            mx = max(mx, arr[i].ff + arr[j].ff);
            arr[i].ss = 0;
            arr[j].ss = 0;
            i++;
            j--;
        }
    }
    cout<<mx<<'\n';

}