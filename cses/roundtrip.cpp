//SATYAM SINGH  
// problem link -- > https://cses.fi/problemset/task/1669/
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

class Graph {
    int v;
    list<int>*adj;
    int st,end;
public:
    Graph(int n) {
        this->v = n;
        this->adj = new list<int>[n];
    }

    void addedge(int u,int v) {
        this->adj[u].pb(v);
        this->adj[v].pb(u);
    }
    bool dfs(int src,int p,vector<int>&vis,vector<int>&parent) {
        vis[src] = true;
        parent[src] = p;

        for(auto neigh:this->adj[src]) {
            if(neigh == p) continue;
            if(vis[neigh]) {
                st = neigh;
                end = src;
                return true;
            }
            if(not vis[neigh] and dfs(neigh,src,vis,parent)) return true; 
        }
        return false;
    }

    void solve() {
        vector<int>parent(this->v),visited(this->v,0);

        bool ans = false;
        for(int i=1;i<this->v;i++) {
            if(not visited[i] and dfs(i,-1,visited,parent)) { 
                ans = true;
                break;
            }
        }
        if(ans == false) cout<<"IMPOSSIBLE"<<endl;
        else {
            vector<int>ans;
            ans.pb(end);
            int v= end;
            while(end !=st) {
                end = parent[end];
                ans.pb(end);
            }
            ans.pb(v);
            cout<<ans.size()<<endl;
            outv(ans);
        }
    }


};
int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n,m;
    cin>>n>>m;

    Graph g(n+1);
    loop(i,0,m) {
        int u,v;
        cin>>u>>v;
        g.addedge(u,v);
    }
     
    g.solve();

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*100<<" seconds";
    #endif 
    return 0;
}