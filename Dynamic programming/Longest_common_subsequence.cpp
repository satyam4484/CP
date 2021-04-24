#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// recursion aproach   TC- O(2^n)
int solve_LCS(string x,string y,int n,int m) {
    // string size becames zero 
    if(n==0 or m==0) return 0;
    // if matches then add and call for remaning one 
    if(x[n-1]== y[m-1]) {
        return 1+solve_LCS(x,y,n-1,m-1);
    }
    // else take maximum of both the string and recurr 
    return max(solve_LCS(x,y,n-1,m),solve_LCS(x,y,n,m-1));
}

// bottom up  -(memoziation approach )
int solve_MM(string x,string y,int n,int m,vector<vector<int>>&ans) {
    if(n==0 or m==0) return 0;
    if(ans[n][m]!=-1) return ans[n][m];
    if(x[n-1] == y[m-1]) {
        return ans[n][m]=1+solve_MM(x,y,n-1,m-1,ans);
    }
    return ans[n][m]=max(solve_MM(x,y,n-1,m,ans),solve_MM(x,y,n,m-1,ans));
}
int bottom_up(string x,string y,int n,int m) {
    // create a matrix 
    vector<vector<int>>ans(n+1,vector<int>(m+1,-1));
    return solve_MM(x,y,n,m,ans);
}

// TOp down - DP  TC( O(NM) )
int DP(string x,string y) {
    vector<vector<int>>d(x.size()+1,vector<int>(y.size()+1,0));
    for(int i=1;i<= x.size() ; i++ ){
        for(int j=1; j<= y.size() ;j++ ) {
            if(x[i-1]==y[j-1]) {
                d[i][j]=1+d[i-1][j-1];
            }
            else{
                d[i][j]=max(d[i-1][j],d[i][j-1]);
            }
        }
    }
    return d[x.size()][y.size()];
}
int main() {
    string x="AGGTAB";
    string y="GXTXAYB";
    // int ans=solve_LCS(x,y,x.size(),y.size());
    // cout<<ans;

    // cout<<bottom_up(x,y,x.size(),y.size());
    cout<<DP(x,y);
    return 0;
}