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
    list<int>*tp;
    public:
    Graph(int v) {
        this->V = v;
        this->adj = new list<int>[v];
        this->tp = new list<int>[v];
    }

    void addedge(int u,int v) {
        this->adj[u].push_back(v);

        // pushing the tranpose 
        this->tp[v].push_back(u);
    }


    //  this is the whole code for th Kosaraju algorithm 
    void DFS(int src,stack<int> &st,ump<int,bool > &visited) {
        visited[src] = true;
        for(auto j:this->adj[src]) {
            if(not visited[j]) {
                DFS(j,st,visited);
            }
        }
        st.push(src);
    }

    void DFS2(int src,ump<int,bool> &visited) {
        visited[src] = true;
        cout<<src<<" ";
        for(auto neig:this->tp[src]){
            if(not visited[neig]) {
                DFS2(neig,visited);
            }
        }
    }

    // kosaraju algorithm to find the strongly connected components  O(V+E)
    void Kosaraju() {
        stack<int>st;
        ump<int,bool> visited;

        // call dfs to push elements in the stack 
        loop(i,0,this->V ) {
            if(not visited[i]) {
                DFS(i,st,visited);
            }
        }

        loop(i,0,this->V) {
            visited[i] = false;
        }

        cout<<"The strongly connected components are "<<endl;
        
        while(not st.empty()) {
            int v= st.top();
            st.pop();
            if(not visited[v]) {
                DFS2(v,visited);
                cout<<endl;
            }
        }
    }

    void TargenDFS(int src,vector<int> &disc,vector<int> &low,stack<int> &st,vector<bool> &Instack) {
        static int timer = 0;
        low[src] = disc[src] = timer;
        st.push(src);
        Instack[src] =true;
        timer+=1;

        for(auto j :this->adj[src]) {
            if(disc[j] == -1) {
                TargenDFS(j,disc,low,st,Instack);
                low[src] = min(low[src] , low[j]);
            }
            else if(Instack[j]) {
                low[src] = min(low[src],disc[j]);
            }
        }
        if(low[src] == disc[src]) {
            cout<<"SCC is ";
            while(st.top()!=src) {
                cout<<st.top()<<" ";
                Instack[st.top()] = false;
                st.pop();
            }
            cout<<st.top()<<endl;
            Instack[st.top()] = false;
            st.pop();
        }
    }

    void TargensAlgortihm() {
        vector<int>disc(this->V,-1),low(this->V,-1);
        stack<int>st;
        vector<bool>Instack(this->V,false);
        for(int i=0;i<this->V;i++) {
            if(disc[i] == -1) {
                TargenDFS(i,disc,low,st,Instack);
            }
        }
    }

    

    
};

int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    // strongly connected components  
    Graph g(7);
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(1,3);
    g.addedge(3,4);
    g.addedge(4,0);
    g.addedge(4,5);
    g.addedge(4,6);
    g.addedge(6,5);
    g.addedge(5,6);
    g.addedge(5,2);
    cout<<"Kosaraju algorithm"<<endl;
    g.Kosaraju();

    cout<<endl<<"Targens aLgorithm"<<endl;
    g.TargensAlgortihm();


    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
    #endif 
    return 0;
}
