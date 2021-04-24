#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void inser(stack<int>&st,int &temp){
    if(st.empty() || st.top()<=temp){
        st.push(temp);
        return ;
    }
    int val=st.top();
    st.pop();
    inser(st,temp);
    st.push(val);
    return;
}
void sort_stack(stack<int>&st){
    if(st.size()==1){
        return ;
    }
    int temp=st.top();
    st.pop();
    sort_stack(st);
    inser(st,temp);
}

int main(){
    stack<int>st;
    st.push(1);
    st.push(5);
    st.push(3);
    st.push(4);
    st.push(2);
    sort_stack(st);

    //  Before sorting ===== 1 5 3 4 2
    int n=st.size();

    // printing the values after sorting 
    for (int i = 0; i <n ; i++)
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    

    // After sorting ===== 5 4 3 2 1
    return 0;
}
