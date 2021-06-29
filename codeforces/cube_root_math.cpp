//SATYAM SINGH  
// problem link -->https://codeforces.com/problemset/problem/1490/C
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll                 long long int
#define pb                 push_back
#define mod                     1000000007
#define inf                     1e18
#define ump                unordered_map
#define mp                 make_pair
#define all(v)                   v.begin(),v.end()

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
unordered_set<ll>b;

const ll N = 1'000'000'000'000L;

void solve() {
    for(ll i=1;i*i*i<=N;i++) {
        b.insert(i*i*i);
    }
}



int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    solve();
    int t;
    cin>>t;
    while(t--) {
        ll x;
        cin>>x;
        bool val=false;
        for(ll i=1;i*i*i<=x;i++) {
            if(b.count(x-i*i*i)) {
                val=true;
                break;
            }
        }
        if(val) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    
     

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*100<<" seconds";
    #endif 
    return 0;
}