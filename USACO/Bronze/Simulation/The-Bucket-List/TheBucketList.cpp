#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<lli ,lli>;
int main()
{
	ifstream mycin;
	mycin.open("blist.in");
	ofstream mycout;
	mycout.open("blist.out");
	int n;
	mycin>>n;
	pii arr[2*n];
	for(int i = 0; i< n; i++)
	{
		int a,b,c;
		mycin>>a>>b>>c;
		arr[2*i] = {a, c};
		arr[2*i + 1] = {b, -c};
	}
	sort(arr, arr + 2*n);
	int tot = 0;
	int cur = 0;
	for(int i = 0; i<2*n; i++)
	{
		cur += arr[i].second;
		tot = max(tot, cur);
	}
	mycout<<tot<<'\n';
	mycin.close();
	mycout.close();


}
