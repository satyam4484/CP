//SATYAM SINGH  
// Problem link  -- > https://www.hackerrank.com/contests/projecteuler/challenges/euler002/problem
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


/*  
 since there can be only 80 fibonnaci numbers between 0 to 4*10^16 
 so brute force will work correctly 
*/
int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    ll ans = 4*pow(10,16);
    ll a=0,b=1,c=0;
    vL v;
    while(true) {
      c = a + b;
      v.pb(c);
      if ( c > ans ) break;
      a = b , b = c;
    }

    int t;
    cin>>t;
    while(t--) {
      int i=0;
      ll n;
      cin>>n;
      ll sum=0;
      while(v[i] < n ) {
        if(v[i]%2 == 0) sum+=v[i];
        i++;
      }
      cout<<sum<<endl;
    }
    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
    #endif 
    return 0;
}
