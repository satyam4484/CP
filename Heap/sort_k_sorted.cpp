#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// sort an almost k sorted array 
int main(){
    vector<int>v{6,5,3,2,8,10,9};
    int k=3;

    // we will take min heap iif we want to sort in ascending order or max heap in descending order 
    priority_queue<int,vector<int>,greater<int>>p;
    // traverse the loop 
    for(int i=0;i<v.size();i++){
        p.push(v[i]);
        // if size is greater than k print the ans 
        if(p.size()>k){
            cout<<p.top()<<" ";
            p.pop();
        }
    }
    // atlast remove all elemnts from the heap and print 
    while (p.size()>0)
    {
        cout<<p.top()<<" ";
        p.pop();
    }
}