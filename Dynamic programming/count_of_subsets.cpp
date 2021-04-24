#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// count of subsets with given sum  (similar to subset sum problem )

// Recursion approach 
int count_subset_R(vector<int>&v,int sum,int n) {
    if(sum==0){return 1;}
    if(n==0 && sum!=0) {return 0;}
    if(v[n-1]<=sum) {
        return count_subset_R(v,sum-v[n-1],n-1)+count_subset_R(v,sum,n-1);
    }
    return count_subset_R(v,sum,n-1);
}

// DP approach
int DP(vector<int>&v,int sum,int n) {
    /*
    vector<vector<int>>ans(n+1,vector<int>(sum+1));

    // initialization 
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=sum ;j++) {
            if(i==0) {ans[i][j]=0;}
            if(j==0) {ans[i][j]=1;}
        }
    }

    // main code 
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=sum ;j++) {
            if(v[i-1]<=j) {
                ans[i][j]=ans[i-1][j-v[i-1]] + ans[i-1][j];
            }
            else{ans[i][j]=ans[i-1][j];}
        }
    }
    return ans[n][sum];

    */

    // lets see in o(sum) space complexcity
    vector<int>ans1(sum+1,0);
    ans1[0]=1;
    for(int i=0;i<=n;i++) {
        for(int j=sum;j>=v[i];j--) {
            ans1[j]=ans1[j] + ans1[j-v[i]];
            // cout<<"ans["<<j<<"]=="<<ans1[j]<<" "<<endl;
        }
        // cout<<endl;
    } 
    return ans1[sum];
    
}
int main() {
    vector<int>v{1,2,3,3};
    int sum=6;
    // cout<<count_subset_R(v,sum,v.size());
    int x=DP(v,sum,v.size());
    cout<<x;
    return 0;
}