// subset sum problem using DP  (basic variation of o-1 knapsack problem )
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool Is_subset_sum(vector<int>&v,int sum){
    // creation of 2d vector 
	vector<vector<bool>>ans(v.size()+1,vector<bool>(sum+1));
	// Initialising the array 
	for(int i=0;i<v.size()+1;i++) {
		for(int j=0;j<sum+1;j++) {
			if(i==0){
				ans[i][j]=false;
			}
			if(j==0) {
				ans[i][j]=true;
			}
		}
	}
	// display(ans);
	// checking for subproblems to solve the subset sum problem 
	for(int i=1;i<v.size()+1;i++) {
		for(int j=1;j<sum+1;j++) {
			if(v[i-1]<=j) {
				// it is similar to the o-1 knapsack 
				ans[i][j]=ans[i-1][j-v[i-1]] or ans[i-1][j];
			}
			else {
				ans[i][j]=ans[i-1][j];
			}
		}
	}
	// cout<<ans[v.size()][sum];
	return ans[v.size()][sum];
}

int main(){
	vector<int>arr{3,34,4,12,5,2};
	int sum=9;
	bool x=Is_subset_sum(arr,sum);
	
	if(x==1){cout<<"True"<<endl;}
	else{cout<<"No";}
    return 0;
}
