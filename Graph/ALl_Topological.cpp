#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// All topological sort 
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
    unordered_map<int,bool>visited;
    vector<int>ans;

    // function
    void Topp_func() {

        // flag value to check whether we have visited or not all the vextex 
        bool flag=false;
        for(int i=0;i<this->V;i++) {

            // if not visited the vertex and its indegree is 0 then visit it 
            if(not visited[i] and ind[i]==0) {
                visited[i]=true;
                ans.push_back(i);
                // disconnect it edges from its neighbours 
                for(auto neighbour:this->adj[i]) {
                    ind[neighbour]--;
                }

                // traverse again 
                Topp_func();

                // we are backtracking to previous vertex 
                visited[i]=false;
                // remove from the ans 
                ans.erase(ans.end()-1);
                // add the edges that we have deleted 
                for(auto neighbour:this->adj[i]) {
                    ind[neighbour]++;
                }
                // this indicate we have visted the the vertex 
                flag=true;
            }
        }

        // print the ans 
        if(not flag) {
            for(auto i:ans) {
                cout<<i<<" ";
            }
            cout<<endl;
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
    g.Topp_func();
    return 0;
}