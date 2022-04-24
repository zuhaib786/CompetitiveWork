#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
// 💖 Hi, thanks for using ICIE! 💖
// 🔧 To use a custom code template, press Ctrl+Shift+P and select "ICIE Template configure" from the list 🔧
// 📝 If you spot any bugs or miss any features, create an issue at https://github.com/pustaczek/icie/issues 📝
int arr[200005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        if(s[s.size() - 1]!='B')
        {
            cout<<"NO\n";
            continue;
        }
        int aCnt = 0, bCnt = 0;
        bool poss = true;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'A')
            {
                aCnt++;
            }
            else
            {
                bCnt++;
            }
            if(aCnt < bCnt)
            {
                poss = false;
                break;
            }
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
    return 0;


}
