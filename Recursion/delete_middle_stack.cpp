#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//deleting function 
void deletes(stack<int>&st,int k){
    if(k==1){
      st.pop();
      return;
    }
    int temp=st.top();
    st.pop();
    deletes(st,k-1);
    st.push(temp);
}

// checking condition 
void middle(stack<int>&st,int n){
  if (n==1){
    return ;
  }
  int k=(n/2)+1;
  deletes(st,k);
}
int main(){
  stack<int>st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.push(5);
  st.push(10);
  st.push(23);

  // delete function 
  middle(st,st.size());
  int n=st.size();
  for (int i = 0; i <n; i++)
  {
    cout<<st.top()<<" ";
    st.pop();
  }
  
  
  return 0;
}