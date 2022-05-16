#include<bits/stdc++.h>
using namespace std;
class RectangPrefixSum
{
    public:
    vector<vector<long long int> >prefix;
 
    RectangPrefixSum(vector<vector<long long int> > & v)
    {
        int n = v.size();
        int m = v[0].size();
        prefix = vector<vector<long long int>>(n + 1, vector<long long int> (m+1, 0));
        vector<long long int>vert(m,0);
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                vert[j]+=v[i][j];
                prefix[i+1][j+1] = prefix[i+1][j] +vert[j];
            }
        }
 
    }
 
 
 
    long long int getSum(pair<int, int> A, pair<int, int> B, pair<int, int> C, pair<int, int> D)
    {
        /*
                        A-------B
                        |       |
                        |       |
                        |       |
                        C-------D
 
 
                        
        */
       return prefix[D.first][D.second] - prefix[C.first][C.second -1 ] - prefix[B.first - 1][B.second] + prefix[A.first-1][A.second -1 ];
    }
};
int main()
{
    int n, q;
    cin>>n>>q;
    vector<vector<long long int>>vc(n, vector<long long int>(n, 0));
    for(int i = 0; i<n; i++)
    {
        string s;
        cin>>s;
        for(int j = 0; j<n; j++)
        {
            vc[i][j] = s[j] == '*';
        }
    }
    RectangPrefixSum calc(vc);
    while(q--)
    {
        pair<int, int> A, B, C, D;
        cin>>A.first>>A.second>>D.first>>D.second;
        B.first = A.first;
        B.second = D.second;
        C.first = D.first;
        C.second = A.second;
        cout<<calc.getSum(A, B, C, D)<<endl;
    }
}
