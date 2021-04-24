// longest palindromic subsequence 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// function to find the length of longest common palindrome subsequence 
void solve_palin(string s1,string s2) {
    vector<vector<int>>ans(s1.size()+1,vector<int>(s2.size()+1,0));

    // 
    for(int i=1;i<= s1.size() ; i++) {
        for(int j=1; j<= s2.size() ; j++) {
            if(s1[i-1] == s2[j-1]) {
                ans[i][j] =  1+ ans[i-1][j-1];
            }
            else {
                ans[i][j] = max(ans[i-1][j],ans[i][j-1]);
            }
        }
    }
    cout<<ans[s1.size()][s2.size()];
}


void print_subse(string a , string b ){
    // find the length of longest palindromic subsequence 
    vector<vector<int>>lenght(a.size()+1,vector<int>(b.size()+1,0));

    for(int i=1;i<= a.size() ; i++) {
        for(int j=1; j<= b.size() ;j++) {
            if(a[i-1] == b[j-1] ){
                lenght[i][j]= 1+ lenght[i-1][j-1];
            }
            else {
                lenght[i][j]= max(lenght[i-1][j],lenght[i][j-1]);
            }
        }
    }
    string ans="";
    for(int i=a.size() ;i>0 ;i--) {
        for(int j=b.size() ;j>0 ;j--) {
            if(a[i]==b[j]) {ans+=a[i];}
            else {
                if(lenght[i-1][j] > lenght[i][j-1]) i--;
                else j--;
            }
        }
    }
    cout<<ans<<endl;
}

// function to print the length of longest common palindrome substring 
void substring(string a,string b) {
    vector<vector<int>>subs(a.size()+1,vector<int>(b.size()+1,0));

    // store the maximum lenght 
    int max_size=-1;
    for(int i=1;i<= a.size() ; i++) {
        for(int j=1; j<= b.size(); j++) {
            if(a[i-1] == b[j-1]) {
                subs[i][j]=1+subs[i-1][j-1];
                
                if(max_size<subs[i][j]) 
                {
                    max_size=subs[i][j];
                }
            }
            else {
                subs[i][j]=0;
            }
        }
    }
    
}


int main() {
    string a="aacabdkacaa";
    string b=a;
    reverse(b.begin(),b.end());
    substring(a,b);
    return 0;
}