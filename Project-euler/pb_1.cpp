//SATYAM SINGH  
// problem link -- > https://www.hackerrank.com/contests/projecteuler/challenges/euler001/problem

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll 				long long int
#define pb 				push_back
#define mod             1000000007
#define inf             1e18
#define vi              vector<int>
#define vL              vector<ll>
#define vs             vector<string>
#define ump				unordered_map
#define mp 				make_pair
#define all(v)           v.begin(),v.end()

/* 

for n = 100

mult of 3 -- > 3+6+9+12+15+18+21 ..... 99
mult of 5 -- > 5+10+15+20 .........95 

now since 15 is common for both of the mulitples so we need to subtract 
it one time 

mul of 15 ---> 15+30+45... 90 

now take common terms 

3--> 3 (1+2+3+4...33) = 3* sum of natural numbers == 3*n*(n-1)/2   -- this will give sum of all mulitples of 3 less than 100 
5--> 5 (1+2+3...19)   = 5* sum of natural numbers == 5*n*(n-1)/2
15--> 15 (1+2+3...6)   = 15* sum of natural numbers == 15*n*(n-1)/2

so finall answer will be  == 3*n1*(n1-1)/2 + 5*n2*(n2-1)/2 - 15*n3*(n3-1)/2 

where      n1 = n/3 (subtract -1 if it is divisble )
           n2 = n/5 (subtract -1 if it is divisble )
           n3 = n/15 (subtract -1 if it is divisble )
*/




ll mul(ll a,ll b) {
    return a*(b*(b+1)/2);
}
int main( ) {

    int t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;

        ll m3 = (n%3 == 0?n/3-1:n/3);
        ll m5 = (n%5 == 0?n/5-1:n/5);
        ll m15 = (n%15 == 0?n/15 -1:n/15);
        ll sum = 0;
        sum+= mul(3,m3) + mul(5,m5) - mul(15,m15);
        cout<<sum<<endl;
    }

    
    return 0;
}
