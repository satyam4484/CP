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
class PrimsAlgo {
    public:
    int  minimumMst(vector<int> &weight,ump<int,bool> &visited,int v) {
        int minimum = INT_MAX;
        int vertex;
        loop(i,0,v) {
            if(not visited[i] and weight[i] < minimum) {
                vertex =i;
                minimum = weight[i];
            }
        }
        return vertex;
    }
    void PrimsMSt(int vertex,vector<vector<int> >&graph ) {
        // lets create a parent array to print the ans of minimum spanning tree 
        vector<int>ans(vertex);
        // a weighted array to keep track of minimum weights 
        vector<int>weight(vertex,INT_MAX);
        // a map to mark visited vertex 
        ump<int,bool>visited(vertex);
        
        //initially we can mark the intial vertex as 0
        ans[0] = -1;
        weight[0] = 0;
        // since a minium spanning tree contains (v-1) edges we will repeat our process for v-1 times 

        loop(i,0,vertex-1) {

            // get the minimum vertex from graph 
            int from = minimumMst(weight,visited,vertex);
            // mark that visited 
            visited[from] = true;

            // travel the adjacent vertices and check for minimum vertex from that adjacent vertex 
            loop(to,0,vertex) {
                if(not visited[to] and graph[from][to]!= 0  and graph[from][to] < weight[to] ) {
                    ans[to] = from;
                    weight[to] = graph[from][to];
                }
            }
        }

        // lets print the minimum spanning 
        int sum = 0;
        loop(i,1,vertex) {
            cout<<"From vertex "<<ans[i]<<" --- > "<<i<<" with weight == "<<weight[i]<<endl;
            sum+=weight[i];
        }
        cout<<"with total weight == "<<sum<<endl;
    }
};

// minimum spanning tree using matrix and prims algorithm 
int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int v,e;
    cin>>v>>e;
    vector<vector<int> >graph (v,vector<int>(v,0));
    loop(i,0,e) {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a][b] = c;
        graph[b][a] = c;
    }
    PrimsAlgo P;
    P.PrimsMSt(v,graph);

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
    #endif 
    return 0;
}


/* Test cases 

1::
7 9
0 1 28
1 2 16
1 6 14
6 4 24
6 3 18
3 2 12
3 4 22
4 5 25
5 0 10

2 ::

*/