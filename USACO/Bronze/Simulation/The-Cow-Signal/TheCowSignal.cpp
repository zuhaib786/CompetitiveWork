#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int main()
{
    ifstream mycin;
    mycin.open("cowsignal.in");
    ofstream mycout;
    mycout.open("cowsignal.out");
    int n, m, p;
    mycin>>n>>m>>p;
    string arr[n];
    for(int i = 0; i< n; i++)
    {
        mycin>>arr[i];
    }
    string newArr[p*n];
    for(int i =0; i<n;i++)
    {
        string s = "";
        for(int j = 0; j< m; j++)
        {
            for(int t = 0; t<p; t++)
            {
                s += arr[i][j];
            }
        }
        for(int j = 0; j<p; j++)
        {
            newArr[i * p + j] = s;
        }
    }
    for(int i = 0; i<p*n; i++)
    {
        mycout<<newArr[i]<<'\n';
    }
    return 0;
}
