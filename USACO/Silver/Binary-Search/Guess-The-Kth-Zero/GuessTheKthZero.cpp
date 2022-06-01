#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
int main()
{
    int t, n;
    cin>>n>>t;
    while(t--)
    {
        int k;
        cin>>k;
        int left = 1;
        int right = n;
        lli ans = n;
        while(left < right)
        {
            lli mid = left + (right - left)/2;
            cout<<"? "<<left<<" "<<mid<<'\n';
            cout.flush();
            int w;
            cin>>w;
            int total = mid - left + 1;
            if(w == total - k)
            {
                right = mid;
            }
            else if (w > total - k)
            {
                int nz = total - w;
                k -= nz;
                left = mid + 1;
            }
            else
            {
                right = mid  -1 ;
            }
        }
        cout<<"! "<<left<<'\n';
        // assert(false);
        return 0;
    }

}