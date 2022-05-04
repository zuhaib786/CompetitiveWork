#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
void setIO(string name = "") {

	cin.tie(0)->sync_with_stdio(0);

	if ((int) name.size()) {

		freopen((name + ".in").c_str(), "r", stdin); 

		freopen((name + ".out").c_str(), "w", stdout);

	}

}
struct entry
{
	int day; string cow; int change;
};
bool comp(const entry & m1 , const entry & m2)
{
	return m1.day == m2.day ? m1.cow < m2.cow : m1.day < m2.day;
}

int main()
{
	setIO("measurement");
	int n;
	cin>>n;
	entry measurments[n];
	for(int i = 0; i<n; i++)
	{
		cin>>measurments[i].day>>measurments[i].cow>>measurments[i].change;
	}
	string keys[3] = {"Mildred", "Elsie", "Bessie"};
	sort(measurments, measurments + n, comp);
	map<string , int>m;
	map<string, bool>winner;
	winner["Mildred"]  = true;
	winner["Elsie"] = true;
	winner["Bessie"] = true;
	int changecnt = 0;
	m["Mildred"] = 7;
	m["Elsie"] = 7;
	m["Bessie"] = 7;
	for(int i = 0; i<n; i++)
	{
		m[measurments[i].cow] += measurments[i].change;
		int mx = INT_MIN;
		for(auto x: m)
		{
			mx = max(x.second, mx);
		}
		bool changed = false;
		for(int i = 0; i<3; i++)
		{
			string s = keys[i];
			if (winner[s] != (m[s] == mx))
				changed = true;
			winner[s] = (m[s] == mx);
		}
		changecnt += changed;
		
	}
	cout<<changecnt<<'\n';
}
