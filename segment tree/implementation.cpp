// sum values in range and update 
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// making of segment tree (1 based index )

void build_segment(vector<int>&array,vector<int>&segment,int low,int high,int mid1) {
    // when range values are equal (leaf node )
    // update the segment tree values 
    if(low==high) {
        segment[mid1]=array[low];
        return ;
    }
    // calculate the mid value 
    int m=(low+high)/2;
    // Traverse the left part of the tree 
    build_segment(array,segment,low,m,2*mid1);
    // traverse the right part of the tree 
    build_segment(array,segment,m+1,high,2*mid1+1);
    //  while coming back add thode two values and return back 
    segment[mid1]=segment[2*mid1]+segment[2*mid1+1];
}

// updating the value of segment 
void update(vector<int>&array,vector<int>&segment,int low,int high,int mid1,int ind,int val) {

    // when leaf node condition comes update the value in the original array and in the segment tree 
    if(low==high) {
        array[ind]=val;
        segment[mid1]=val;
        return ;
    }

    // calculate mid 
    int m=(low+high)/2;
    // if index is greater than move to right part of the tree 
    if(ind>m) {
        update(array,segment,m+1,high,2*mid1+1,ind,val);
    }
    // else move to left part of the tree 
    else{
        update(array,segment,low,m,2*mid1,ind,val);
    }
    // while coming back update the values 
    segment[mid1]=segment[2*mid1]+segment[2*mid1+1];
}

// function for queries 
int query(vector<int>&segment,int low,int high,int mid1,int left,int right ) {
    //  if we exceed the segment tree return ans 0
    if(low>right or high<left) {
        return 0;
    }
    // when we hit any bounday condition similar to the range then return that value 
    if(low>=left and high<=right) {
        return segment[mid1];
    }
    // calculate the mid 
    int m=(low+high)/2;

    // get values from left part of the tree 
    int a1=query(segment,low,m,2*mid1,left,right);
    // get from right part 
    int a2=query(segment,m+1,high,2*mid1+1,left,right);

    // add them and return the ans 
    return a1+a2;
}
int main() {
    vector<int>v={1,3,5,7,9,11};
    vector<int>segment(4*v.size(),0);
    // builde the segment tree 
    build_segment(v,segment,0,v.size()-1,1);

    // sum of value in range (1,4);
    cout<<query(segment,0,v.size()-1,1,1,3);
    
    // update the value
    update(v,segment,0,v.size()-1,1,1,10);

    // print the updated sum  value again 
    cout<<query(segment,0,v.size()-1,1,1,3);
}