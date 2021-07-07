#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;
class MinStack {
    stack<pair<int,int>>st;
    int mn = INT_MAX;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val) {
        mn = min(val,mn);
        st.push({val,mn});
    }
    
    void pop() {
        if(not st.empty() and st.top().first == mn) {
            st.pop();
            mn = (not st.empty() ? st.top().second:INT_MAX);
        } else{
            st.pop();
        }
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};



int main( ) {
    MinStack minst =  MinStack();
    minst.push(-2);
    minst.push(0);
    minst.push(-3);
    cout<<minst.getMin()<<endl;
    minst.pop();
    cout<<minst.top()<<endl;
    cout<<minst.getMin()<<endl;


    return 0;
}