#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<int, int>;
lli f[300];
lli pref[300];
void precalc()
{
    f[1] = 0;
    pref[1] = 0;
    pref[2] = 2;
    f[2] = 2;
    // f[3] = 
    for(int i = 3; i<30; i++)
    {
        f[i] = 0;
        if(i%2 == 1)
        {
            lli t1 = 4 * (pref[(i  + 1)/2 - 1 ] - ((i + 1)/2   - 2));
            lli t2 = 2 * (f[(i + 1)/2] - 1);
            // cout<<t1<<" "<< t2 <<"\n";
            f[i] = i + 4 * (pref[(i  + 1)/2 - 1 ] - ((i + 1)/2   - 2)) + 2*( f[(i + 1)/2] - 1);
        }
        else
        {
            f[i] = 4*(pref[i/2 ] - (i/2 - 1));
        }
        pref[i] = pref[i - 1] + f[i];
    }
}
vector<pii> constructTree(lli &offset, int size, lli &numEdges)
{
    int svnumEdges = numEdges;
    int svoffset = offset;
    // cout<<"ConstructTree("<<offset<<","<<size<<","<<numEdges<<")\n";
    if(numEdges == 0)
    {
        return vector<pii>();
    }

    if(size == 1)
    {
        return vector<pii>();
    }
    else if (size == 2)
    {
        vector<pii>ans;
        ans.push_back({offset , offset + 1});
        offset++;
        // cout<<"ConstructTree("<<svoffset<<","<<size<<","<<svnumEdges<<")\n";
        // for(auto edge: ans)
        // {
        //     cout<<edge.first<<" "<<edge.second<<"\n";
        // }
        return ans;
    }
    else 
    {
        vector<pii>ans;
        int stoffset = offset;
        for(int i = 0; i<size - 1; i++)
        {
            if(numEdges == 0)
                break;
            ans.push_back({stoffset, offset  + 1});
            stoffset++;
            offset++;
            numEdges--;
            if(numEdges >=1)
            {
                ans.push_back({stoffset, offset + 1});
                offset++;
                numEdges--;
                vector<pii>temp = constructTree(offset, min(i + 1, size - 1 - i), numEdges);
                // cout<<"Printing Temp\n";
                for(auto edge:temp)
                {
                    // cout<<edge.first<<" "<<edge.second<<'\n';
                    ans.push_back(edge);
                }
            }
            // offset++;
            // numEdges--;
        }
    
        return ans;
        
    }


}
int main()
{
    int t;
    cin>>t;
    precalc();
    // for(int i = 0; i<30; i++)
    // {
    //     cout<<f[i]<<" "<<pref[i]<<'\n';
    // }
    while(t--)
    {
        lli b, w;
        cin>>b>>w;
        lli sum = b + w;
        // cout<<"Sum is "<<sum<<'\n';
        lli d = 1;
        while(true)
        {
            if(f[d] >= sum)
                break;
            d++;
        }
        // cout<<"D is "<<d<<'\n';
        int color[b + w];
        pii edges[b + w - 1];
        int j = 0;
        // d is the min diameter
        if( d%2 == 1)
        {
            if(min(b, w) < d/2)
            {
                cout<<-1<<'\n';
            }
            else
            {
                lli ed = b + w -d;
                int tot = b + w - 1;
                if( b < w)
                {
                    for(int i = 0; i<d; i++)
                    {
                        if(i%2 == 0)
                        {
                            color[i] = 1;
                            w--;
                        }
                        else
                        {
                            color[i] = 0;
                            b--;
                        }
                        if(i!=0)
                        {
                            edges[j] = {i - 1, i};
                            j++;
                        }
                    }
                    lli sv = d;
                    vector<pii> temp;
                    for(int i = 1; i<sv - 1; i++)
                    {
                        if(ed == 0)
                        break;
                        ed--;
                        temp.push_back({i, sv});
                        sv++;
                        vector<pii>k = constructTree(sv, min(i, (int)(sv - 1 - i)), ed);
                        for(auto edge: k)
                        {
                            temp.push_back(edge);
                        }
                        if(ed == 0)
                        break;
                        ed--;
                        temp.push_back({i, sv});
                        sv++;
                        k = constructTree(sv, min(i, (int)(sv - 1 - i)), ed);
                        for(auto edge: k)
                        {
                            temp.push_back(edge);
                        }
                    }
                    for(int i = 0; i< temp.size(); i++)
                    {
                        edges[d + i  - 1] = temp[i];
                    }
                    int i =0;
                    while(b!=0)
                    {
                        color[d + i] = 0;
                        b--;
                        i++;
                    }
                    while(w !=0)
                    {
                        color[d + i] = 1;
                        w--;
                    }
                    for(int i = 0; i<tot + 1; i++)
                    {
                        char c = color[i] == 0 ? 'B':'W';
                        cout<<c;
                    }
                    cout<<'\n';
                    for(int i = 0; i<tot; i++)
                    {
                        cout<<edges[i].first + 1<<" "<<edges[i].second + 1<<'\n';
                    }
                    
                }
                else
                {
                    lli ed = b + w -d;
                    int tot = b + w - 1;
                    lli sv = d;
                    swap(w, b);
                    for(int i = 0; i<d; i++)
                    {
                        if(i%2 == 0)
                        {
                            color[i] = 1;
                            w--;
                        }
                        else
                        {
                            color[i] = 0;
                            b--;
                        }
                        if(i!=0)
                        {
                            edges[j] = {i - 1, i};
                            j++;
                        }
                    }
                    
                    vector<pii> temp;
                    for(int i = 1; i<sv - 1; i++)
                    {
                        if(ed == 0)
                        break;
                        ed--;
                        temp.push_back({i, sv});
                        sv++;
                        vector<pii>k = constructTree(sv, min(i, (int)(sv - 1 - i)), ed);
                        for(auto edge: k)
                        {
                            temp.push_back(edge);
                        }
                        if(ed == 0)
                        break;
                        ed--;
                        temp.push_back({i, sv});
                        sv++;
                        k = constructTree(sv, min(i, (int)(sv - 1 - i)), ed);
                        for(auto edge: k)
                        {
                            temp.push_back(edge);
                        }
                    }
                    // cout<<"Printing temp\n";
                    // for(auto edge: temp)
                    // {
                    //     cout<<edge.first<<" "<<edge.second<<" ||| \n";
                    // }
                    for(int i = 0; i< temp.size(); i++)
                    {
                        edges[d + i - 1] = temp[i];
                    }
                    int i =0;
                    while(b!=0)
                    {
                        color[d + i] = 0;
                        b--;
                        i++;
                    }
                    while(w !=0)
                    {
                        color[d + i] = 1;
                        w--;
                    }
                    for(int i = 0; i<tot + 1; i++)
                    {
                        char c = color[i] == 0 ? 'W':'B';
                        cout<<c;
                    }
                    cout<<'\n';
                    for(int i = 0; i< tot; i++)
                    {
                        cout<<edges[i].first + 1<<" "<<edges[i].second + 1<<'\n';
                    }
                }
            }
        }
        else{
            if(min(b,w) < d/2)
            {
                cout<<-1<<'\n';
            }
            else
            {
                lli sv = d;
                lli ed = b + w -d;
                int tot = b + w - 1;
                for(int i = 0; i<d; i++)
                {
                    if(i%2 == 0)
                    {
                        color[i] = 1;
                        w--;
                    }
                    else
                    {
                        color[i] = 0;
                        b--;
                    }
                    if(i!=0)
                    {
                        edges[j] = {i - 1, i};
                        j++;
                    }
                }
                
                
                // cout<<"ed  = "<<ed<<'\n';
                vector<pii> temp;
                for(int i = 1; i < sv - 1; i++)
                {
                    if(ed == 0)
                    break;
                    ed--;
                    temp.push_back({i, sv});
                    sv++;
                    vector<pii>k = constructTree(sv, min(i, (int)(sv - 1 - i)), ed);
                    for(auto edge: k)
                    {
                        temp.push_back(edge);
                    }
                    if(ed == 0)
                    break;
                    ed--;
                    temp.push_back({i, sv});
                    sv++;
                    k = constructTree(sv, min(i, (int)(sv - 1 - i)), ed);
                    for(auto edge: k)
                    {
                        temp.push_back(edge);
                    }
                }
                for(int i = 0; i< temp.size(); i++)
                {
                    edges[d + i - 1] = temp[i];
                }
                int i =0;
                while(b!=0)
                {
                    color[d + i] = 0;
                    b--;
                    i++;
                }
                while(w !=0)
                {
                    color[d + i] = 1;
                    w--;
                }
                for(int i = 0; i<tot + 1; i++)
                {
                    char c = color[i] == 0 ? 'B':'W';
                    cout<<c;
                }
                cout<<'\n';
                for(int i = 0; i< tot ; i++)
                {
                    cout<<edges[i].first + 1<<" "<<edges[i].second + 1<<'\n';
                }
            }
        }
    }
}