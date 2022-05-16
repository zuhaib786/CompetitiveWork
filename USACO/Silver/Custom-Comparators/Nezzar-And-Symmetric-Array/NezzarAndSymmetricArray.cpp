#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
const int maxN = 1e5 + 5;
lli arr[2*maxN];
void solve()
{
    int n;
    cin>>n;
    for(int i = 0; i < 2*n; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr + 2*n);
    bool check1 = true;
    vector<lli>d;
    for(int i = 0; i< 2*n; i+=2)
    {
        check1 = check1 && (arr[i] == arr[i + 1]);
        d.push_back(arr[i]);
    }
    if(!check1)
    {
        cout<<"NO\n";
        return;
    }
    if(d[n - 1] %(2 * n)!=0)
    {
        cout<<"NO\n";
        return;
    }
    set<lli>s;
    lli ak = d[n - 1]/(2*n);
    s.insert(ak);
    lli div = n - 1 ;
    for(int i = n - 2; i>=0; i--)
    {
        // cout<<ak<<" "<<(d[i + 1] - d[i])<<" "<<div<<"\n";
        if( (d[i + 1] - d[i])%(2*div)!=0)
        {
            cout<<"NO\n";
            return;
        }
        
        lli cur = ak - (d[i + 1] - d[i])/(2*div);
        // cout<<cur<<'\n';
        if(s.find(cur)!=s.end() || cur <= 0)
        {
            cout<<"NO\n";
            return;
        }
        s.insert(cur);
        ak = cur;
        div--;
    }
    cout<<"YES\n";
    return;

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