#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<int, int>;
const int maxN = 1e2 + 2;
void setIO(string name)
{
    cin.tie(0)->sync_with_stdio(0);
    freopen((name + ".in").c_str() , "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
int arr[maxN];  
int solve(int i, int n)
{
    int lefty = i;
    int righty = i;
    int lr = 1;
    int rr = 1;
    while(true)
    {
        int l = lefty;
        while(l - 1 >=0 && abs(arr[lefty] - arr[l - 1]) <= lr)
        {
            l--;
        }
        if(lefty == l)
            break;
        lefty = l;
        lr++;
    }
    while(true)
    {
        int r = righty;
        while(r + 1 < n && abs(arr[r + 1] - arr[righty]) <= rr)
        {
            r++;
        }
        // r-=1;
        if(r == righty)
            break;

        righty = r;
        rr++;
    }
    return abs(righty - i) + abs(i - lefty) + 1;
}

int main()
{
    setIO("angry");
    int n;
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr + n);
    int mx = 0;
    for(int i = 0; i<n; i++)
    {
        mx = max(mx, solve(i, n));
    }
    cout<<mx<<'\n';
}   