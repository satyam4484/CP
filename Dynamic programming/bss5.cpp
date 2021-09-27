// problem link ->> https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>&v) {
        int n=v.size();
        vector<int>left(n,0),right(n,0);
        int mn = v[0];
        for(int i=1;i<n;i++) {
            if(mn > v[i]) {
                left[i] = max(left[i-1],v[i]-mn);
                mn = v[i];
            }else{
                left[i] = max(left[i-1],v[i]-mn);
            }
        }
        
        mn = v[n-1];
        for(int i=n-2;i>=0;i--) {
            if(mn>v[i]) {
                right[i] = max(right[i+1],mn-v[i]);
            }else {
                right[i] =max(right[i+1],mn-v[i]);
                mn = v[i];
            }
        }
        int ans = 0;                        
        for(int i=0;i<n;i++) {
            ans = max(ans,left[i]+right[i]);
        }
                                    return ans;
    }
};

int main ( ) {
    vector<int>v {3,3,5,0,0,3,1,4};
    Solution s;
    cout<<s.maxProfit(v);
    return 0;
}