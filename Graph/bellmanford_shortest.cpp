//SATYAM SINGH  
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

struct node{
    ll des,weight;
};


void bellmanford(vector<node>adj[],int n){
    vector<ll>dist(n,INT_MAX);
    dist[0] = 0;
    bool any = false;
    loop(itr,0,n-1){
        for(int i=0;i<n;i++) {
            for(auto j:adj[i]){
                int u=i;
                ll v = j.des;
                ll w = j.weight;
                if(dist[u]!=INT_MAX and dist[u]+w < dist[v]) {
                    dist[v] = dist[u]+w;
                    any = true;
                }
            }
        }
        if(not any) break;
    }
    outv(dist);
}


int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n,m;
    cin>>n>>m;
    vector<node>v[n];
    loop(i,0,m) {
        ll a,b,c;
        cin>>a>>b>>c;
        v[a].pb({b,c});
    }

    bellmanford(v,n);
    // for(int i=0;i<n;i++) {
    //     cout<<i<<" -->";
    //     for(auto j:v[i]) {
    //         cout<<j.des<<" "<<j.weight<<" ,";
    //     }
    //     cout<<endl;
    // }
    
     

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*100<<" seconds";
    #endif 
    return 0;
}