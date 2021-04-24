#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/* 1: program for kth smallest number in an array */
int main(){
    // create a max heap to find the kth smallest number 
    priority_queue<int>heap;
    vector<int>v{1,23,12,9,30,2,50};
    int k=3;
    // traverse the array 
    for(int i=0;i<v.size();i++)
    {
        heap.push(v[i]);
        // we will maintain the size of heap upto k 
        if(heap.size()>k){
            heap.pop();
        }
    }
    // finally we will get answer at the top of the max heap which will be the kth smallest number
    cout<<heap.top(); // 9
    return 0;
}

/* 2: program for the kth lagrest number in an array */
int main(){
    // declaration of min heap using stl 
    priority_queue<int,vector<int>,greater<int>>min_heap;
    vector<int>v{1,23,12,9,30,2,50};
    int k=3;
    // traverse the array 
    for(int i=0;i<v.size();i++)
    {
        min_heap.push(v[i]);
        // we will maintain the size of heap upto k 
        if(min_heap.size()>k){
            min_heap.pop();
        }
    }
    // finally we will get answer at the top of the min heap which will be the kth largest number
    cout<<min_heap.top();  // 23
    return 0;
}