#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;


int main( ) {
    stack<pair<int,int>>st;
    vector<int>ans;
    int n;
    cin>>n;
    int maxel = INT_MIN;
    for(int i=0;i<n ;i++) {
        int x,y;
        cin>>x;
        if(x == 1 ) {
            cin>>y;
            maxel = max(maxel,y);
            st.push({y,maxel});
        } else if( x == 2) {
            if(st.top().first == maxel) {
                st.pop();
                maxel = (not st.empty() ?st.top().second:INT_MIN);
            } else {
                st.pop();
            }
        } else {
            ans.push_back(st.top().second);
        }
    }

    for(auto i:ans) {
        cout<<i<<endl;
    }
    return 0;
}