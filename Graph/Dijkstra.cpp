// dijisktra shortest path algo implementation 
//SATYAM SINGH  

// problem link --> https://codeforces.com/problemset/problem/20/C
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll 				long long int
#define pb 				push_back
#define mod             1000000007
#define inf             1e18
#define ppi             pair<int,int>
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


// create a node for destination and source 
struct node {
    int des,weight;
};

class Graph {
    int V;
    // create a list of nodes 
    list<node>*adj;
    public:

    // constructor to initialise it 
    Graph(int v) {
        this->V = v;
        this->adj = new list<node>[v];
    }

    // function to addedge 
    void addedge(int u,int v,int w) {
        this->adj[u].pb({v,w});
        this->adj[v].pb({u,w});
    }

    // main function for dijisktra shortest path algo 

    void main(int src) {

        // create a min heap which will give us the minimum distance 
        // make it as pair os weight,des 
        priority_queue<ppi,vector<ppi>,greater<ppi>>pq;
        // array to store the values initially all are infinity 
        vector<int>value(this->V,INT_MAX);
        // mark ditance of source as 0
        vector<int>parent(this->V,-1);
        value[src] = 0;

        // push the source 
        pq.push({0,src});

        // travsere while heap becomes empty 
        while(not pq.empty()) {
            // take the destination vertex 
            int u = pq.top().second;
            pq.pop();

            // traverse its adjacent vertex 
            for(auto j :this->adj[u]) {
            
                int des = j.des;
                int weight = j.weight;
                // if current value plus weight is less then the original values of array then update it and push it in the heap 
                if(value[u] + weight < value[des]) {
                    value[des] = value[u] + weight;
                    parent[des] = u;
                    pq.push({value[des],des});
                }
            }
        }

        // finally print the shortest path according to requirement 
        // loop(i,1,this->V) {
        //     cout<<src<<" --> "<<i<<" == "<<value[i]<<endl;
        // }
        if(value[this->V-1] == INT_MAX) cout<<-1<<endl;
        else {
            vector<int>ans;
            for(int i=this->V-1;i!=1;i=parent[i] ){
                ans.pb(i);
            }
            ans.push_back(1);
            reverse(ans.begin(),ans.end());
            outv(ans);

        }

    }
};


int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int v,e;
    cin>>v>>e;
    Graph g(v+1);
    loop(i,0,e) {
        int a,b,c;
        cin>>a>>b>>c;
        g.addedge(a,b,c);
    }

    g.main(0);
     

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
    #endif 
    return 0;
}
