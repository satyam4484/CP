//SATYAM SINGH  
// problem link --> https://www.hackerrank.com/contests/projecteuler/challenges/euler003/problem

// did't passed the last test case and modification ?? 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll         long long int
#define pb         push_back
#define mod             1000000007
#define inf             1e18
#define vi              vector<int>
#define vL              vector<ll>
#define vs             vector<string>
#define ump        unordered_map
#define mp         make_pair
#define all(v)           v.begin(),v.end()

#define  inpv(v,n)  for(int i=0;i<n;i++) cin>>v[i]
#define  outv(v)    for(auto i:v) cout<<i<<' ' 
#define  loop(i,a,b)  for(int i=(a);i<(b);i++)
#define  looprev(i,a,b)  for(int i=(a);i>=0;i--)
#define log(args...)  {string _s = #args ;replace(_s.begin(),_s.end(),',',' ') ; stringstream _ss(_s); istream_iterator<string> _it(_ss) ; err(_it,args);}
void err(istream_iterator<string> it) {}
template<typename T,typename ... Args>
void err(istream_iterator<string> it, T a,Args... args) {
      cout<<*it<<" = "<<a<<endl;
   err(++it,args...);
}

void file_i_o()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
vL prime;

void solve() {
  vector<bool> v(100000009,true);
  v[0] = v[1] = false;

  for(int i = 2 ; i*i<= 100000009 ; i++) {
    if(v[i]) {
      for(int j=i*i;j<=100000009;j+=i) {
        v[j] = false;
      }
    }
  }

  loop(i,2,v.size()) {
    if(v[i]) prime.pb(i);
  }
}

int main( ) {
    clock_t begin = clock();
    // file_i_o();
    // Write your code here....
    solve();
    
    int t;
    cin>>t;
    while(t--) {

      ll n;
      cin>>n;
      ll ans;
      int i=0;
      while(prime[i] <= n) {
        if(n%prime[i] == 0) ans=prime[i];
        i++;
      }
      cout<<ans<<endl;
    }

     

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
    //   clock_t end = clock();
    //   cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
    #endif 
    return 0;
}
