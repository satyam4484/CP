//SATYAM SINGH  
// problem link -->https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/tutorial/
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
void findall(int u,vector<int>&at,vector<pair<int,int>>&bd,vector<int>&low,vector<int>&disc,vector<int>&parent,vector<int>adj[]) {
    static int time = 0;
    low[u] = disc[u] = time;
    time++;
    int children = 0;
    for(auto v:adj[u]) {
        if(disc[v] == -1) {
            children++;
            parent[v] = u;
            findall(v,at,bd,low,disc,parent,adj);
            low[u] = min(low[u],low[v]);

            // bridges
            if(low[v] > disc[u]) {
                if(u > v) bd.pb({v,u});
                else bd.pb({u,v});
            }

            if(parent[u] == -1 and children > 1) at.pb(u);
            if(parent[u] !=-1 and low[v] >= disc[u]) at.pb(u);

        } else if(v!=parent[u]) {
            low[u] = min(low[u],disc[v]);
        }
    }

}
void solve(vector<int>&at,vector<pair<int,int>>&bd,int n,vector<int>adj[]) {
    vector<int>low(n),disc(n,-1),parent(n,-1);
    findall(0,at,bd,low,disc,parent,adj);
}


int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n,m;
    cin>>n>>m;
    vector<int>v[n];
    loop(i,0,m) {
        int a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }

    vector<int>at;
    vector<pair<int,int>>br;
    solve(at,br,n,v);
    sort(all(at));
    cout<<at.size()<<endl;
    outv(at);
    cout<<endl;
    cout<<br.size()<<endl;
    sort(all(br));
    for(auto i:br) {
        cout<<i.first<<" "<<i.second<<endl;
    }
     
    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*100<<" seconds";
    #endif 
    return 0;
}