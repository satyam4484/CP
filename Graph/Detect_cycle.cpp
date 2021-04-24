//SATYAM SINGH  
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

class Graph {
    int V;
    list<int>*adj;
    public:
    Graph(int v) {
        this->V = v;
        this->adj = new list<int>[v];
    }

    void addedge(int u,int v,bool birdir= false) {
        this->adj[u].pb(v);

        if(birdir) {
            this->adj[v].pb(u);
        }
    }

    // detect cycle in directed graph 
    bool iscycle(ump<int,bool>&visited,int src) {
        if(visited[src] == true) return true;
        bool flag=false;
        visited[src] = true;
        for(auto j:this->adj[src]){
            if(iscycle(visited,j)) return true;
        }
        visited[src] = false;
        return false;
    }
    bool Detectdirected() {
        ump<int,bool> visited;
        bool flag=false;
        for(int i=0;i<this->V;i++) {
            visited[i] = true;
            for(auto j:this->adj[i]){
                if(iscycle(visited,j)) return true;
            }
            visited[i] = false;
        }
        return false;
    }

    // Detect cycle in undirected graph 

    bool undirectedgraph(int src,ump<int,int>visited) {
        if(visited[src] == 2) return true;
        visited[src] = 1;
        for(auto neighbour:this->adj[src]) {
            if(visited[neighbour] == 1) visited[neighbour] = 2;
            else {
                if(undirectedgraph(neighbour,visited)) return true;
            }
        }
        return false;
    }
    
    bool undirected() {
        ump<int,int>visited;
        for(int i=0;i<this->V;i++){
            visited[i] = 1;
            for(auto j:this->adj[i]){
                if(undirectedgraph(j,visited)) return true;
            }
            visited[i] = 0;
        }
        return false;
    }



};


int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    Graph g(4);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(2,0);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(3,3);
    cout<<g.Detectdirected();

    Graph g1(4);
    g1.addedge(0,1,true);
    g1.addedge(0,3,true);
    g1.addedge(2,3,true);
    g1.addedge(2,1,true);
    cout<<endl<<g1.undirected();
     

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
    #endif 
    return 0;
}
