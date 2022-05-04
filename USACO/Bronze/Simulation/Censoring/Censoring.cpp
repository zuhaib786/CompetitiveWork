#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
void solve(string & s, string & t)
{
	string buffer = "";
	for(int i = 0; i<s.size(); i++)
	{
		buffer += s[i];
		if(buffer.size() >= t.size() && buffer.substr(buffer.size() - t.size()) == t) 
		{
			buffer.resize(buffer.size() - t.size());
		}
	}
	s = buffer;
	return;
}
void setIO(string name = "") {

	cin.tie(0)->sync_with_stdio(0);

	if ((int) name.size()) {

		freopen((name + ".in").c_str(), "r", stdin); 

		freopen((name + ".out").c_str(), "w", stdout);

	}

}
int main()
{
	setIO("censor");
	string s;
	cin>>s;
	string t;
	cin>>t;
	solve(s, t);
	cout<<s<<'\n';
}
