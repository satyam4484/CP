#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// number of trees inside a forest (no of connected component )

class Graph{
public:
	int V;
	list<int>*adj;
	Graph(int n)
	{
		this->V=n;
		this->adj=new list<int>[n];
	}

	void addedge(int u,int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	// dfs traversal 
	void dfshelper(int src,unordered_map<int,bool>&visited){
		visited[src]=true;
		for(auto neighbour:this->adj[src]){
			if(not visited[neighbour]){
				dfshelper(neighbour,visited);
			}
		}
	}

	// function to count the no of trees 
	int dfs(){
		int trees=0;
		// just traverse the graph for different set of vertices 
		// when one dfs will be complete it will give one tree 
		// so how many times the dfs is called that number of trees will be present inside the forest 
		unordered_map<int,bool>visited;
		for(int i=0;i<this->V;i++){
			if(not visited[i]){
				dfshelper(i,visited);
				// after completeion of each dfs the no of trees will be counted 
				trees++;
			}
		}
		// 
		return trees;
	}
};

int main(){
	Graph g(9);
	g.addedge(0,1);
	g.addedge(0,2);

	g.addedge(3,3);

	g.addedge(4,4);

	g.addedge(5,6);
    
	g.addedge(7,8);
	cout<<g.dfs();  // 5
}