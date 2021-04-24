#include<iostream>
#include<vector>
using namespace std; 

// insert function to arrange the terms 
void insert(vector<int>&v,int temp){
    if (v.size()==0 || v[v.size()-1]<=temp)
    {
        v.push_back(temp);
        return;
    }
    int val=v[v.size()-1];
    v.pop_back();
    insert(v,temp);
    v.push_back(val);
    return ;
}
// sort function to reduce the length 
void sort(vector<int>&v){
    if (v.size()==1)
    {
        return ;
    }
    int temp=v[v.size()-1];
    v.pop_back();
    sort(v);
    insert(v,temp); 
}

int main(){
    int n;
    cin>>n;   // Enter no of elements inside the vector 
    vector<int>v;
    for (int i = 0; i < n ; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v);
    for (int i = 0; i < n ; i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}