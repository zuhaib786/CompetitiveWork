//Load Balancing
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli,lli>;
const int maxN = 1001;
const int A = 1001;
const int B = 1001;
void setIO(string name = "")
{
    cin.tie(0)->sync_with_stdio(0);
	if(name.size() == 0)
		return;
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}
int xd[A][B];
int xd1[A][B];
int xd2[A][B];
int xd3[A][B];
int xd4[A][B];
pii arr[maxN];
int main()
{
    setIO("balancing");
    int n,b;
    cin>>n;
    set<lli> xs;
    set <lli>ys;
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i].first>>arr[i].second;
        xs.insert(arr[i].first);
        ys.insert(arr[i].second);
    }
    
    memset(xd, 0,sizeof(xd));
    map<lli, int>compX;
    map<lli, int>compY;
    for(auto x: xs)
    {
        compX[x - 1] = compX.size();
    }
    for(auto y: ys)
    {
        compY[y - 1] = compY.size();
    }
    for(int i = 0; i < n; i++)
    {
        xd[compX[arr[i].first - 1] + 1][compY[arr[i].second - 1] + 1] = 1;
    }
    
    for(int i = 0; i<xs.size() + 2; i++)
    {
        // p.x<i && p,y<j
        int ps = 0;
        for(int j = 0; j < ys.size() + 2; j++)
        {
            
            if(i!=0)
            {
                xd1[i][j] = xd1[i - 1][j] + ps;
            }
            else
            {
                xd1[i][j] = ps;
            }
            if(i!=0)
            ps += xd[i - 1][j];
        }
    }
    
    for(int i =0 ; i<xs.size() + 2; i++)
    {
        int ps = 0;
        for(int j = ys.size() + 1; j>=0; j--)
        {
            if(i!=0)
            ps += xd[i - 1][j];
            if(i!=0)
            {
                xd2[i][j] = xd2[i - 1][j] + ps;
            }
            else
            {
                xd2[i][j] = ps;
            }
            
        }
    }
    for(int i = xs.size() + 1; i>=0; i--)
    {
        int ps = 0;
        for(int j = 0; j < ys.size() + 2; j++ )
        {
            
            if(i != xs.size() + 1)
            {
                xd3[i][j] = xd3[i + 1][j] + ps;
            }
            else
            {
                xd3[i][j] = ps;
            }
            ps += xd[i][j];
        }
    }
    for(int i = xs.size() + 1; i >= 0; i--)
    {
        int ps = 0;
        for(int j = ys.size() + 1; j >= 0; j--)
        {
            ps += xd[i][j];
            if(i != xs.size() + 1)
            {
                xd4[i][j] = xd4[i + 1][j] + ps;
            }
            else
            {
                xd4[i][j] = ps;
            }
            
        }
    }
    // cout<<xd1[1][0]<<" " << xd2[1][0]<<" " <<xd3[1][0]<<" " <<xd4[1][0]<<'\n';
    int mn = INT_MAX;
    for(int i = 0; i<xs.size() + 2; i++)
    {
        for(int j = 0; j<ys.size() + 2; j++)
        {
            mn = min(mn, max({xd1[i][j], xd2[i][j], xd3[i][j], xd4[i][j]}));
        }
    }
    cout<<mn<<'\n';


}