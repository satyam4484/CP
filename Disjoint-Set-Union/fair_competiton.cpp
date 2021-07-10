//SATYAM SINGH 
// problem link -- > https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/fair-competition-0315250e/ 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll                 long long int
#define pb                 push_back
#define mod                     1000000007
#define inf                     1e18
#define ump                unordered_map
#define mp                 make_pair
#define all(v)                   v.begin(),v.end()

#define  inpv(v,n)  for(int i=0;i<n;i++) cin>>v[i]
#define  outv(v)    for(auto i:v) cout<<i<<' ' 
#define  loop(i,a,b)  for(int i=(a);i<(b);i++)
#define  looprev(i,a,b)  for(int i=(a);i>=0;i--)
#define log(args...)  {string _s = #args ;replace(_s.begin(),_s.end(),',',' ') ; stringstream _ss(_s); istream_iterator<string> _it(_ss) ; err(_it,args);}
void err(istream_iterator<string> it) {}
template<typename T,typename ... Args>
void err(istream_iterator<string> it, T a,Args... args) {
      cout<<*it<<" = "<<a<<endl;
   err(++it,args...);
}

void file_i_o()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

int find(vector<int>&parent,int a) {
    if(parent[a] == -1) return a;
    return parent[a] = find(parent,parent[a]);
}

void unions(vector<int>&parent,vector<int>&rank,int a,int b) {
    a = find(parent,a);
    b = find(parent,b);
    if(a == b) return ;
    parent[b] = a;
    rank[a]+=rank[b];
}

int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>parent(n+1,-1) , rank(n+1,1);
        loop(i,0,m) {
            int a,b;
            cin>>a>>b;
            unions(parent,rank,a,b);
        }

        // outv(rank);
        // cout<<endl;
        // outv(parent);
        // cout<<endl;
        vector<int>ans;
        loop(i,1,n+1) {
            if(parent[i] == -1) ans.push_back(rank[i]);
        }
        int totalans = 0;
        for(int i=0;i<ans.size()-1;i++) {
            for(int j=i+1;j<ans.size();j++) {
                totalans+=ans[i]*ans[j];
            }
        }
        cout<<totalans*2<<endl;
    }

    
     

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*100<<" seconds";
    #endif 
    return 0;
}