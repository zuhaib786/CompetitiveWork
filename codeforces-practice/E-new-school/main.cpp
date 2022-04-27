#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using lli = long long int;
using pii = pair<lli, lli>;
using pi_n = pair< lli, pii>;
struct cmp {
	bool operator() (const pi_n& p1, const pi_n& p2) const
    {
        // {idx2, sc1, k1}, {idx2, sc2, k2};
        if( p1.second.first * p2.second.second != p1.second.second * p2.second.first)
        return p1.second.first * p2.second.second < p1.second.second * p2.second.first;
        return p1.first < p2.first;
    }
};

lli arr[200005];
// const bool cust_comp
typedef tree<pi_n, null_type, cmp, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
int arr[200005];
int sumArr[200005];
int Ks[200005];
int main()
{
    /*
    Doable:
    Idea:
    Each Bi must satsisy that the number of teachers whose age is  < Bi is <=  n - i
    i.e ord(B_i) <= n - i;
    So if the number of teachers who are greater than B_k is >=k, we have a possble solution
    Hence we find the largest remaining set in the group and assert(B_k) >= k
    We compare means as
     */
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        ordered_set s1, s2;
        for(int i = 0; i< n; i++)
        {
            int k;
            cin>>k;
            s1.insert({i, {k, 1}});
        }
        int idx = 0;
        for(int i = 0; i< m; i++)
        {
            int ki;
            cin>>ki;
            lli sum = 0;
            for(int j = 0; j< ki; j++)
            {
                cin>>arr[idx + j];
                sum += arr[idx + j];
            }
            sumArr[i] = sum;
            s2.insert({i, {sum , ki}});
            Ks[i] = ki;
            idx += ki;
        }
        int idx = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j<Ks[i]; j++)
            {
                auto it = *(s2.find({i, {sumArr[i], Ks[i] } }));
                s2.erase(it);
                s2.insert({i, { sumArr[i] - arr[idx + j], Ks[i] - 1} });
                auto temp = *(s2.rbegin());
                int index = s1.order_of_key({200007, })
            }
        }

    }
}