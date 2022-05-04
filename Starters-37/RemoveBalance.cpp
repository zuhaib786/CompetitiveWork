#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
const int maxN = 1e5 + 5;
lli arr[maxN];
using pii = pair<int, int>;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        // cout<<s<<'\n';
        stack<int>st;
        vector<pii>v;
        // bool underDeletion = false;
        int cnt = 0;
        int size = 0;
        int left = -1;
        int arr[s.size()];
        for(int i = 0; i< s.size(); i++)
            arr[i] = -1;
        for(int i = 0; i<s.size(); i++)
        {
            // cout<<s[i]<<" ";
            if(s[i] == '(')
            {
                st.push(i);
                // left = i;
            }
            else if (s[i] == ')')
            {
                if(!st.empty())
                {
                    size += 2;
                    arr[st.top()] = i + 1;
                    st.pop();
                }
                else
                {
                    arr[i] = -1;
                }
            }
            // if(!st.empty())
            // cout<<st.top()<<'\n';
        }
        int cur = 0;
        bool tba = 0;
        cnt = 0;
        for(int i = 0; i<s.size(); )
        {
            if(arr[i] != -1)
            {
                tba = true;
                i = arr[i];
            }
            else 
            {
                if(tba)
                {
                    cnt++;
                    tba = false;
                }
                i++;
            }
        }
        if(tba)
            cnt++;
        cout<<s.size() - size<<" "<<cnt<<'\n';
    }
    return 0;
}

