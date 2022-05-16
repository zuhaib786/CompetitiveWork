#include<bits/stdc++.h>
using namespace std; 
using lli = long long int;
using pii = pair<lli, lli>;
lli arr[200005];
// lli ans[200005];
 
const lli MAX = 1e17;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    // set<int>s;    
    map<lli, int>m;
    lli n;
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i+1];
        arr[i+1] += arr[i];
        arr[i+1]%=n;
        arr[i+1]+=n;
        arr[i+1]%=n;
    }
    lli cnt = 0;
    for(int i = 0; i<n+1; i++)
    {
        // arr[i] - w = 0
        // arr[i] = w;
 
        lli find = arr[i];
        if(m.count(find))
        {
            cnt+=m[find];
        }
        m[arr[i]]++;
    }
    cout<<cnt<<endl;
 
}
