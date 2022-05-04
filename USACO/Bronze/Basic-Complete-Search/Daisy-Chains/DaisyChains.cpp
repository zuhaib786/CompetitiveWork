#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
void setIO(string name = "")
{
    if(name.size() == 0)    return;
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str() , "w", stdout);
}
int main()
{
	// setIO("Daisy");
    int n;
    cin>>n;
    lli petals[n];
    for(int i = 0; i<n; i++)
    {
        cin>>petals[i];
    }
    lli ans = 0;
    for(int i = 0; i<n; i++)
    {
        lli sum = 0;
        set<int>s;
        for(int j = i; j< n; j++)
        {
            sum += petals[j];
            s.insert(petals[j]);
            int cnt = j - i + 1;
            if(sum % cnt == 0)
            {
                ans += (s.find(sum/cnt)!=s.end());
            }
            
        }
    }
    cout<<ans<<'\n';
}
