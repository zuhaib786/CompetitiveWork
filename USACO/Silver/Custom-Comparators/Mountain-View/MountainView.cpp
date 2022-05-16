#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
const int maxN = 1e5 + 5;
pii arr[2*maxN];
pii peaks[maxN];
void setIO(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
bool comp(const pii & p1, const pii & p2)
{
    if(p1.first == p2.first)
    {
        if(p1.second < 0 && p2.second < 0)
        {
            int idx1 = abs(p1.second) - 1;
            int idx2 = abs(p2.second) - 1;
            return peaks[idx1].first > peaks[idx2].first;
        }
        return p1< p2;
    }
    return p1 < p2;
}
// idea is that mountain with peak (x1, y1) will contain peaks (x2, y2) if [x2 - y2, x2 + y2] range lies completely withing range [x1 - y1, x1 + y1].
// The comverted problem , I had done in CSES viz Nested ranges check. 
int main()
{
    setIO("mountains");

    int n;
    cin>>n;
    for(int i = 0; i< n; i++)
    {
        lli x, y;
        cin>>x>>y;
        arr[2*i].first = x - y;
        arr[2*i].second = i + 1;
        arr[2*i + 1].first = x + y;
        arr[2*i + 1].second = -(i + 1);
        peaks[i] = {x - y,x + y};
    }
    sort(arr, arr + 2*n, comp);
    multiset<lli>s;
    int cnt = 0;
    for(int i = 0; i < 2*n; i++)
    {
        if(arr[i].second > 0)
        {
            s.insert( - arr[i].first);
        }
        else
        {
            int idx = abs(arr[i].second) - 1;
            s.erase( s.find(- peaks[idx].first));
            if(s.size() == 0)
            {
                cnt++;
                continue;
            }
            auto it = s.end();
            it--;
            if(*it >= -peaks[idx].first )
                continue;
            else
            {
                cnt++;
            }

        }
    }
    cout<<cnt<<'\n';
}
