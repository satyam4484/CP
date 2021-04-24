
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
    // directed graph 
    void addedge(int u,int v,bool bidir=true){
        adj[u].push_back(v);
    }
    // dfs traversal 
    void dfshelper(int src,int des,int &count){
        if(src==des){count++;}
        else {
            for(auto neighbour :this->adj[src]) {
                dfshelper(neighbour,des,count);
            }
        }  
    }
    int countpath(int src,int des){
        int count=0;
        dfshelper(src,des,count);
        return count;
    }
};

int main(){
   Graph g(5);
   g.addedge(0,1);
   g.addedge(0,2);
   g.addedge(0,3);
   g.addedge(1,3);
   g.addedge(2,3);
   g.addedge(2,1);
   g.addedge(1,4);
   g.addedge(2,4);
    cout<<g.countpath(0,3);   // 4
    return 0;
}