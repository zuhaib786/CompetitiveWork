    #include<bits/stdc++.h>
    using namespace std;
    using lli = long long int;
     
     
    int main()
    {
        /* https://www.hackerearth.com/challenges/competitive/april-circuits-22/algorithm/string-challenge-fbf8cc02/ */
        int t;
        cin>>t;
        while(t--)
        {
            int n,k;
            cin>>n>>k;
            string s;
            cin>>s;
            int i = 0;
            int j = 0;
            for(i = 1; i<s.size(); i++)
            {
                if(s[i] < s[j])
                {
                    j = 0;
                    continue;   
                }
                else if (s[i] == s[j])
                {
                    j++;
                }
                else
                {
                    break;
                }
            }
            i -= j;
            string temp = "";
            j =0;
            while(temp.size() < k + s.size())
            {
                temp += s[j%i];
                j++;
            }
            cout<<temp<<'\n';
        }
    }