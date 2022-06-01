#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;

#define ff first
#define ss second
#define FOR(i, n) for(int i = 0; i < n; i++)
#define ROF(i, n) for(int i = n - 1; i >= 0; i-- )

const int maxN = 2e5 + 5;
pii add(pii a, pii b)
{
    return {a.ff + b.ff , a.ss + b.ss};
}
pii arr[maxN];
pii ps[maxN];
lli manhat(pii a, pii b)
{
    return abs(a.ff - b.ff) + abs(a.ss - b.ss);
}
bool Poss(lli mid, lli n, pii start, pii end)
{
    lli cycles = mid/n;
    pii last = ps[n];
    last.ff = last.ff * cycles;
    last.ss = last.ss * cycles;
    pii sum = ps[mid % n ];
    last = add(last, sum);
    last = add(last, start);
    // cout<<mid<<" "<<last.ff<<" "<<last.ss<<'\n';
    return manhat(last, end) <= mid;
}
int main()
{
    pii start;
    cin>>start.ff >> start.ss;
    pii end;
    cin>>end.ff >> end.ss;
    int n;
    cin>>n;
    string s;
    cin>>s;
    FOR(i, n)
    {
        if(s[i] == 'U')
        {
            arr[i] = {0, 1};
        }
        else if (s[i] == 'D')
        {
            arr[i] = {0, - 1};
        }
        else if (s[i] == 'L')
        {
            arr[i] = {-1, 0};
        }
        else
        {
            arr[i] = {1,0};
        }
        
    }
    ps[0] = {0, 0};
    FOR(i, n)
    {
        ps[i + 1] = add(ps[i], arr[i]);
    }
    // FOR(i, n + 1)
    // {
    //     cout<<ps[i].ff <<" "<<ps[i].ss<<'\n';
    // }
    lli left = 0;
    lli right = 2e14 + 4;
    // lli right = 4;
    lli ans = right;
    while(left <= right)
    {
        lli mid = left + (right - left )/2;
        if(Poss(mid, n, start, end))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    if(ans == 2e14 + 4)
    {
        cout<<-1<<'\n';
    }
    else
    {
        cout<<ans<<'\n';
    }

}