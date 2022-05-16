#include<bits/stdc++.h>
using namespace std; 
using lli = long long int;
using pii = pair<lli, lli>;
pii arr[200005];
// int ans[200005];
 
const lli MAX = 1e17;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    // set<int>s;
    lli n,x;
    cin>>n>>x;
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i].first;
        arr[i].second = i+1;
    }
    sort(arr, arr+n);
    for(int i = 0; i<n; i++)
    {
        int j = i+1;
        int k = n-1;
        lli req = x - arr[i].first;
        while(j<k)
        {
            if(arr[j].first + arr[k].first == req)
            {
                cout<<arr[i].second<<" "<<arr[j].second<<" "<<arr[k].second<<endl;
                return 0;
            }
            else if (arr[j].first + arr[k].first < req)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
 
     
    
}

