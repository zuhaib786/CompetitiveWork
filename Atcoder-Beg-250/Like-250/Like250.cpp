#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
const int maxN = 1e6 + 6;
int arr[maxN];
int karr[maxN];
lli cube(lli n)
{
    lli left = 1;
    lli right = maxN;
    lli ans = 0;
    while(left <= right)
    {
        lli mid = (left + right)/2;
        if((mid * mid)*mid <= n)
        {
            ans = mid;
            left = mid+1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}
void precalc()
{
    // memset(arr, 1,sizeof(arr));
    for(int i = 2; i<maxN; i++)
    {
        arr[i] = 1;
    }
    arr[2] = 1;
    arr[1] = 0;
    arr[0] = 0;
    for(int i = 2; i< maxN; i++)
    {
        if(arr[i] == 0)
            continue;
        for(int j = 2; j*i < maxN; j++)
        {
            arr[j*i] = 0;
        }
    }
    karr[0] = 0;
    for(int i = 1; i<maxN; i++)
    {
        karr[i] = karr[i-1] + arr[i];
    }
}

int main()
{
    lli n;
    cin>>n;
    precalc();
    lli k = cube(n);
    lli cnt = 0;
    for(lli j = 2; j<=k; j++)
    {
        if(arr[j] == 1)
        {
            lli idx = min(j - 1, n/(j*j*j));
            cnt += karr[idx];
        }
    }
    cout<<cnt<<'\n';
}

