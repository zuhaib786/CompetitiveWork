#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int main()
{
	ifstream mycin;
	mycin.open("cbarn.in");
	ofstream mycout;
	mycout.open("cbarn.out");
	int n;
	/*
	
	If we open jth door 
	Then Dist[j] = Sum _{i = 1}^{j - 1} r_i (n + i - j) + Sum _{i = j} ^n r_i (i - j)
	Rearranging we can write as 
	Dist[j] = n * (Sum_ {i = 1}^{j - 1}r_i) - j * Sum_{i = 1}^n{r_i} + Sum_{i = 1}^n{r_i *i};
	So min Dist = Sum_{i = 1}^n{r_i *i} + min_{j = 1}^n (n * (Sum_ {i = 1}^{j - 1}r_i) - j * Sum_{i = 1}^n{r_i} )


	In our algo we have sum = Sum_{i = 1}^n{r_i *i}; and S[j]  = um_{i = 1}^j r_i
	So minDist = sum + min_j n * S[j - 1]  -  j * S[n]
	 */
	mycin>>n;
	lli arr[n];
	lli sum = 0;
	for(int i = 0; i < n; i++)
	{
		mycin>>arr[i];
		sum += arr[i]*(i + 1);
	}
	lli S[n];
	lli curSum =0;
	for(int i =0 ; i< n; i ++ )
	{
		curSum += arr[i];
		S[i] = curSum;
	}
	lli minVal = LONG_MAX;
	for(int i = 1 ; i < n; i++)
	{
		minVal = min(minVal, n*S[i - 1] - (i + 1)*S[n - 1]);
	}
	mycout<< sum + minVal <<'\n';
	mycin.close();
	mycout.close();
	
}
