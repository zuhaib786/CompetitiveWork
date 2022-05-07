#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<int, int>;
void setIO(string name = "")
{
    if(name.size() == 0)
        return;
    cin.tie(0)->sync_with_stdio(0);
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
bool btw(int x1, int y1, int z)
{
    return (x1 <=z ) &&( z<=y1);
}
bool intersect(pii p1, pii p2)
{
    return (btw(p1.first, p1.second, p2.first) && !btw(p1.first, p1.second, p2.second)) ||(btw(p2.first, p2.second, p1.first) && !btw(p2.first, p2.second, p1.second));
}
int main()
{
    setIO("circlecross");
    string s;
    cin>>s;
    vector<pii>arr(26, {-1, -1});
    for(int i = 0; i<s.size(); i++)
    {
        int id = s[i] - 'A';
        if(arr[id].first == -1)
        {
            arr[id].first = i;
        }
        else
        {
            arr[id].second = i;
        }
    }
    int cnt = 0;
    for(int i = 0; i<26; i++)
    {
        for(int j = i + 1; j<26; j++)
        {
            cnt += intersect(arr[i], arr[j]);
        }
    }
    cout<<cnt<<'\n';
}