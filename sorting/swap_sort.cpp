/*
There are given numbers from 1 to N .Some numbers are missing and some numbers are duplicate .
Find the missing and duplicate numbers .
*/
//Find the missing and duplicates number O(n)
#include<iostream>
#include<vector>
using namespace std;
void get_missing(vector<int>&v){
    int i=0;

    /* we have to move each element to their position 
        so that we can directly get the missing and 
        duplicates 
    */
    while (i<v.size())
    {
        //check whether the array element position is correct or not 
        if(v[i]!=v[v[i]-1]){
            // if not then move to correct position 
            swap(v[i],v[v[i]-1]);
        }

        // other wise increment the value of i
        else
        {
            i++;
        }
    }

    /*
        after the above operation all elements 
        will we at their original position 
        except the missing and duplicates numbers 
    */
    for (i = 0; i < v.size(); i++)
    {
        // if value is not equal then missing and duplicates condition
        // satiefies 
        if(v[i]!=i+1){
            cout<<"missing : "<<i+1<<endl;
            cout<<"Duplicate : "<<v[i]<<endl;
        }
    }
}

// main function 
int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    vector<int>v;
    cout<<"Enter elements "<<endl;
    // get array elements 
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    get_missing(v);
    
    return 0;
}