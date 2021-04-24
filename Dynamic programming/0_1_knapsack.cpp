//  0-1 Knapsack problem
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/*********************************************************************************************************/

// Approach 1 using recursion 
int recursion(vector<int>&w,vector<int>&v,int W,int n){
    // if we dont have any item or weight of bag is empty so return 0
    if(n==0 or W==0){return 0;}

    // these will check the given wait is less than the weight of knapsack 
    if(w[n-1]<=W){
        // we need to calculate the maximum profit so we have choices to take it or not 
        return max(v[n-1]+recursion(w,v,W-w[n-1],n-1),recursion(w,v,W,n-1));
    }
    // if weight is not included then check for remaining parts 
    return recursion(w,v,W,n-1);
}

/* ******************************************************************************************************* */

// Approach 2 makin some changes to above program to work better (memorization method )
int memorization(vector<int>&w,vector<int>&v,int W,int n,vector<vector<int>>&ans){
    //  same base case as above method 
    if(n==0 or W==0){return 0;}

    // these is the condtition suppose we have already find the value for next recusion part
    // so instead of calling that we can directly return it value from here which is stored 
    if(ans[n][W]!=-1){
        return ans[n][W];
    }
    // same as recusion only we are storing the values 
    if(w[n-1]<=W){
        return ans[n][W]=max(v[n-1]+memorization(w,v,W-w[n-1],n-1,ans),memorization(w,v,W,n-1,ans));
    }

    return ans[n][W]=memorization(w,v,W,n-1,ans);

}
int memor(vector<int>&w,vector<int>&v,int W,int n){
    // we create a matrix of the values which are changing such as weight on knapsack and size of array 
    // initialise all the elements with -1
    vector<vector<int>>ans(n+1,vector<int>(W+1,-1));
    // call another fucntion which will give the ans 
    return memorization(w,v,W,n,ans);
}

/* ******************************************************************************************************* */

// Approach 3 --Dyanmic programming 
int Dynamic_programming(vector<int>&w,vector<int>&v,int W,int n) {
    // we created a 2d matrix without iniatilaiseing with -1
    vector<vector<int>>DP(n+1,vector<int>(W+1));

    // step 1 : base case initialisation 
    for(int i=0;i<n+1;i++) {
        for(int j=0 ;j<W+1;j++) {
            if(i==0 or j==0 ){
                DP[i][j]=0;
            }
        }
    }

    // step 2 : Doing the recursion part iteratively and storing the values 

    for(int i=1; i<n+1 ;i++) {
        for(int j=1 ;j<W+1 ;j++) {
            // if statement same as recursion 
            if(w[i-1]<=j){
                DP[i][j]=max(v[i-1]+DP[i-1][j-w[i-1]],DP[i-1][j]);
            }
            // if wight is greater than dont take it 
            else{
                DP[i][j]=DP[i-1][j];
            }
        }
    }
    return DP[n][W];
}




int main(){
    vector<int>value{60,100,120};
    vector<int>weight{10,20,30};
    int W=50;
    // cout<<recursion(weight,value,W,3);
    // cout<<memor(weight,value,W,3);
    cout<<Dynamic_programming(weight,value,W,3); // ANS--> 220 
    return 0;
}