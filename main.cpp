#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
const int maxN = 1e5 + 5;
lli arr[maxN];
vector<pair<int, int>>A[4];
vector<pair<int,int>>B[4];
int n;
bool solve(pair<int, int> cur, int idx)
{
    if(idx == n - 1)
    {
        return true;
    }
    // cout<<cur.first<<" "<<cur.second<<endl;
    if(cur.second == 0)
    {
        int num = arr[idx + 1];
        bool found = false;
        pair<int, int>p ;
        for(auto x: A[cur.first])
        {
            if(x.first == num)
            {
                p = x;
                found = true;
                break;
            }
        }
        
        // cout<<p.first<<" "<<p.second<<endl;
        if(found)
        {
            // if(idx == )
            return solve(p, idx+1);
        }
        // cout<<idx<<"\n";
        return false;
    }
    else{
        int num = arr[idx + 1];
        bool found = false;
        pair<int, int>p ;
        for(auto x: B[cur.first])
        {
            if(x.first == num)
            {
                p = x;
                found = true;
                break;
            }
        }
        // cout<<p.first<<" "<<p.second<<endl;
        if(found)
        {
            return solve(p, idx+1);
        }
        // cout<<idx<<'\n';
        return false;
    }
}
int main()
{
    int t;
    cin>>t;
    A[0] = {{1,1}, {2, 0}, {0,0}};
    A[1] = {{0,0}, {2, 0}, {1, 1}};
    B[1] = {{2, 1}, {3, 0}, {1, 0}};
    A[2] = {{1, 0}, {3, 0}, {2, 1}};
    B[2] = {{0, 0}, {1,1}, {2,0}};
    A[3] = {{1,0}, {2,1}, {3,0}};
    while(t--)
    {
        // int n;
        cin>>n;
        for(int i = 0; i< n; i++)
        {
            cin>>arr[i];
        }
        if(arr[0] == 0 || arr[0] == 3)
        {
            bool b = solve({arr[0], 0}, 0);
            if(b)
            {
                cout<<"Yes\n";
            }
            else
            {
                cout<<"No\n";
            }
        }
        else
        {
            bool b = solve({arr[0], 0}, 0);
            // cout<<b<<'\n';
            b |= solve({arr[0], 1}, 0);
            // cout<<b<<'\n';
            if(b)
            {
                cout<<"Yes\n";
            }
            else
            {
                cout<<"No\n";
            }
        }
        
        
    }
    return 0;
}