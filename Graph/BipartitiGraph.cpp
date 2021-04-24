//SATYAM SINGH  
// Biparatite graph 
// problem link -->  https://leetcode.com/problems/possible-bipartition/
// problem link -->  https://leetcode.com/problems/is-graph-bipartite/
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

class Solution {
public:
    bool BFS(int src,int N,vector<int> &color ,list<int>adj[]) {
        // queue to do bfs traversal 
        queue<int>qq;
        // make that vertex of color 1 
        color[src] = 1;
        qq.push(src);
        while(not qq.empty()) {
            // pop out the top element from the queue 
            int v= qq.front();
            qq.pop();

            // traverse the neighbour vertex of the graph 
            for(auto neighbour : adj[v]) {
                // if vertex is already colore then check whether 
                // it is not the same color if yes then it is not possible to paritition the vertex 
                if (color[v] == color[neighbour]) return false;

                // if we have not visited the vertex then do color in oppsoite color of the adjancent vertex 
                if(color[neighbour] == -1 ){ 
                    color[neighbour] = 1- color[v];
                    // push it in the queue and repeat for the same steps 
                    qq.push(neighbour);
                }
            }
        }
        // finally return the ans 
        return true;
    }

    // function to return ans 
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        // create a adjancency list 
        list<int>adj[N+1];

        // add edges to graph 
        for(int i=0; i <dislikes.size() ; i++ ) {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        // make an vector of color to do patition 
        vector<int>color(N+1,-1);
        // traverse for all edges that are present there may be chances of disconnected component 
        for(int i = 1 ;i<=N ;i++) {

            // if color is -1 that means we have not visited that graph so visit it 
            if(color[i] == -1 ){
                // if some how value gets false then return else check for all componensts 
                if(not BFS(i,N+1,color,adj)) return false;
            }
        }
        return true;
    }
};


int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    vector<vector<int>> v{{1,2},{1,3},{2,4}};
    Solution s;
    cout<<s.possibleBipartition(4,v);
     

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
    #endif 
    return 0;
}
