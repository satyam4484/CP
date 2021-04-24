// Gold mine problem 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Recursive code

void recursive(vector<vector<int>>&mine,int i,int j,int cs,int& max_sum) {
    // if we reach to end of mine grid then check whether the given sum is greater than maximum sum 
    if(i<0 or j<0 or i>=mine.size() or j>=mine[0].size()) {
         max_sum=max(cs,max_sum);
        return ;
    }
    // add the current value to our profit 
    cs+=mine[i][j];

    // go to right upward mine to gain profit 
    recursive(mine,i-1,j+1,cs,max_sum);

    // go to straight to gain profit 
    recursive(mine,i,j+1,cs,max_sum);

    // go right downward to gain profit 
    recursive(mine,i+1,j+1,cs,max_sum);
}


// DP approach 
int DP(vector<vector<int>>&mine,int n,int m) {
    vector<vector<int>>ans(n+1,vector<int>(m+1));
    for(int i=0;i<n;i++) {
        ans[i][0]=mine[i][0];
    }
    for(int j=0;j<m;j++) {
        ans[0][j]=mine[0][j];
    }

    for(int i=1; i<= n; i++) {
        for(int j=1 ; j<= m ;j++) {
            
        }
    }
}


int main() {
    vector<vector<int>>mine{{10,33,13,15},{22,21,4,1},{5,0,2,3},{0,6,14,2}};
    int max_sum=0;

    // since we are present at the first column so check for all values 
    // for(int i=0;i<mine.size() ;i++) {
    //     recursive(mine,i,0,0,max_sum);
    // }

    // finally we get the ans maximum 
    // cout<<max_sum;
    // cout<<DP(mine);
    return 0;
}