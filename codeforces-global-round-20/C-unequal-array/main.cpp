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
        int n;
        cin>>n;
        for(int i = 0; i< n; i++)
        {
            cin>>arr[i];
        }
        int leftMost = INT_MAX;
        int rightMost = -1;
        for(int i = 0; i< n - 1; i++)
        {
            if(arr[i] == arr[i+1])
            {
                leftMost = min(leftMost, i);
                rightMost = max(rightMost , i);
            }
        }

        if(leftMost == rightMost || leftMost == INT_MAX)
        {
            cout<<0<<'\n';
        }
        else
        {
            //leftMost + 1->rightMost
            cout<<max(1, rightMost - leftMost - 1) <<endl;
        }
    }


}
