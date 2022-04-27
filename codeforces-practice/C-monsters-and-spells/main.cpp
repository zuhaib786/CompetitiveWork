#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<int, int>;
pair<int, int> arr[2000];
bool comp(const pair<int,int>p1, const pair<int, int> p2)
{
    if(p1.first == p2.first)
    {
        return p1.second > p2.second;
    }
    return p1.first < p2.first;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        // cout<<"Case #"<<t<<endl;
        int n;
        cin>>n;
        for(int i = 0; i< n; i++)
        {
            cin>>arr[2*i].first;
        }   
        for(int i= 0; i< n; i++)
        {
            cin>>arr[2*i].second;
            arr[2*i + 1] = {arr[2*i].first - arr[2*i].second, -1};
            arr[2* i ].second = 1;
        }
        sort(arr, arr + 2 * n, comp);
        lli l = -1;
        int cnt = 0;
        lli finAns = 0;
        for(int i = 0; i< 2*n; i++)
        {
            
            if(arr[i].second == -1)
            {
                if( l == -1)
                {
                    l = arr[i].first ;   
                }
                cnt++;
            }
            else if (arr[i].second == 1)
            {
                cnt--;
            }
            // cout<<arr[i].first<<" "<<arr[i].second<<" " << l <<endl;
            if(cnt == 0)
            {
                lli length = arr[i].first - l ;
                finAns += (length *(length + 1))/2;
                l = -1;
            }
        }
        assert( l == - 1);
        cout<<finAns<<endl;
        // cout<<"Endcase\n";
    }
}