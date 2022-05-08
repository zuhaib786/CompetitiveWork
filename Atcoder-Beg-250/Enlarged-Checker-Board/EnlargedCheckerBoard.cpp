#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int main()
{
    int n, a, b;
    cin>>n>>a>>b;
    int col =1;
    for(int r = 0; r<n; r++)
    {
        int curcol = col;
        string s = "";
        for(int k = 0; k<n; k++)
        {
            for(int w = 0; w< b; w++)
            {
                if(curcol == 1)
                {
                    s += '.';
                }
                else
                {
                    s += '#';
                }
            }
            curcol^=1;
        }
        for(int w = 0; w<a; w++)
        {
            cout<<s<<'\n';
        }
        col ^= 1;
    }
}

