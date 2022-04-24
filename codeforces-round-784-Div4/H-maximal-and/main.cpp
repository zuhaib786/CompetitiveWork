#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        map<int, int>bitPos;
        for(int i = 0; i< n; i++)
        {
            int temp;
            cin>>temp;
            for(int i = 0; i< 31; i++)
            {
                if(temp & (1<<i))
                {
                    continue;
                }
                else
                {
                    bitPos[i]++;
                }
            }
        }   
        int finAns = 0;
        for(int i = 30; i >=0 ; i-- )
        {
            if(bitPos[i] <= k)
            {
                k -= bitPos[i];
                finAns  += (1<<i);
            }
        }
        cout<<finAns<<endl;
    }

    return 0;
}