#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
struct segment 
{
    lli start, type, index;
};
int main()
{
    ifstream mycin;
    mycin.open("speeding.in");
    ofstream mycout;
    mycout.open("speeding.out");
    int n,m;
    mycin>>n>>m;
    int arr[100];
    int idx = 0;
    for(int i = 0; i< n; i++)
    {
        int k;
        mycin>>k;
        int speed;
        mycin>>speed;
        for(int j = idx ; j < idx + k; j++)
        {
            arr[j] = speed;
        }
        idx += k;
    }
    lli maxExcess  = 0;
    idx = 0;
    for(int i = 0; i<m; i++)
    {
        lli k, speed;
        mycin>>k>>speed;
        for(int j = idx; j< idx + k; j++)
        {
            maxExcess = max(maxExcess, speed - arr[j]);
        }
        idx += k;

    }
    mycout<<maxExcess<<'\n';
}
