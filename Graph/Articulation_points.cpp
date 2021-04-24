//SATYAM SINGH  

// articulaton points 
// problem link --> https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/practice-problems/algorithm/rhezo-and-destructive-mind/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll 				long long int
#define pb 				push_back
#define mod             1000000007
#define inf             1e18
#define vi              vector<int>
#define vL              vector<ll>
#define vs             vector<string>
#define ump				unordered_map
#define mp 				make_pair
#define all(v)           v.begin(),v.end()

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

    void addedge(int u,int v) {
        this->adj[u].pb(v);
        this->adj[v].pb(u);
    }


    void helper(int u,vi &parent,vi &low,vi &desc,vector<bool>&pt) {
        static int timer = 0;
        low[u] = desc[u] = timer;
        timer++;
        int children = 0;

        for(int v :this->adj[u]) {
            if(desc[v] == -1) {
                children++;
                parent[v] = u;
                helper(v,parent,low,desc,pt);
                low[u] = min(low[u],low[v]);

                if(parent[u] == -1 and children>1) {
                    pt[u] =true;
                }

                if(parent[u] !=-1 and low[v] >= desc[u]) {
                    pt[u] = true;
                }
            } else if(v!=parent[u]) {
                low[u] = min(low[u],desc[v]);
            }
        }
    }


    void FindArticulation(vector<bool>&pt) {
        vi parent(this->V,-1) ,low(this->V,-1),desc(this->V,-1);

        loop(i,1,this->V) {
            if(desc[i] == -1) {
                helper(i,parent,low,desc,pt);
            }
        }
    }

    void satisfied(int x) {
        int count =0;
        for(int v:this->adj[x]) {
            count++;
        }
        cout<<"Satisfied "<<count<<endl;
    }

};
int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    // Articulation points  
    int v,e,q;
    cin>>v>>e;
    Graph g(v+1);
    loop(i,0,e) {
        int a,b;
        cin>>a>>b;
        g.addedge(a,b);
    }
    vector<bool>pt(v+1,false);
    g.FindArticulation(pt);
    cin>>q;
    loop(i,0,q) {
        int x;
        cin>>x;
        if(pt[x] == true ) g.satisfied(x);
        else cout<<"Not Satisfied"<<endl;
    }


    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
    #endif 
    return 0;
}
