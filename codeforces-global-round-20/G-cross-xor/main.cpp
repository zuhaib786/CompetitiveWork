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
        lli x ;
        cin>>n>>x;
        for(int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        sort(arr, arr + n);
        lli cnt = 0;
        lli sum = 0;
        for(int i = 0; i < n ; i++)
        {
            if(sum + arr[i] <= x)
            {
                sum += arr[i];
                cnt++;
            }
        }
        lli tot = 0;
        int iterCnt = 0;
        int iter = 0;
        while(cnt > 0)
        {
            lli diff = x - sum;
            tot += (diff/cnt + 1)*cnt;
            iter += diff/cnt + 1;
            sum = sum + (diff/cnt + 1)*cnt;
            while(cnt > 0 && sum > x)
            {
                cnt--;
                sum -= arr[cnt] + iter ;
            }
            assert(iterCnt < 100000);
        }
        cout<<tot<<endl;

    }


}
