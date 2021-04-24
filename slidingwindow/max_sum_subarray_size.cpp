/*
Given array and a value of k . Find the maximum sum of subarray of size k .
EG :  v=[ 2,5,1,8,2,9,1 ], k=3
           [ 8,2,9 ] gives maximum sum = 19 
Approach 1 : Brute force 

// maximum sum of sub-array of size k 
*/
#include<iostream>
#include<vector>
using namespace std;

// function to get maximum sum (Brute force approach )
void max_sum(vector<int>&v,int &k,int &max_su){
    
    for (int i = 0; i < v.size()-k+1; i++)
    {
        int sum=0;
        for (int j = i; j <i+k ; j++)
        {
            sum+=v[j];
        }
        max_su=max(sum,max_su);
    }
}
int main(){
    int n,k;
    vector<int>v;
    cout<<"Enter the array size : ";
    cin>>n;
    cout<<"Enter array elements "<<endl;
    for (int i = 0; i < n ; i++)
    {
        cin>>k;
        v.push_back(k);
    }
    
    cout<<"Enter the size of subarray : ";
    cin>>k;
    int max_su=INT8_MIN;
    max_sum(v,k,max_su);
    cout<<"maximum subarray sum is : "<<max_su<<endl;
    return 0;
}
// Approach 2 : Sliding window 
// only function rest all are same 
// function to get maximum sum (sliding window approach )
void max_sum(vector<int>&v,int &k,int &max_su){
    int sum=0,i=0,j=0;
    while (j<v.size())
    {
        sum+=v[j];
        if(j-i+1<k){
            j++;
        }
        // when we reach to subarray then maintain it 
        else if(j-i+1==k){
            max_su=max(sum,max_su);
            sum=sum-v[i];
            i++,j++;
        }
    }
}