#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using vc = vector<lli>;

#define ff first
#define ss second
#define FOR(i, n) for(int i = 0; i<n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0; i--)

const int maxN = 2e5 + 5;
lli arr[maxN];
struct frac{
    lli num; lli den;
    void reduce()
    {
        lli gc = __gcd(num,den);
        num = num/gc;
        den = den/gc;
    }
    bool operator < (frac const & f)
    {
        return this->num * f.den < this->den * f.num;
    }
};

lli ps[maxN];
frac find(lli mid, int n)
{
    // frac f = {INT_MAX, 1};
    lli mx = 0;
    for(int i = 1; i< n - mid; i++)
    {
        lli sum = ps[i + mid] - ps[i];
        mx = max(sum , mx);
    }
    return {ps[n] - mx, mid};

}
int Poss(lli mid, int n)
{
    frac f1 = find(mid, n);
    if(mid < n - 3)
    {
        frac f2 = find(mid + 1 , n);
        if(f1 < f2)
        {
            return 1;
        }
    }
    if(mid > 2)
    {
        frac f2 = find(mid - 1 , n);
        if(f1 < f2)
        {
            return - 1;
        }
    }
    return 0;
}
int main()
{
    lli n;
    cin>>n;
    FOR(i, n)
    {
        cin>>arr[i];
    }

    lli left = 1;
    lli right = n - 2;
    memset(ps, 0, sizeof(ps));
    FOR(i, n)
    {
        ps[i + 1] = ps[i] + arr[i];
    }
    frac ans = {INT_MAX, 1};
    while (left <= right)
    {
        lli mid = left + (left - right)/2;
        int dir = Poss(mid, n);
        if(dir == 0)
        {
            frac f = find(mid, n);
            cout<<setprecision(6)<<(double)(f.num)/((double)f.den)<<'\n';
            break;
        }
        else if (dir > 0)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }


}