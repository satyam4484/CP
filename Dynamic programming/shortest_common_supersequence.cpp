#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// shortest common supersequence 
#define    pb    push_back
#define    ll    long long int 

#define  inpv(v,n)  for(int i=0;i<n;i++) cin>>v[i]
#define  outv(v)    for(auto i:v) cout<<i<<' ' 

// function to find the  SUSP
int find_common(string s1,string s2) {
    vector<vector<int>>ans(s1.size()+1,vector<int>(s2.size()+1,0));
    
    for(int i=1;i<= s1.size();i++) {
        for(int j=1;j<= s2.size(); j++) {
            if(s1[i-1] == s2[j-1] ) {
                ans[i][j] = 1+ ans[i-1][j-1];
            }
            else {
                ans[i][j]= max(ans[i-1][j], ans[i][j-1]);
            }
        }
    }

    // the common values will be at the last value 
    int lcs=ans[s1.size()][s2.size()];

    // subtract the value of total size minus the commmon values 
    return (s1.size()+s2.size()-lcs);
} 

int main()
{
    string s1="geek";
    string s2="eke";
    cout<<find_common(s1,s2);
    return 0;
}