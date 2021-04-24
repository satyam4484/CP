#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Generic implementation of graph using unordered map 
//template for generic 
template<typename T>
// class graph 
class Graph{
    public:
    // list<pair<T,int>>
    // unordered map for graph 
    unordered_map<T , list<T> > adj;
    Graph(){
    }
    // function to add edge in graph 
    // by default we will make it bidirectional 
    void addedge(T n1,T n2,bool birdir=true){
        adj[n1].push_back(n2);
        // if we dont want bidirectional we can make it false 
        if(birdir){
            adj[n2].push_back(n1);
        }
    }
    // function to print the graph 
    void print(){
        // traverse the map 
        for(auto row :this->adj){
            cout<<row.first<<"-->";
            // now traverse the linked list which is the second part of map 
            for(auto el:row.second){
                cout<<el<<", ";
            }
            cout<<endl;
        }
    }
};
int main(){
    Graph<int>g;
    Graph<string>g1;
    g.addedge(1,2,false);
    g.addedge(3,2,false);
    g.addedge(4,2);
    g.addedge(1,4);
    g.addedge(1,3);
    g.print();
    return 0;
}