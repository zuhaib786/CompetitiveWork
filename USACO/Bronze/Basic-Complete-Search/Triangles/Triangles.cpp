#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
void setIO(string name = "")
{
    if(name.size() == 0)    return;
    freopen((name + ".in").c_str() , "r", stdin);
    freopen((name + ".out").c_str() , "w", stdout);
}
int main()
{
    setIO("triangles");
    map<lli, vector<pii>>xcor;
    map<lli, vector<pii>>ycor;
    int n;
    cin>>n;
    pii arr[n];
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i].first>>arr[i].second;
        xcor[arr[i].first].push_back(arr[i]);
        ycor[arr[i].second].push_back(arr[i]);
    }
    lli maxArea = 0;
    for(int i = 0; i<n; i++)
    {
        // middle point = arr[i]
        pii v2 = arr[i];
        // cout<<ycor[v2.second].size()<<" "<<xcor[v2.first].size()<<'\n';
        // Moving along y axis;
        for(auto v1:ycor[v2.second])
        {
            for(auto v3: xcor[v2.first])
            {
                // cout<< abs(v2.first - v1.first)*abs(v2.second - v3.second)<<'\n';
                maxArea = max(maxArea, abs(v2.first - v1.first)*abs(v2.second - v3.second));
            }
        }
    }
    cout<<maxArea<<'\n';
}
