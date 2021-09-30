//SATYAM SINGH  
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll                 long long int

int main( ) {
    // Write your code here....
    int n;
    cin>>n;
    int count = 0;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        if(x != -1) count++;
    }
    cout<<count<<endl;

    return 0;
}