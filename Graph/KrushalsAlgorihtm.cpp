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

// krushals algorithm for minimum spanning tree TC (ElogE + ElogV )
class KrushkalsAlgo{
    public:
    
    // function to display the mst 
    void display(vector<pair<int,pair<int,int>>>&adj ) {
        int sum = 0;
        // tarverse the pair of mst and print the path with sum 
        for(auto i:adj) {
            cout<<i.second.first<<"-->"<<i.second.second<<"=="<<i.first<<endl;
            sum+=i.first;
        }
        cout<<"total :: "<<sum<<endl;
    
    } 
    
    // find method of disjoint set 
    int findp(int val,vector<pair<int,int>>&parent) {
        if(parent[val].first == -1) return val;
        return parent[val].first =  findp(parent[val].first,parent);
    }

    // union method of disjoint set 
    void unionP(int u,int v,vector<pair<int,int>>&parent ) {
        if(parent[u].second > parent[v].second ) {
            parent[v].first = u;
        } else if(parent[u].second < parent[v].second) {
            parent[u].first = v;
        } else {
            parent[u].first = v;
            parent[v].second+=1;
        }
    }

    // main function for krushals algo 
    void mainAlgo(int v,vector<pair<int,pair<int,int>>>&adj) {
        // step 1 :sort the vector in ascending order 
        sort(adj.begin(),adj.end());

        // vector to store the minimum spanning tree 
        vector<pair<int,pair<int,int>>>ans;

        // we are going to use disjoint set algo using rank compression which will take O(log v ) to determint the cycle
        vector<pair<int,int>>Ds(v,{-1,0});

        int i=0,j=0,n=adj.size();

        // tarverse while there are v-1 edges in spannig tree 
        while(i<v-1 and j<n) {

            // get the parent of start 
            int from = findp(adj[j].second.first,Ds);
            // get the parent of end 
            int to = findp(adj[j].second.second,Ds);
            // if there parents are same then they contain a cyclce dont add to mst continue 
            if(from  == to ) {
                j++;
                continue;
            }
            // else make union of them 
            unionP(from,to,Ds);
            // push to mst and increase the no of count of mst vertices 
            ans.push_back(adj[j]);
            i++;
        }
        display(ans);
    }

};


int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    // get the number of edges and vertices 
    int v,e;
    cin>>v>>e;

    // create a pair of vectors ,you can also use the structure to define the graph 
    vector<pair<int,pair<int,int>>> graph;
    loop(i,0,e) {
        int a,b,c;
        cin>>a>>b>>c;
        graph.pb({c,{a,b}});
    }

    KrushkalsAlgo kl;
    kl.mainAlgo(v,graph);

     

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
    #endif 
    return 0;
}

// test case 
// 7 9
// 0 1 28
// 1 2 16
// 1 6 14
// 6 4 24
// 6 3 18
// 3 2 12
// 3 4 22
// 4 5 25
// 5 0 10