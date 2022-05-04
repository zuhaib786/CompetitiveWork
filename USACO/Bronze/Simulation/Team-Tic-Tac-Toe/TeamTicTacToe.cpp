#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
set<char>st;
set<string>dt;
char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y','Z'};
void add(set<char>totCrs)
{
	assert(totCrs.size()>= 1);
	if(totCrs.size() == 1)
	{
		char c = *totCrs.begin();
		st.insert(c);
	}
	else if (totCrs.size() == 2)
	{
		auto it = totCrs.begin();
		string s = "";
		s += *it;
		it++;
		s += *it;
		sort(s.begin(), s.end());
		dt.insert(s);
	}
}
void printSet(set<char>totCrs)
{
	for(auto x: totCrs)
	{
		cout<<x<<' ';
	}
	cout<<'\n';
}
int main()
{
	ifstream mycin;
	mycin.open("tttt.in");
	ofstream mycout;
	mycout.open("tttt.out");
	string arr[3];
	for(int i = 0; i < 3; i++)
	{
		mycin>>arr[i];
	}
	
	// rows
	for(int i = 0; i< 3; i++)
	{
		set<char>totCrs ;
		for(auto x: arr[i])
		{
			totCrs.insert(x);
		}
		add(totCrs);
	}
	//cols
	for(int j = 0; j<3; j++)
	{
		set<char>totCrs;
		for(int i = 0; i< 3; i++)
		{
			totCrs.insert(arr[i][j]);
		}
		add(totCrs);
	}
	// diag 1
	for(int i = 0; i<1; i++)
	{
		set<char>totCrs;
		for(int j = 0; j<3; j++)
		{
			totCrs.insert(arr[j][j]);
		}
		add(totCrs);
	}
	// diag2 ;
	for(int i = 0; i< 1; i++)
	{
		set<char>totCrs;
		for(int j = 0; j<3; j++)
		{
			totCrs.insert(arr[j][2 - j]);
		}
		add(totCrs);
	}
	mycout<<st.size()<<'\n';
	mycout<<dt.size()<<'\n';
	mycout.close();
	mycin.close();
}
