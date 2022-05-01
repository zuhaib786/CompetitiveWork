    #include<bits/stdc++.h>
    using namespace std;
     
    int minUpdates (int N, vector<int> A, int K) {
        /* https://www.hackerearth.com/challenges/competitive/april-circuits-22/algorithm/update-the-array-3fcbf307/ */
       if(N%2 !=0)
       return -1;
       map<int, int>m;
       int rem[2];
       rem[0] = 0;
       rem[1] = 0;
       for(int i = 0; i< A.size(); i++)
       {
           m[A[i]]++;
           rem[A[i]%2 ]++;
       }
       int evenAvail = K/2;
       int oddAvail = K/2 + (K%2);
       int totOPs = 0;
       int temp = K;
       for(auto x: m)
       {
           if(x.first <=K && x.first > 0)
           {
               if(x.first %2 == 0)
               {
                   evenAvail--;
               }
               else
               {
                   oddAvail--;
               }
           }
           totOPs += x.second -1;
           int xd = min(abs(rem[0] - rem[1])/2 , x.second - 1);
           if(rem[0] > rem[1] && x.first%2 == 1 || rem[0] < rem[1] && x.first%2 == 0)
            xd = 0;
           if(rem[0] > rem[1])
           {
               rem[0] -= xd;
               rem[1] += xd;
               if(x.first%2 == 0)
               {
                   oddAvail -= xd;
                   evenAvail -= x.second -1 -xd;
               }
               else
               {
                   oddAvail -= x.second - 1;
               }
           }
           else if(rem[0] < rem[1])
           {
               rem[1] -= xd;
               rem[0] +=xd;
               if(x.first%2 == 1)
               {
                   evenAvail -= xd;
                   oddAvail -= x.second -1 -xd;
               }
               else
               {
                   evenAvail -= x.second - 1;
               }
           }
           else
           {
               if(x.first %2 == 0)
               {
                   evenAvail -= x.second - 1;
               }
               else
               {
                   oddAvail -= x.second - 1;
               }
           }
       }
       if(rem[0]!= rem[1])
       {
           if(rem[0] > rem[1])
           {
               oddAvail -= (rem[0] - rem[1])/2;
           }
           else
           {
               evenAvail -= (rem[1] - rem[0])/2;
           }
           totOPs += abs(rem[0] - rem[1])/2;
       }
       return (evenAvail >=0) &&(oddAvail >=0) ? totOPs : - 1;
       
    }
     
    int main() {
     
        ios::sync_with_stdio(0);
        cin.tie(0);
        int T;
        cin >> T;
        for(int t_i = 0; t_i < T; t_i++)
        {
            int N;
            cin >> N;
            vector<int> A(N);
            for(int i_A = 0; i_A < N; i_A++)
            {
            	cin >> A[i_A];
            }
            int K;
            cin >> K;
     
            int out_;
            out_ = minUpdates(N, A, K);
            cout << out_;
            cout << "\n";
        }
    }