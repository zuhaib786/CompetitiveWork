#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

int getYear(int curYear, int relation, int birthYear)
{
    if(relation == -1)
    {
        curYear--;
        while((curYear%12 + 12)%12 != birthYear)
        {
            curYear--;
        }
        return curYear;
    }
    curYear++;
    while((curYear%12 + 12)%12 != birthYear)
    {
        curYear ++;
    }
    return curYear;
}
int main()
{
    // The last word is the name of a cow on the farm, which is either "Bessie" or a cow that has already been mentioned in a previous line of input.
    // call bessie 0 .
    int n;
    cin>>n;
    string year[12] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
    map<string, int>yearMap;
    for(int i = 0; i<12; i++)
    {
        yearMap[year[i]]  = i ;
    }
    int ans = 0;
    map<string , int> m;
    m["Bessie"] = 0;
    for(int i = 0; i<n; i++)
    {
        // Mildred born in previous Dragon year from Bessie
        string s1,  s2, s3, s4,      s5,    s6,  s7,  s8;
        cin>>s1>>s2>>s3>>s4>>s5>>s6>>s7>>s8;
        // cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<" "<<s5<<" "<<s6<<" "<<s7<<" "<<s8<<'\n';
        if(s4 == "previous")
        {
            m[s1] = getYear(m[s8], - 1, yearMap[s5]);
        }
        else
        {
            m[s1] = getYear(m[s8], 1, yearMap[s5]);
        }
        // cout<<s1<<" " <<m[s1]<<'\n';
    }
    cout<<abs(m["Elsie"])<<'\n';
}