#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
void setIO(string name = "")
{
    cin.tie(0)->sync_with_stdio(0);
	if(name.size() == 0)
		return;
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}
int main()
{
	setIO("cownomics");
	int n,m;
	cin>>n>>m;
	string spotted[n];
	string plain[n];
	for(int i = 0; i<n; i++)
	{
		cin>>spotted[i];
	}
	for(int i = 0; i<n; i++)
	{
		cin>>plain[i];
	}
	int cnt = 0;
	for(int j1 = 0; j1<m; j1++)
	{
		for(int j2 = j1 + 1; j2 < m; j2++)
        {
            for(int j3 = j2 + 1; j3<m; j3++)
            {
                unordered_set<string>ss;
                for(int i = 0; i<n; i++)
                {
                    string s = "";
                    s += spotted[i][j1];
                    s += spotted[i][j2];
                    s += spotted[i][j3];
                    ss.insert(s);
                }
                bool b = true;
                set<string>sp;
                for(int i =0 ; i <n; i++)
                {
                    string s = "";
                    s += plain[i][j1];
                    s += plain[i][j2];
                    s += plain[i][j3];
                    if(ss.find(s)!=ss.end())
                    {
                        b = false;
                        break;
                    }
                }
                
                
                cnt += b;
            }
        }
	}
	cout<<cnt<<'\n';

}