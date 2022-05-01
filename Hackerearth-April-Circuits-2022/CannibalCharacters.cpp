    #include<bits/stdc++.h>
    using namespace std;
    using lli = long long int;
     
     
    int main()
    {
        /* https://www.hackerearth.com/challenges/competitive/april-circuits-22/algorithm/cannibal-characters-d30e8a5f/ */
        int t;
        cin>>t;
        while(t--)
        {
            int n;
            cin>>n;
            string s;
            cin>>s;
            map<char, int>m;
            for(int i = 0; i< n; i++)
            {
                m[s[i]]++;
            }
            int cost = 0;
            // int legth = n;
            for(auto x: m)
            {
                cost += x.second/2;
                // length -= x.second - 1;
            }
            cout<<cost<<endl;
        }
    }