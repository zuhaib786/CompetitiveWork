#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
lli getMax(vector<int>A, int jumps)
{
    if(A.size() == 1)
    {
        return A[0];
    }
    int even[A.size()/2];
    int odd[A.size()/2 + A.size()%2];
    int i = 0;
    int j = 0;
    int id = 1;
    for(int k= 0; k<A.size(); k++)
    {
        if(id == 1)
        {
            odd[j] = A[k];
            j++;
        }
        else
        {
            even[i] = A[k];
            i++;
        }
        id ^= 1;
    }
    sort(even, even + A.size()/2);
    sort(odd, odd + A.size()/2 + A.size()%2);
    i  = A.size()/2 - 1;
    j = A.size()/2 + A.size()%2 -1;
    // start with even jumper;
    lli ans = 0;
    lli finans = 0;
    int cnt  = 0;
    id =0;
    while(i>=0 && j>=0 && cnt < jumps)
    {
        if(id == 0)
        {
            ans += even[i];
            i++;
        }
        else
        {
            ans += odd[j];
            j++;
        }
        id ^= 1;
        cnt++;
    }
    finans  = ans;
    //start with odd;
    i  = A.size()/2 - 1;
    j = A.size()/2 + A.size()%2 -1;
    int cnt  = 0;
    id = 1;
    lli ans = 0;
    while(i>=0 && j>=0 && cnt < jumps)
    {
        if(id == 0)
        {
            ans += even[i];
            i++;
        }
        else
        {
            ans += odd[j];
            j++;
        }
        id ^= 1;
        cnt++;
    }
    finans = max(ans, finans);
    return finans;

}