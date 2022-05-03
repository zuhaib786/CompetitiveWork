#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int arr[200005];
int main()
{
    int t;
    t = 1;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i = 0; i< n; i++)
        {
            cin>>arr[i];
        }
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        // break independent things
        for(int i = 0; i < n; i++)
        {
            if(min1 == arr[i])
            {
                min2 = arr[i];
            }
            else if(min1 > arr[i])
            {
                min2 = min1;
                min1 = arr[i];
            }
            else if (min2 > arr[i])
            {
                min2 = arr[i];
            }
        }
        
        
        int ans = min1/2  + min2/2 + min1%2 + min2%2;
        // cout<<min1<<" "<<min2<<" " <<ans<<endl;
        // break dependent things
        for(int i = 1; i< n - 1; i++)
        {
            int c1 = arr[i]/2 + arr[i]%2;
            if(arr[i-1] <= c1 && arr[i + 1] <= c1)
            {
                if(arr[i - 1]< arr[i + 1])
                {
                    int temp = arr[i + 1] - arr[i-1];
                    ans = min(ans, arr[i - 1] + temp/2 + temp%2);
                }
                else
                {
                    int temp = arr[i - 1] - arr[i + 1];
                    ans = min(ans, arr[i + 1] + temp/2 + temp%2);
                }
            }
            else if (arr[i - 1] <= c1)
            {
                int tans= 0;
                int itercnt = 0;
                set<int>s = {arr[i - 1], arr[i]};
                while(s.size()> 1)
                {
                    // if(itercnt >1000)
                    // break;
                    // itercnt++;
                    auto it = s.begin();
                    int v2 = *it;
                    it++;
                    int v1 =  *it;
                    // cout<<v1<<" "<<v2<<'\n';
                    s.erase(v1);
                    s.erase(v2);
                    int r = v1 - v2 + (v1 - 2*v2 != 0);
                    int tv1 = v1 - 2*r;
                    int tv2 = v2 - r;
                    // assert(tv1 >=0 && tv2>=0);
                    // cout<<v1<<" "<<v2<<" "<<tv1<<" "<<tv2<<" "<<r<<endl;
                    tans += r;
                    if(tv1>0)
                    {
                        s.insert(tv1);
                    }
                    if(tv2 > 0)
                    {
                        s.insert(tv2);
                    }

                }
                if(s.size()!=0)
                {
                    tans += (*s.begin())/2 + (*s.begin())%2;
                }
                ans = min(ans, tans);
            }
            else if (arr[i  + 1] <= c1)
            {
                int tans= 0;
                set<int>s = {arr[i + 1], arr[i]};
                int itercnt = 0;
                while(s.size()> 1)
                {
                    // if(itercnt >1000)
                    // break;
                    // itercnt++;
                    auto it = s.begin();
                    int v2 = *it;
                    it++;
                    int v1 =  *it;
                    s.erase(v1);
                    s.erase(v2);
                    int r = v1 - v2 + (v1 - 2*v2 != 0);
                    int tv1 = v1 - 2*r;
                    int tv2 = v2 - r;
                    
                    // assert(tv1 >=0 && tv2>=0);
                    tans += r;
                    if(tv1>0)
                    {
                        s.insert(tv1);
                    }
                    if(tv2>0)
                    {
                        s.insert(tv2);
                    }

                }
                if(s.size()!=0)
                {
                    tans += (*s.begin())/2 + (*s.begin())%2;
                }
                ans = min(ans, tans);
            }
            else
            {
                int tans = 0;
                // cout<<arr[i-1]<<" "<<arr[i]<<" "<<arr[i+ 1]<<'\n';
                multiset<int>s = {min(arr[i + 1], arr[i - 1]), arr[i]};
                int itercnt = 0;
                while(s.size()> 1)
                {
                    // if(itercnt >1000)
                    // break;
                    // itercnt++;
                    auto it = s.begin();
                    int v2 = *it;
                    it++;
                    int v1 =  *it;
                    s.erase(v1);
                    s.erase(v2);
                    int r = v1 - v2;
                    if( r== 0)
                        r++;
                    int tv1 = v1 - 2*r;
                    int tv2 = v2 - r;
                    // cout<<v1<<" "<<v2<<" "<<tv1<<" "<<tv2<<" "<<r<<endl;
                    // assert(tv1 >=0 && tv2>=0);
                    tans += r;
                    if(tv1>0)
                    {
                        s.insert(tv1);
                    }
                    if(tv2>0)
                    {
                        s.insert(tv2);
                    }

                }
                if(s.size()!=0)
                {
                    tans += (*s.begin())/2 + (*s.begin())%2;
                }
                ans = min(ans, tans);
            }
        }
        cout<<ans<<'\n';
    }
}
