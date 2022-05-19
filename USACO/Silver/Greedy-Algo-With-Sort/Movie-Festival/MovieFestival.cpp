#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<int, int>;
pii arr[200005];
bool comp(const pii &a , const pii & b)
{
    return b.second == a.second ? a.first<b.first : a.second<b.second;
}
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
        arr[i]= {a,b};
        // arr[2*i+1] = {b,-1};
    }
    
    sort(arr, arr+n, comp);
    int cnt = 0;
    int cur_time = 0;
    for(int i = 0; i<n; i++)
    {
        if(cur_time <= arr[i].first)
        {
            cnt++;
            cur_time = arr[i].second;
        }
    }
    cout<<cnt<<endl;
    
}

