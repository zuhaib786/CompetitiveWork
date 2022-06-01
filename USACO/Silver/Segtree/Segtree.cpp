#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
#define all(x) begin(x), end(x)
#define ff first
#define ss second
const int maxN = 2e5 + 5;// change accordingly
const lli emptyOP = INT_MIN; // --> identity w.r.t oP;
lli t[4*maxN];
lli op(lli a , lli b)// set your operation
{
    return max(a, b);// i have set it to be maximum
}
void build(lli a[], lli v, lli tl, lli tr)
{
    // Build the segtree from initial array.
    // Call with v = 1, tl = 0, tr = n -1 .
    if(tl == tr)
    {
        t[v] = a[tl];
    }
    else
    {
        lli tm = (tl + tr)/2;
        build(a, 2*v, tl, tm);
        build(a, 2*v + 1, tm + 1, tr);
        t[v] = op(t[2*v], t[2*v + 1]);
    }
}
lli getRangeOp(lli v, lli tl, lli tr,lli l, lli r)
{
    // call with v = 1, tl = 0, tr = n - 1 and  desired l and r
    if(l > r)
    {
        return emptyOP;
    }
    if(l == tl && r == tr)
    {
        // cout<<l<<" "<<r<<" "<<t[v]<<'\n';
        return t[v];
    }
    lli tm = (tl + tr)/2;
    return op(getRangeOp(2*v, tl, tm , l, min(r, tm)), getRangeOp(2*v + 1, tm + 1, tr, max(l, tm + 1), r));
}
void update(lli v, lli tl, lli tr, lli pos, lli new_val)
{
    // call with v = 1, tl = 0, tr = n - 1, pos and new val  of desired setting.
    if(tl == tr)
    {
        t[v] = new_val;
    }
    else
    {
        lli tm = (tl + tr)/2;
        if(pos<=tm)
        {
            update(2*v, tl, tm , pos, new_val);
        }
        else
        {
            update(2*v + 1, tm + 1, tr, pos, new_val);
        }
        t[v] = op(t[2*v + 1], t[2*v]);
    }
}