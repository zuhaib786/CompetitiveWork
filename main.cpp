#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
const int maxN = 1e6 + 5;
lli arr[maxN];

void solve()
{
    int n;
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    int cnt = 0;
    for(int i = 0; i<31; i++)
    {
        
        int zc = 0, oc = 0;
        for(int k = 0; k<n; k++)
        {
            zc += ((arr[k] & (1<<i)) == 0);
            oc += ((arr[k] & (1<<i))!=0);
        }
        // cout<<zc<<" "<<oc<<" "<<i<<'\n';
        if(zc!=0 && oc !=0 )
        {
            int j = 0;
            int cur =  - 1;
            int l = 0;
            for(int k = 0; k<n; k++)
            {
               
                if(arr[k] &(1<<i))
                {
                    if(cur == -1)
                    {
                        cur = arr[k];
                        l = 1;
                    }
                    else
                    {
                        cur = cur & (arr[k]);
                        l++;
                    }
                }
                else
                {
                    if(cur == -1)
                    {
                        arr[j] = arr[k];
                        j++;
                    }
                    else
                    {
                        arr[j] = arr[k] & (cur);
                        cur = -1;
                        cnt += l;
                        j++;
                        l = 0;
                    }
                }
                // cout<<cur<<" "<<cnt<<'\n';
            }
            // cout<<cur<<'\n';
            if(cur !=-1)
            {
                cnt += l;
                arr[j] = arr[j] & (cur);
                cur = -1;
            }
            n = j;
            // cout<<n<<'\n';
        }
    }
    cout<<cnt<<'\n';
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