// palindrome partitioning 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// function to check whether the string is paindrome or not 
bool ispalindrome(string a,int i,int j) {
    while(i<=j) {
        if(a[i]!=a[j]) return false;
        i++,j--;
    }
    return true;
}

// recusrive function to solve the palindromic partition 
int solve(string a,int i, int j) {
    // in valid value no need to partition 
    if(i>=j) return 0;

    // if string is already palindromic then no need to partition it return 0
    if(ispalindrome(a,i,j)) return 0;

    // value to store the min ans 
    int min_ans=INT_MAX;
    for(int k=i;k<j;k++) {
        // since we are patitoning it add 1 and recur for remaining values 
        int temp=1+solve(a,i,k)+solve(a,k+1,j);

        //  store the min ans 
        min_ans=min(min_ans,temp);
    }
    // return 
    return min_ans;
}

// function of memoziation method of recusrive approach 
int solve_memo(string a,int i,int j,vector<vector<int>>&ans) {
    if(i>=j) return 0;
    //  check whether we have already find the ans for these values or not 
    if(ans[i][j]!=-1) return ans[i][j];
    // if string is palindromic then no need to partition 
    if(ispalindrome(a,i,j)) return 0;
    ans[i][j]=INT_MAX;
    for(int k=i;k<j;k++) {
        int temp=1+solve(a,i,k)+solve(a,k+1,j);
        ans[i][j]=min(ans[i][j],temp);
    }
    return ans[i][j];
}

//  function of memoziation 
int memo(string a,int i,int j) {
    vector<vector<int>>ans(a.size()+1,vector<int>(a.size()+1,-1));
    return solve_memo(a,i,j,ans);
}

int main( ){
    // string a="abcde";
    string a="ababbbabbababa";
    int i=0,j=a.size()-1;
    // cout<<solve(a,i,j);
    cout<<memo(a,i,j);
    return 0;
}