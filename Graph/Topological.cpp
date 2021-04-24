#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph {
    public:
    int V;

    list<int>*adj;

    // vetor to store indegree 
    vector<int>ind;

    // contructor to initialize 
    Graph(int n) {
        this->V=n;
        this->adj=new list<int>[n];
        for(int i=0;i<this->V;i++){ind.push_back(0);}
    }

    // adding edge anc also calculating the indegree of each vertex 
    void addedge(int u,int v) {
        adj[u].push_back(v);
        ind[v]++;
    }

    // map to mark visited places 
    unordered_map<int,bool>visited;

    // topological function 
    void topological() {
        // start from vertex 
        for(int i=0;i<this->V;i++) {

            // if the indegree of vertx is zero and not visited 
            if(not visited[i] && ind[i]==0) {
                // mark the visited true 
                visited[i]=true;
                cout<<i<<" ";
                // now cut all edges of its neighbour which are connected 
                for(auto neighbour:this->adj[i]) {
                    ind[neighbour]--;
                }
                // call again function 
                topological();
            }
        }
    }

};
int main() {
    Graph g(6);
    g.addedge(5,2);
    g.addedge(5,0);
    g.addedge(4,0);
    g.addedge(4,1);
    g.addedge(2,3);
    g.addedge(3,1);
    g.topological();
    return 0;
}