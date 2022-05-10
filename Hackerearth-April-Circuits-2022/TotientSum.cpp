    #include<bits/stdc++.h>
    using namespace std;
    using lli = long long int;
    const lli mod = 1e9 + 7;
    const int maxN = 1e5 + 5;
    lli phi[maxN];
    lli pd[maxN];
    lli ps[maxN];
    lli F[maxN];
    /*https://www.hackerearth.com/practice/math/number-theory/totient-function/practice-problems/algorithm/totient-sum-10be760f/ */
    void precalc()
    {
        pd[1] = 1;
        for(int i = 2; i < maxN; i++)
        {
            pd[i] = i;
        }
        for(int i = 2; i<maxN; i++)
        {
            if(pd[i] == i)
            {
                for(int j = 2; j*i<maxN; j++)
                {
                    pd[j*i] = i;
                }
            }
        }
        phi[1] = 1;
        for(int i = 2; i< maxN; i++)
        {
            if(pd[i] == i)
            {
                phi[i] = i-1;
            }
            else
            {
                int prime = pd[i];
                int w = i;
                int k = 0;
                int mul = 1;
                while(w%prime == 0)
                {
                    w/=prime;
                    k++;
                    mul*=prime;
                }
                phi[i] = phi[w]*(mul - mul/prime);
            }
        }
        ps[1] = 1;
        ps[1] = 1;
        for(int i = 2; i<maxN; i++)
        {
            ps[i] = ps[i-1] + phi[i];
            ps[i] %= mod;
        }
        F[0] = 0;
        F[1] = 1;
        for(int i = 2; i< maxN; i++)
        {
            F[i] = F[i-1] + phi[i]*ps[i];
            F[i]%=mod; 
        }
    }
    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        precalc();
        int t;
        cin>>t;
     
        while(t--)
        {
            int n;
            cin>>n;
            cout<<F[n]<<'\n';
        }
    }
