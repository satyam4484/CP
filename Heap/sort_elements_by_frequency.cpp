#include<iostream>
#include<bits/stdc++.h>

using namespace std;
// sort elemets of array having highest repetiton 
int main(){
    vector<int>v{2,5,2,8,5,6,8,8};
    // hash map for for storing frequencies 
    unordered_map<int,int>mp;
    for(int i=0;i<v.size();i++){
        mp[v[i]]++;
    }
    // max heap to store the elements with largest frequency 
    priority_queue<pair<int,int>>p;
    for(auto i:mp){
        p.push({i.second,i.first});
    }
    // printing the soretd array by frequency 
    while (p.size()>0)
    {
        pair<int,int>ans=p.top();
        // printing the element by their frequency 
        for(int i=0;i<ans.first;i++){
            cout<<ans.second<<" ";
        }
        p.pop();
    }
    // here the order of element does not matter 
    return 0;   
}
