#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
void setIO(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
bool btw(int a1, int a2, int x)
{
    return (a1 <=  x) && (a2 >=x);
}
void printVec(vector<int> & v)
{
    cout<<"PrintingVec\n";
    for(auto x: v)
    {
        cout<<x + 1<<" ";
    }
    cout<<'\n';
}
int main()
{
    setIO("swap");
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        arr[i] = i + 1;
    }
    int a1, a2, b1, b2;
    cin>>a1>>a2>>b1>>b2;
    map<int, vector<int>>cycles;
    a1 --, a2 -- , b1 -- , b2 --;
    for(int i = 0; i<n; i++)
    {
        if(cycles.count(i))
        {
            continue;
        }
        vector<int>cycle;
        int temp = i;
        cycle.push_back(i);
        int ctitr = 0;
        do
        {
            
            assert(ctitr <= n + 1);
            ctitr++;
            
            if(btw(a1, a2, temp))
            {
                temp = a1 + a2 - temp;
            }
            if(btw(b1, b2, temp))
            {
                temp = b1 + b2 - temp;
            }
            if(temp != i)
            {
                cycle.push_back(temp);
            }
            // if(i == 14)
            // {
            //     cout<<temp<<' ';
            // }
        }
        while(temp != i);
        // cout<<'\n';
        for(int j = 0; j<cycle.size(); j++)
        {
            cycles[cycle[j]] = cycle;
        }
    }
    // for(auto x: cycles)
    // {
    //     cout<<x.first + 1<<"\n";
    //     printVec(x.second);
    // }
    int ans[n];
    for(int i = 0; i<n; i++)
    {
        vector<int>cycle = cycles[i];
        int tk = k%cycle.size();
        int j = 0;
        for(j = 0; j<cycle.size(); j++)
        {
            if(cycle[j] == i)
            {
                break;
            }
        }
        // cout<<i<< " "<<j<<' '<<tk<<" ";
        assert( j < cycle.size());
        
        // cout<<j<<'\n';
        // cout<<cycle[(j + tk)%cycle.size()]<<'\n';
        ans[cycle[(j + tk)%cycle.size()]] = i + 1;
    }
    for(int i = 0; i<n; i++)
    {
        cout<<ans[i]<<'\n';
    }
    // cout<<'\n';
    
}