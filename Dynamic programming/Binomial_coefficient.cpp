#include<iostream>
#include<bits/stdc++.h>

using namespace std;
/*     1
    Triangle 
       1 1
       1 2 1
       1 3 3 1
       1 4 6 4 1
       1 5 10 10 5 1
*/

//  recursive approach 
int combination(int n,int k){
    // when n and k are equal their values became 1 
    if(n==k or k==0) return 1;
    // else find the sum of previous values as can be seen above diagram 
    return combination(n-1,k-1) +combination(n-1,k);
}

// DP approach  TC-O(n*k)   SPC (o(n*k))
int DP_approach(int n,int k) {
    vector<vector<int>>dp(n+1,vector<int>(k+1,0));
    

    // initializing the first column with values zero 
    for (int i = 0; i < n+1; i++)
    {
        dp[i][0]=1;
    }

    for(int i =1 ; i < n+1 ; i++) {
        for(int j =1 ;j < k+1 ; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    return dp[n][k];
}

// Optimizd DP approach  TC- O(n*k)  SPC-O(n)
int OP_DP(int n,int k) {
    vector<int>dp(k+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++) {
        for(int j=min(i,k);j>0;j--) {
            dp[j] = dp[j]+dp[j-1];
            cout<<dp[j]<<" ";
        }
        cout<<endl;
    }
    return dp[k];
}

int main() {
    int n,k;
    cin>>n>>k;
    // cout<<combination(n,k);
    // cout<<DP_approach(n,k);
    cout<<OP_DP(n,k);

}