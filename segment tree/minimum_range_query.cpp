// range minimum query 
#include<iostream>
#include<bits/stdc++.h>

// 0 based segment tree 
// creation 
using namespace std;
void create(vector<int>&array,vector<int>&segment ,int low ,int high,int ind) {
    if(low==high) {
        segment[ind]=array[low];
        return ;
    }
    int mid=(low+high)/2;
    create(array,segment,low,mid,2*ind+1);
    create(array,segment,mid+1,high,2*ind+2);
    // since we need minimum then we will store minimum of the two nodes 
    segment[ind]=min(segment[2*ind+1],segment[2*ind+2]);
}

//  range query for get them minimum element 
int range_query(vector<int>&segment,int low,int high,int ind,int start,int end) {
    // if index is outside the given range return max value 
    if(low>end or high<start) return INT_MAX;

    //  if leaf node of self index comes then return the value 
    if(low>=start and high<=end) return segment[ind];
    int mid=(low+high)/2;

    //go to left range 
    int l=range_query(segment,low,mid,2*ind+1,start,end);

    // go to right range 
    int r=range_query(segment,mid+1,high,2*ind+2,start,end);
    // return the min of left and right part 
    return min(l,r);
}

int main() {
    vector<int>v{2,5,1,4,9,3};
    int n=v.size()-1;
    vector<int>segment(4*n);
    create(v,segment,0,n,0);

    cout<<"minimum in the range [4,5] is : "<<range_query(segment,0,n,0,4,5);

}