#include<iostream>
#include<bits/stdc++.h>

using namespace std;
// find k number with most occurances in the given array 
int main(){
    //our array having different elements 
    vector<int>v{3,1,4,4,5,2,6,1};
    int k=2;
    // we can count the occurance of the digit using hash map (( O(d) )) ->d:number of distinct elements 
    unordered_map<int,int>mp;
    for(int i=0;i<v.size();i++){
        mp[v[i]]++;
    }
    // then we can create a min heap which will take pair of items 
    // pair<frequency of each element,the element>
    // so replace the int places with the pair of int 
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
    for(auto i:mp){
        // we will push the pairs in heap 
        p.push({i.second,i.first});
        // since the these is the minimum heap , the element with lowest frequency will be at the top
        // we want only k number if the size is greater then the k then pop the element 
        if(p.size()>k){p.pop();}
    }
    // finally we will be having a heap of k elements with most count 
    // since we are having pair at the heap we need pair to print the elements 
    while(p.size()>0){
        pair<int,int>t=p.top();
        // since the element is at the second position we will  print the second 
        cout<<t.second<<" ";
        p.pop();
    }
    
    return 0;
}