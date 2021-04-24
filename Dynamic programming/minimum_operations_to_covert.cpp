// problem link  -- > https://www.geeksforgeeks.org/minimum-number-deletions-insertions-transform-one-string-another/
//  minimum number of insertion and deletion 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define    pb    push_back
#define    ll    long long int 

#define  inpv(v,n)  for(int i=0;i<n;i++) cin>>v[i]
#define  outv(v)    for(auto i:v) cout<<i<<' ' 

// function to find the common or lcs of the string 
int find_lcs(string s1,string s2) {
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
    // return the length of the lcs 
    return ans[s1.size()][s2.size()];
}


int main()
{
    string s1="satyamsingh";
    string s2="sating";
    int lcs=find_lcs(s1,s2);

    // to make string 1 equal to string 2 delet the non common length
    cout<<"Deletion : "<<s1.size()-lcs<<endl;

    // and add the non common characters 
    cout<<"insertion : "<<s2.size()-lcs<<endl;

    return 0;
}