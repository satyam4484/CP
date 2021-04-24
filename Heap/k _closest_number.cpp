#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// k closest number 
/* you are a given a number which you have to find how many k numbers are closer to that number in a given array */
int main(){
    vector<int>v{5,6,7,8,11,12,4};
    int x=9;
    int k=3;
    // we have created  pair of max heap ,which take the absoulte differene and the number 
    priority_queue<pair<int,int>>p;
    for(int i=0;i<v.size();i++){
        p.push({abs(v[i]-x),v[i]});
        if(p.size()>k){
            p.pop();
        }
    }
    cout<<"the numbers closer to "<<x<<" are :  ";
    while(p.size()>0){
        cout<<p.top().second<<" ";
        p.pop();
    }
    // time complexcity is ( O(nlogk) )
    return 0;   
}