#include <bits/stdc++.h> 
using namespace std;
pair<vector<long long >, int> merge(long long * arr, int l, int r)
{
    
    if(l == r)
    {
        return {vector<long long >(1,arr[l]), 0};        
    }
    int mid = (l + r)/2;
    pair<vector<long long >, int>p1 = merge(arr, l, mid);
    pair<vector<long long >, int> p2 = merge(arr, mid + 1, r);
    
    int L = 0;
    int R = 0;
    int inversion_cnt = p1.second + p2.second;
    vector<long long >save(p1.first.size() + p2.first.size(), 0);
    while(L<p1.first.size() && R < p2.first.size())
    {
        if(p1.first[L] > p2.first[R])
        {
            auto idx = p1.first.end() - (p1.first.begin() + L, p1.first.end(), 2 * p2.first[R]);
            inversion_cnt += (p1.first.size() - L);
            save[L + R] = p2.first[R];
            R++;
        }
        else
        {
            save[L + R] = p1.first[L];
            L++;
        }
    }
    while(L<p1.first.size())
    {
        save[L + R] = p1.first[L];
        L++;
    }
    while(R < p2.first.size())
    {
        save[L + R] = p2.first[R];
        R++;
    }
    // cout<<l<<" "<<mid <<" "<<r<<" "<<inversion_cnt <<'\n';
    return {save, inversion_cnt};
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    auto p = merge(arr, 0, n - 1);
    return p.second;
    
}
int main()
{
    int n;
    cin>>n;
    long long  arr[n];
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<getInversions(arr, n)<<'\n';
}