#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
lli arr[200005];
lli freq[1000006];
const int block = 555;
struct node
{
    int L, R, i;
} q[200005];
lli finAns[200005];
lli ans = 0;
bool comp(const node &node1, const node &node2)
{
    int block1 = node1.L/block;
    int block2 = node2.L/block;
    return block1  == block2 ? node1.R < node2.R : block1 < block2;
}
void add(int position)
{
    position =  arr[position];
    ans -= (freq[position]*freq[position])*position;
    freq[position]++;
    ans += (freq[position]*freq[position])*position;
}
void remove(int position)
{
    position = arr[position];
    ans -= (freq[position]*freq[position])*position;
    freq[position]--;
    ans += (freq[position]*freq[position])*position;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,t;
    cin>>n>>t;
    memset(freq, 0, sizeof(freq));
    for(int i = 0 ; i < n; i++ )
    {
        cin>>arr[i];
    }
    for(int i = 0; i < t; i++)
    {
        int l, r;
        cin>>l>>r;
        l--;r--;
        q[i] = {l,r, i};
    }
    sort(q, q + t, comp);
    int currentL = 0, currentR = 0;
    for(int i = 0 ; i < t; i++)
    {
        int L = q[i].L;
        int R = q[i].R;
        while(currentL < L)
        {
            remove(currentL);
            currentL++;
        }
        while(currentL  > L)
        {
            add(currentL - 1);
            currentL--;
        }
        while(currentR <=R)
        {
            add(currentR);
            currentR++;
        }
        while(currentR > R + 1)
        {
            remove(currentR - 1);
            currentR--;
        }
        finAns[q[i].i] = ans;
    }
    for(int i = 0; i < t; i++)
    {
        cout<<finAns[i]<<'\n';
    }
    
}