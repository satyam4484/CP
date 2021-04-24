#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Recurisive approach 
bool is_possible(vector<int>&v,int n,int sum) {
    // if we have not given any sum then we can return an empty subset which whill we zero 
    if(sum==0) {return true;}

    // suppose we have vector size zero and want sum then there is no to pass any sum 
    if(n==0 && sum!=0) {return false;}
    // if our elemnts are less than our sum then there are chances that they can give us answer 
    if(v[n-1]<=sum) {
        // here we include the sum or do not include it 
        return is_possible(v,n-1,sum-v[n-1]) or is_possible(v,n-1,sum);
    }

    // if not included then directly return false 
    return is_possible(v,n-1,sum);
}

// Dynamic programming  Space-comp( O(n+1*sum+1) )
bool DP_approach(vector<int>&v,int sum,int n) {


    /* more space approach */ 

/*
    vector<vector<bool>>DP(n+1,vector<bool>(sum+1));
    // Initialization 
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++) {
            if(i==0) {DP[i][j]=false;}
            if(j==0) {DP[i][j]=true;}
        }
    }

    // main code of the above recursion step 
    for(int i=1;i<n+1;i++) {
        for(int j=1;j<sum+1;j++) {
            if(v[i-1]<=j) {
                DP[i][j]=DP[i-1][j-v[i-1]] or DP[i-1][j];
            }
            else{
                DP[i][j]=DP[i-1][j];
            }
        }
    }
    return DP[n][sum];
*/


    // The space complexcity  can be reduced 
    vector<bool>DP(sum+1,false);
    DP[0]=true;

    // traverse the array 
    for(int i=0;i<n+1;i++) {

        // traverse from the sum upto the value or array 
        for(int j=sum;j>=v[i];j--) {
            // same as above dp step 
            DP[j]=DP[j] or DP[j-v[i]];
         
        }
    }
    return DP[sum];
}


int main() {
    vector<int>v{1,5,11,5};
    int sum=0;
    // calculating the sum of elements inside the array 
    for(auto i:v) {
        sum+=i;
    }
    // since we want to divide the array in to equal parts then sum of their elements should be even 
    // if not then there is no way to divide in equal parts 
    if(sum%2!=0) {
        cout<<"No"<<endl;
    }

    else{
        // now the problem became to subset sum problem since we need to calcute whether half of the sum exist or not 
        // if yes then another subset will also exist in the array 
    // bool ans=is_possible(v,v.size(),sum/2);
    bool ans(DP_approach(v,sum/2,v.size()));
    if(ans) {cout<<"yes";}
    else{cout<<"no";}}
    return 0;
}