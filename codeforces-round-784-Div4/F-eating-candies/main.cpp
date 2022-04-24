#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int arr[200005];
lli lt[200005];
lli rt[200005];
int main()
{
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
        lt[0] = arr[0];
        for(int i = 1; i< n; i++)
        {
            lt[i] = lt[i-1] + arr[i];
        }
        rt[n-1] = arr[n-1];
        for(int i = n-2; i>=0; i--)
        {
            rt[i] = arr[i] + rt[i+1];
        }
        int i  = 0, j = n - 1;
        int tot = 0;
        while (i < n && j>=0 && i<j)
        {
            if(lt[i] == rt[j])
            {
                tot =  i + 1 + n - j;
                i++;
                j--;
            }
            else if (lt[i] < rt[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        cout<<tot<<endl;
    }
    return 0;
}