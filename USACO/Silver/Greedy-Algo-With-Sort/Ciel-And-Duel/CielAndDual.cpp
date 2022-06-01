#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
#define ff first
#define ss second
#define FOR(i, n) for(int i = 0; i<n; i++)
#define ROF(i, n) for(int i = n - 1; i>=0; i--)

const int maxN = 105;
int att[maxN];
int def[maxN];
int c[maxN];
bool Poss(int k, int j2)
{
    int l1 = k - 1;
    int l2 = j2 - 1;
    FOR(i , k)
    {
        if(att[l1] > c[l2])
        return false;
        l1--;
        l2--;
    }
    return true;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int j1 = 0;
    int j2 = 0;
    FOR(i, n)
    {
        string s; int k;
        cin>>s>>k;
        if(s == "ATK")
        {
            att[j1] = k;
            j1++;
        }
        else
        {
            def[j2] = k;
            j2++;
        }
    }
    FOR(i, m)
    {
        cin>>c[i];
    }
    // only defeating the top seeds.
    sort(c,c + m , greater<lli>());
    sort(att, att + j1);
    lli psc[m + 1];
    memset(psc, 0, sizeof(psc));
    lli psatt[j1 + 1];
    memset(psatt, 0, sizeof(psatt));
    lli sc1 = 0;  
    int sm1 = 0;
    lli sm2 = 0;
    FOR(i, min(j1, m))
    {
        sm1 += att[i];
        sm2 += c[i];
        sc1 = max(sc1, sm2 - sm1);
    }
    //sc1 draav;
    // wun kruv kaem wun harnaavhukh saeri
    multiset<lli>s;
    FOR(i, m)
    {
        s.insert(c[i]);
    }
    lli poss = true;
    FOR(i, j2)
    {
        auto it = s.upper_bound(def[i]);
        if(it == s.end())
        {
            poss = false;
            break;
        }
        else
        {
            s.erase(s.find(*it));
        }
    }
    multiset<lli>save = s;
    FOR(i,j1)
    {
        auto it = s.lower_bound(att[i]);
        if(it == s.end())
        {
            poss= false;
            break;
        }
        else
        {
            s.erase(s.find(*it));
        }
    }
    if(poss)
    {
        lli sc2 = 0;
        int cnt =0;
        while(cnt < j1)
        {
            // sc2 += *save.rbegin();
            // save.erase(save.find(*s.rbegin()));
            sc2 -= att[cnt];
            cnt++;
        }
        for(auto it = save.begin(); it !=save.end(); it++)
        {
            sc2 += *it;
        }
        
        cout<<max(sc1, sc2)<<'\n';
    }
    else
    {
        cout<<sc1<<'\n';
    }


}