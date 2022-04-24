#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
// 💖 Hi, thanks for using ICIE! 💖
// 🔧 To use a custom code template, press Ctrl+Shift+P and select "ICIE Template configure" from the list 🔧
// 📝 If you spot any bugs or miss any features, create an issue at https://github.com/pustaczek/icie/issues 📝
int arr1[200005];
int arr2[200005];
int helper[200005];
bool poss ;
int n;
map<int, pair<int , vector<int>>> m;
// void printVec(vector<int> &v)
// {
//     for(auto x: v)
//     {
//         cout<<x<<" ";
//     }
//     cout<<endl;
// }
void performIteration(int & i, int & j)
{
    // /home/zuhaib/home/zuhaib/CompetitiveWork/codeforces-global-round-20/D-cyclic-rotation/main.cpp
    
    if(i >= n || j>= n)
    {
        poss = false;
        return;
    }
    if(arr1[i] == arr2[j])
    {
        if(helper[i])
        {
            helper[i]--;
        }
        else
        {
            i++;
        }
        j++;
        return;
    }
    auto p = m[arr1[i]];
    int idx = p.first;
    // cout<<"Printing Vec\n";
    // printVec(p.second);
    // cout<<"Finished Vec\n";
    while( idx < p.second.size() && p.second[idx] <= i)
    {
        idx++;
    }
    if(idx == p.second.size())
    {
        poss = false;
        return;
    }
    else
    {
        p.first = idx;
        // cout<<"helper id  = "<<p.second[idx]<<endl;
        helper[p.second[idx]]++;        
    }
    if(helper[i])
    {
        helper[i]--;
    }
    else
    {
        i++;
    }
    performIteration(i ,  j);

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        // int n;
        m = map<int, pair<int, vector<int>>>();
        poss = true;
        cin>>n;
        memset(helper, 0, sizeof(helper));
        
        for(int i = 0; i< n; i++)
        {
            cin>>arr1[i];
            m[arr1[i]].first = 0;
            m[arr1[i]].second.push_back(i);
        }
        for(int j = 0; j< n; j++)
        {
            cin>>arr2[j];
        }
        
        int i = 0;
        // int add = 0;
        int  j = 0;
        while( i < n && j < n && poss)
        {
            performIteration(i, j);
        }
        if(i!= n || j!= n)
        {
            poss = false;
        }
        if(poss)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }


}
