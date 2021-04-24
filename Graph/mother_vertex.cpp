// mother vertex - a vertex from graph through which we can visit any vertex in a graph 
// if no vertex exist then return -1
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    int V;
    list<int>*adj;

    Graph(int n){
        this->V=n;
        this->adj=new list<int>[n];
    }

    void addedge(int u,int v,bool bidir=true){
        adj[u].push_back(v);
        if(bidir){
            adj[v].push_back(u);
        }
    }
    // a dfs function 
    void dfshelper(int src,unordered_map<int,bool> &visited){
        visited[src]=true;
        for(auto neighbour:this->adj[src]){
            if(not visited[neighbour]){
                dfshelper(neighbour,visited);
            }
        }
    }
    // we will traverse with each vertex and mark it true and store the vertex 
    // if there  is no path then dfs will call again from new vertex
    int mothervertex(){
        unordered_map<int ,bool>visited;
        int v=0;
        for(int i=0;i<this->V;i++){
            if(not visited[i]){
                dfshelper(i,visited);
                v=i;
            }
        }
        // once we will complete will mark the vertices univisted and will visit again with previous vertex stored 
        // if it will visited through all the vextex then it will be the mother vertex otherwise no vertex exist 
        for(int i=0;i<this->V;i++){
            visited[i]=false;
        }
        dfshelper(v,visited);
        // checking the final conditon to see whehter the vertex is mother or not 
        for(int i=0;i<this->V;i++){
            if(not visited[i]){
                return -1;
            }
        }
        return v;
    }
};

int main(){
    /* Exampe 1: */
    Graph g(7);
    g.addedge(0,1 ,false);
    g.addedge(0,2 ,false);
    g.addedge(1,3 ,false);
    g.addedge(4,1 ,false);
    g.addedge(6,4 ,false);
    g.addedge(5,6 ,false);
    g.addedge(5,2 ,false);
    g.addedge(6,0 ,false);
    cout<<g.mothervertex(); //5 
    cout<<endl;

    
    /* example 2: */ 

    Graph g1(6);
    g1.addedge(0,1,false);
    g1.addedge(2,1,false);
    g1.addedge(1,5,false);
    g1.addedge(2,5,false);
    g1.addedge(3,0,false);
    cout<<g1.mothervertex();  // -1
    return 0;
}