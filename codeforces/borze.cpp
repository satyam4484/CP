// problem link --> https://codeforces.com/problemset/problem/32/B
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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
    string s;
    cin>>s;
    string ans;
    int i=0;
    while(i<s.size()){
        if(s[i] =='-' and s[i+1]=='-') {
            ans+='2';
            i+=2;
        }
        else if(s[i]=='-' and s[i+1]=='.') {
            ans+='1';
            i+=2;
        }
        else {
            ans+='0';
            i++;
        }
    }
    cout<<ans<<endl;
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