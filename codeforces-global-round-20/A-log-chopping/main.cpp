#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
// 💖 Hi, thanks for using ICIE! 💖
// 🔧 To use a custom code template, press Ctrl+Shift+P and select "ICIE Template configure" from the list 🔧
// 📝 If you spot any bugs or miss any features, create an issue at https://github.com/pustaczek/icie/issues 📝
// int arr[200005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        lli sum = 0;
        for(int i = 0; i < n; i++)
        {
            int k;
            cin>>k;
            sum += k-1;
        }
        if( sum %2 == 0)
        {
            cout<<"maomao90\n";
        }
        else
        {
            cout<<"errorgorn\n";
        }
    }
    return 0;


}
