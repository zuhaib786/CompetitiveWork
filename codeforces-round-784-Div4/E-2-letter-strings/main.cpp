#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
// int arr[10000];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string>v(n); 
        for(int i = 0; i< n; i++)
        {
            cin>>v[i];
        }
        map<char, int>fp;
        map<char, int>sp;
        map<string, int>m;
        for(auto s : v )
        {
            fp[s[0]]++;
            sp[s[1]]++;
            m[s]++;
        }
        lli ans =0;
        for(auto s: v)
        {
            int fir = fp[s[0]];
            int sec = sp[s[1]];
            int tot  = m[s];
            // cout<<fir<<" "<<sec<<" "<<tot<<" " << s<<"\n";
            int c1 = fir - tot;
            int c2 = sec - tot; 
            ans += c1 + c2;
        }
        cout<<ans/2<<endl;
        
    }
    return 0;
}