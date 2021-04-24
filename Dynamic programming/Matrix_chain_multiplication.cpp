// matrix chain multplication 
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// recursive approach to solve the problem 
int solve(vector<int>&array,int i,int j) {
    // if the value is invalid then return 0 
    if(i>=j) return 0;

    // variable to store the minimum element 
    int min_ans=INT_MAX;
    // now split the array into parts and chek for each variable 
    for(int k=i;k<j;k++) {

        //  store the ans in 
        int temp=solve(array,i,k)+solve(array,k+1,j) + array[i-1]*array[j]*array[k];
        min_ans=min(min_ans,temp);
    }
    return min_ans;
}

// memoziation of above approach 
int solve_ans(vector<int>&v,int i,int j,vector<vector<int>>&value) {
    if(i>=j) return 0;
    if(value[i][j]!=-1 )return value[i][j];
    value[i][j]=INT_MAX;
    for(int k=i;k<j;k++) {
        value[i][j]=min(value[i][j],solve_ans(v,i,k,value)+solve_ans(v,k+1,j,value)+v[i-1]*v[k]*v[j]);
    }
    return value[i][j];
}
int solve_memo(vector<int>&arr,int i,int j) {
    vector<vector<int>>ans(arr.size(),vector<int>(arr.size(),-1));
    for(int  i=0;i<arr.size() ;i++) {
        ans[i][0]=0;
        ans[0][i]=0;
    }
    return solve_ans(arr,i,j,ans);
}
int main( ){
    vector<int>v = {40,20,30,10,30};
    cout<<solve_memo(v,1,4);
    return 0;
}