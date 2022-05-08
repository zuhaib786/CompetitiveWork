#include<bits/stdc++.h>
using namespace std;

const int maxN = 102;
int arr[maxN];

void setIO(string name = "")
{
    if(name.size() == 0)    return;
    cin.tie(0)->sync_with_stdio(0);
    freopen((name + ".in").c_str() , "r", stdin);
    freopen((name + ".out").c_str() , "w", stdout);
}

int solve(vector<int>  v, int i , int j, int n)
{
    int i1 = 0;
    int ans = 0;
    while(i1 < v.size() )
    {
        ans += abs(v[i1] - v[i1 + 1]);
        i1 += 2;
    }
    return ans;

}

int main()
{
    int n;
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        cin>>arr[2*i]>>arr[2* i + 1];
    }
    int maxDif = INT_MAX;
    sort(arr, arr + 2*n);
    for(int i = 0; i<2* n; i++)
    {
        for(int j = i + 1; j< 2 * n; j++)
        {
            vector<int>v;
            for(int k = 0; k<2*n; k++)
            {
                if(k != i && k != j)
                {
                    v.push_back(arr[k]);
                }
            }
            maxDif = min(maxDif, solve(v, i, j, n));
        }
    }
    cout<<maxDif<<'\n';
}