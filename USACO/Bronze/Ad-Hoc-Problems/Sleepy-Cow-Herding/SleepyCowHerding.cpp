#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
void setIO(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
int main()
{
    setIO("herding");
    lli arr[3];
    for(int i = 0; i< 3; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr + 3);
    if(arr[1] == arr[0] + 1 || arr[2] == arr[1] + 1)
    {
        int gap = arr[2] - arr[0];
        if(gap == 2)
        {
            cout<<0<<'\n'<<0<<'\n';
        }
        else
        {
            // a  a + 1  a + 3 -> a + 1 a + 3 - 1 a + 3
            // a a + 1 a + gap -> a + 1 a + gap - 2 a+ gap -> a+ gap - 2 a + gap - 1 a+ gap
            cout<<min(gap-2 , 2)<<'\n';
            // a  a+1  a+ gap -> a+ 1 a+ 2 a+ gap  -> a+ 2 a+ 3 a+ gap -----
            cout<<gap - 2<<'\n';
        }
    }
    else
    {
        // a  a+ gap1  a+ gap1 + gap2
        // For min a + gap1 a + gap1 + 2 a + gap1 + gap2 (if gap2  > 2)-> a + gap1 a + gap1 + 1 a+ gap1 + 2
        // Else Order 1 mai ho jayay ga.
        // Symmetry argument XDDDD
        int gap1 = arr[1] - arr[0];
        int gap2 = arr[2] - arr[1];
        int mn = min(2, gap1 - 1);
        mn = min(mn, gap2 - 1);
        cout<<mn<<'\n';
        // For max
        // a  a+ gap1 a + gap2  -> a + gap1  a+ gap1 + 1 a+ gap2 -> a+ gap1 + 1  a+ gap1 + 2 a+ gap2 ->--- a +  gap1 + gap2 -2  a+ gap1 + gap2 - 1 a+ gap1 + gap2
        // Total steps gap2 - 1;
        // If i bring otw total steps = gap1 - 1;
        cout<<max(gap1 - 1, gap2 - 1)<<'\n';
    }

}