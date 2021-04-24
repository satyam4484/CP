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

struct node{
    int des,weight;
};

class Graph {
    public:
    int V;
    list<node>*adj;

    Graph (int v) {
        this->V =v;
        this->adj= new list<node>[v];
    }

    // function to add the edges in graph 
    void addedge(int u,int v,int w=1) {
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
    }

    // here the weights are 1 by default and it can be 0 or 1 according to the confidtion of the given questions 
    void ShortestPathInWeightesd(int src) {
        queue<int>q;
        vector<int>dis(this->V,0);
        ump<int,bool>visited;
        visited[src] =true;
        q.push(src);

        while(not q.empty()) {
            int v=q.front();
            q.pop();

            for(auto neighbour: this->adj[v]) {
                if (not visited[neighbour.des]) {
                    visited[neighbour.des] = true;
                    q.push(neighbour.des);
                    dis[neighbour.des] = dis[v] + neighbour.weight;
                }
            }
        }

        cout<<"Shortest Path from source '"<< src<<"' to all other vertices are ::  ";
        outv(dis);
        // ans  -->   0 1 2 3 4 3 2 1 2 
    }

    //  helper function to do bfs traversal 
    void helper(int src,ump<int,bool> &visited) {
        visited[src] =true;
        queue<int>q;
        q.push(src);
        while(not q.empty()) {
            int v=q.front();
            q.pop();
            for(auto neigh:this->adj[v]) {
                if(not visited[neigh.des]) {
                    visited[neigh.des] = true;
                    q.push(neigh.des);
                }
            }
            // cout<<v<<" ";
            // ans -- >0 to all -->   0 1 7 2 6 8 3 5 4 
        }
    }

    //  normal bfs traversal 
    void bfs(int src){
        ump<int,bool>visited;
        helper(src,visited);
    }


    void ConnectedComponent() {
        ump<int,bool>visited;
        int ans=0;
        for(int i=0;i <this->V;i++) {
            if(not visited[i]) {
                helper(i,visited);
                ans++;
            }
        }
        cout<<"No of connected components are :: "<<ans<<endl;
    }

    
};

int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    Graph g(8);
    for(int i=0;i<13;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        g.addedge(u,v);
    }
    g.ConnectedComponent();
    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
    #endif 
    return 0;
}


/* 
Input for shotest path in binary weighted graph 

0 1 0
0 7 1
1 7 1
1 2 1
2 3 0
2 5 0
2 8 1
3 4 1
3 5 1
4 5 1
5 6 1
6 7 1
7 8 1

*/