#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int main()
{
    ifstream mycin;
    mycin.open("shell.in");
    ofstream mycout;
    mycout.open("shell.out");
    int n;
    mycin>>n;
    int arr[3][3];
    for(int i = 0; i< 3; i++)
    {
        for(int j = 0; j< 3; j++)
        {
            arr[i][j] = 0;
        }
    }
    arr[0][0] = 1;
    arr[1][1] = 1;
    arr[2][2] = 1;
    int c1 = 0, c2 = 0,c3 = 0;
    for(int i = 0; i< n; i++)
    {
        int a, b, c;
        mycin>>a>>b>>c;
        a--, b--, c--;
        swap(arr[0][a], arr[0][b]);
        c1 += arr[0][c];
        swap(arr[1][a], arr[1][b]);
        c2 += arr[1][c];
        swap(arr[2][a], arr[2][b]);
        c3 += arr[2][c];
    }
    mycout<<max({c1, c2, c3})<<'\n';
    mycin.close();
    mycout.close();
}
