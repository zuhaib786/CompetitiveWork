#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
const int maxN = 1e5 + 5;
lli arr[maxN];
using pii = pair<int, int>;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        sort(arr, arr + n);
        int k = (n + 1)/2;
        double mean = 0;
        if(n == 1)
        {
            cout<<arr[0]<<'\n';
        }
        else
        {
            lli sum = 0;
            for(int i = 0; i < n; i++)
            {
                sum += arr[i];
            }
            lli s2 = 0;
            double mx = sum/n;
            int cnt = n;
            for(int i = n - 1; i > 0; i--)
            {
                s2 += arr[i];
                sum -= arr[i];
                cnt--;
                double mean = 0;
                mean += s2;
                mean += ((double)sum)/cnt;
                mean /= (1 + n - cnt);
                mx = max(mean , mx);
            }
            cout<<setprecision(10)<<mx<<'\n';
        }
    }
    return 0;
}
