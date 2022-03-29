#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/141/A
#define ll                 long long int
#define pb                 push_back
#define mod             1000000007
#define inf             1e18
#define ump                unordered_map
#define mp                 make_pair

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

void Main() {
    unordered_map<char,int>mp;
    string a;
    cin>>a;
    for(auto i:a){
        mp[i]++;
    }
    cin>>a;
    for(auto i:a){
        mp[i]++;
    }
    cin>>a;
    for(auto i:a){
        if(mp[i] == 1) {
            mp.erase(i);
        }else if(mp.find(i) != mp.end()) {
            mp[i]--;
        }else{
            mp[i]++;
        }
    }
    if(mp.size() == 0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    Main();

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
    #endif 
    return 0;
}