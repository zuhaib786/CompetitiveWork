#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int main()
{
    ifstream mycin;
    mycin.open("shuffle.in");
    ofstream mycout;
    mycout.open("shuffle.out");
	int n;
    mycin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        mycin>>arr[i];
        arr[i]--;
    }
    lli id[n];
    for(int i = 0; i< n; i++)
    {
        mycin>>id[i];
    }
    for(int i = 0; i<3 ; i++)
    {
        lli temp[n];
        for(int j = 0; j< n; j++)
        {
            temp[j] = id[arr[j] ];
        }
        for(int j = 0; j< n; j++)
        {
            id[j] = temp[j];
        }
    }
    for(int i = 0; i< n; i++)
    {
        mycout<<id[i]<<'\n';
    }
}
