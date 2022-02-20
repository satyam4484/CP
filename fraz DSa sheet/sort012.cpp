#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// problem link--> 
/*
https://leetcode.com/problems/sort-colors/
https://www.codingninjas.com/codestudio/problems/sort-0-1-2_631055?topList=mohammad-fraz-dsa-sheet-problems&leftPanelTab=0

*/

void sort012(vector<int>&arr,int n){
    int low = 0,high = n-1,mid = low;
   while(mid <= high){
       if(arr[mid] == 0) {
           swap(arr[mid],arr[low]);
           low++,mid++;
       }else if(arr[mid] == 2){
           swap(arr[mid],arr[high]);
           high--;
       }else{
           mid++;
       }
   }
}

int main ( ) {
    vector<int>v{0,1 ,2 ,1 ,2 ,1,2};
    sort012(v,v.size());
    for(auto &i:v){
        cout<<i<<" ";
    }
     
    return 0;
}