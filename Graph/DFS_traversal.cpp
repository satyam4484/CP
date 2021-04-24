#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int V; // no of vertices 
    list<int>*adj;
    Graph(int n){
        this->V=n;
        this->adj=new list<int>[V];
    }
    // function to add edge 
    // by defualt we will made birectional 
    void addedge(int u,int v,bool bidir=true){
        adj[u].push_back(v);
        if(bidir){
            adj[v].push_back(u);
        }
    }
    // a helper function for dfs traversl 
    void dfsHelper(int src,unordered_map<int,bool>& visited){
        visited[src]=true;
        cout<<src<<" ";
        for(auto neighbour:this->adj[src]){
            if(not visited[neighbour]){
                dfsHelper(neighbour,visited);
            }
        }
    }
    //  function for dfs and visited places 
    void Dfs(int src){
        unordered_map<int,bool>visited;
        dfsHelper(src,visited);
    }
};
// 
int main(){
    Graph G(6);
    G.addedge(1,2);
    G.addedge(2,4);
    G.addedge(2,3);
    G.addedge(4,5);
    G.Dfs(1);
    return 0;
}