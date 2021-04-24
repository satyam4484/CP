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

class Detect {
    public:


    // the approach uses  O (n) time 
    int find(int v,vector<int>&Ds) {
        // if the value is -1 then we have not visited then directly return from here 
        if(Ds[v] == -1) return v;
        // else travel to its value which will give the ans 
        return find(Ds[v],Ds);
    }
    // these method is used to add the parent 
    void unionofTwo(int u,int v,vector<int>&Ds) {
        //find the parent of start 
        int from = find(u,Ds);
        //find the parent of end 
        int to = find(v,Ds);
        // add any one of them as parent of other 
        Ds[from] = to;
    }
    // function to check the cycle is present or not 
    bool DetectCycle(int ver,vector<pair<int,int>>&v) {
        // emoty vector to mark the parent child relationship 
        vector<int>DS(ver,-1);

        // traverse the given graph 
        for(auto value : v) {

            // find the parent 
            int from = find(value.first,DS);
            int to = find(value.second,DS);

            // if parent is same then they contain a cycle and return directly
            if(from  == to ) return true;
            // else join them s
            unionofTwo(from,to,DS);
        }
        return false;
    }

    // optimised version of Disjoint set union method using rank compression

    int FIND(int val,vector<pair<int,int> >&v) {
        // same as above 
        if(v[val].first == -1) return val;

        // once we get the parent we know that we can direclyt reach to parent by pointing 
        // directly to it so point it direclty to parent which inshort reduces time 
        return v[val].first = FIND(v[val].first,v);
    } 

    // union function to join two differents sets 

    void UNION(int u,int w,vector<pair<int,int> >&v) {
        // we will always choose the rank with minimum value 
        if(v[u].second > v[w].second ) {
            v[w].first = u;
        } else if(v[u].second < v[w].second ) {
            v[u].first = w;
        } else {
            // if the rank i same then add to any one of them and increase the rank of second 
            v[u].first = w;
            v[w].second+=1;
        }
    }
    bool RankCompression(int V,vector<pair<int,int>>&v) {
        vector<pair<int,int>>Ds(V,{-1,0});
        // rest all the methods are same 
        for(auto val:v) {
            int from  = FIND(val.first,Ds);
            int to  = FIND(val.second,Ds);
            if(from == to ) return true;

            UNION(from,to,Ds);
        }
        return false;
    }

};

int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    vector<pair<int,int>> v; 
    v.push_back({0,1});
    v.push_back({1,2});
    v.push_back({2,3});
    v.push_back({3,4});
    v.push_back({4,5});
    v.push_back({5,0});
    Detect g;
    // if(g.DetectCycle(6,v)) cout<<"TRUE\n";
    // else cout<<"NO\n";
    if(g.RankCompression(6,v)) cout<<"TRUE\n";
    else cout<<"NO\n";

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
    #endif 
    return 0;
}
