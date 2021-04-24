//SATYAM SINGH  
// problem link -->    https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll 				long long int
#define pb 				push_back
#define mod             1000000007
#define inf             1e18
#define ump				unordered_map
#define mp 				make_pair

#define  inpv(v,n)  for(int i=0;i<n;i++) cin>>v[i]
#define  outv(v)    for(auto i:v) cout<<i<<' ' 
#define  loop(i,a,b)  for(int i=(a);i<(b);i++)
#define  looprev(i,a,b)  for(int i=(a);i>=0;i--)

void file_i_o()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
int Get(vector<int>&parent ,int a) {
    if(parent[a] == a ) return a;
    return parent[a] = Get(parent,parent[a]);
}

void setunion(vector<int>&parent,vector<int>&rank,int a,int b) {
    a = Get(parent,a);
    b =Get(parent,b);
    if(rank[a] == rank[b] )rank[a]++;
    if(rank[a] > rank[b] ) parent[b] = a;
    else parent[a] = b;
}

int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int n,k;
    cin>>n>>k;
    vector<int>parent(n+1);
    loop(i,1,n+1) parent[i] = i;
    vector<int>rank(n,1);

    loop(i,0,k) {
        int a,b;
        cin>>a>>b;
        setunion(parent,rank,a,b);
    }

    int count = 0;
    loop(i,1,n+1) {
        if(parent[i] == i ) count++;
    }
    cout<<count<<endl;


    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
    #endif 
    return 0;
}
