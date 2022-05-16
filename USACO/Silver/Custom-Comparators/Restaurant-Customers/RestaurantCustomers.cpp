#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<int, int>;
pii arr[400005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        arr[2*i]= {a,1};
        arr[2*i+1] = {b,-1};
    }
    
    sort(arr, arr+2*n);
    int cnt = 0;
    int max_cnt = 0;
    for(int i = 0; i<2*n; i++)
    {
        cnt+=arr[i].second;
        max_cnt = max(cnt, max_cnt);
    }
    cout<<max_cnt<<'\n';
}
