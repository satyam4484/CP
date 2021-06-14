// problem link -- > https://codingcompetitions.withgoogle.com/kickstart/round/0000000000436140/000000000068cca3

#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
    
    
int main( ) {
    int t;
    cin>>t;
    for(int j=1;j <= t; j++) {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int count = 0;
        for(int i=0;i<n/2;i++) {
            if(s[i] != s[n-i-1]) count++;
        }
        if(count == k)  cout<<"Case #"<<j<<": "<<0<<endl;
        else if(count > k) cout<<"Case #"<<j<<": "<<count-k<<endl;
        else cout<<"Case #"<<j<<": "<<k-count<<endl;
    }
    return 0;
}