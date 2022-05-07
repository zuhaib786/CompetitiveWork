//Load Balancing
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli,lli>;
void setIO(string name = "")
{
    cin.tie(0)->sync_with_stdio(0);
	if(name.size() == 0)
		return;
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}
pii arr[101];
int main()
{
    setIO("balancing");
    int n,b;
    cin>>n>>b;
    unordered_set<int> xs;
    unordered_set <int>ys;
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i].first>>arr[i].second;
        xs.insert(arr[i].first);
        ys.insert(arr[i].second);
    }
    int mn = INT_MAX;
    for(auto x: xs)
    {
        for(auto y: ys)
        {
            int x_ = x-1;
            int y_ = y - 1;
            int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 =0;
            for(int i =0; i<n; i++)
            {
                if(arr[i].first < x_)
                {
                    if(arr[i].second < y_)
                    {
                        cnt1 ++;
                    }
                    else if (arr[i].second > y_)
                    {
                        cnt2 ++;
                    }
                }
                else 
                {
                    if(arr[i].second < y_)
                    {
                        cnt3++;
                    }
                    else
                    {
                        cnt4++;
                    }
                }
            }
            mn = min(mn, max({cnt1, cnt2, cnt3, cnt4})); 
        }
    }
    cout<<mn<<'\n';


}