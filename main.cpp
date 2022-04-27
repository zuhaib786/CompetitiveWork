#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<int, int>;
const lli maxN = 2e5 + 5;
lli controls[maxN];
lli arr[maxN];
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<pii>adj[n];
    // memset(index, 0, sizeof(index));
    for(int i = 0; i< n; i++)
    {
        cin>>controls[i];
    }
    for(int i = 0; i< n-1; i++)
    {
        cin>>arr[i];
    }
    for(int i = 0; i< n; i++)
    {
        int pi = arr[i];
        pi--;
        int wt;
        cin>>wt;
        adj[pi].push_back({i + 1, wt});
    }
        



}