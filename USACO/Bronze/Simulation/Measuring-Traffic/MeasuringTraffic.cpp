#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
pii merge(pii p1, pii p2)
{
    pii p = {max(p1.first, p2.first), min(p1.second, p2.second)};
    return p;
}
struct segment
{
    int left , right;
    string type;
};

int main()
{
    ifstream mycin;
    mycin.open("traffic.in");
    ofstream mycout;
    mycout.open("traffic.out");
    int n;
    mycin>>n;
    pii cur = {INT_MIN, INT_MAX};
    segment arr[n];
    for(int i = 0; i< n; i++)
    {
        mycin>>arr[i].type>>arr[i].left>>arr[i].right;
    }
    for(int i = n -1 ; i>=0; i--)
    {
        if(arr[i].type == "none")
        {
            cur = merge(cur, {arr[i].left, arr[i].right});
        }
        else if (arr[i].type == "off")
        {
            cur.first += arr[i].left;
            cur.second += arr[i].right;
        }
        else 
        {
            cur.first = max(0ll, cur.first - arr[i].right);
            cur.second = max(0ll, cur.second - arr[i].left);
        }
    }
    mycout<<cur.first<<" "<<cur.second<<'\n';
    cur = {INT_MIN, INT_MAX};
    for(int i = 0 ; i< n; i++)
    {
        if(arr[i].type == "none")
        {
            cur = merge(cur, {arr[i].left, arr[i].right});
        }
        else if (arr[i].type == "on")
        {
            cur.first += arr[i].left;
            cur.second += arr[i].right;
        }
        else 
        {
            cur.first = max(0ll, cur.first - arr[i].right);
            cur.second = max(0ll, cur.second - arr[i].left);
        }
    }
    mycout<<cur.first<<" "<<cur.second<<'\n';
    mycin.close();
    mycout.close();
    return 0;
}