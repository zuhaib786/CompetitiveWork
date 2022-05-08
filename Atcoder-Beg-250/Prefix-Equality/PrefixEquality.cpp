#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
const int maxN = 2e5 + 5;

int arr[maxN];
int brr[maxN];
int idxA[maxN];
int idxB[maxN];

int main()
{
   int n;
   cin>>n;
   for(int i = 0; i< n; i++)
   {
       cin>>arr[i];
   }
   for(int j = 0; j<n; j++)
   {
       cin>>brr[j];
   }
   map<lli, int>mb;
   for(int i = 0; i<n; i++)
   {
       if(mb.count(brr[i]))
       {
           continue;
       }
       mb[brr[i]] = i;
   }
   for(int i = 0; i < n; i++)
   {
       if(mb.count(arr[i]))
       {
           idxA[i] = mb[arr[i]];
           if(i!=0)
           {
               idxA[i] = max(idxA[i - 1], idxA[i]);
           }
       }
       else
       {
           idxA[i] = n;
       }
   }
   map<lli, int>ma;
   for(int i = 0; i<n; i++)
   {
       if(ma.count(arr[i]))
       {
           continue;
       }
       ma[arr[i]] = i;
   }
   for(int i = 0; i < n; i++)
   {
       if(ma.count(brr[i]))
       {
           idxB[i] = ma[brr[i]];
           if(i!=0)
           {
               idxB[i] = max(idxB[i - 1], idxB[i]);
           }
       }
       else
       {
           idxB[i] = n;
       }
   }
   int q;
   cin>>q;
   while(q--)
   {
       int xi, yi;
       cin>>xi>>yi;
       xi--;
       yi--;
       if(idxA[xi] <= yi && idxB[yi] <= xi)
       {
           cout<<"Yes\n";
       }
       else
       {
           cout<<"No\n";
       }
   }
   return 0;

}
