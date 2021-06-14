//SATYAM SINGH  
// problem link -- > https://www.spoj.com/problems/LCA/
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

void storeparent(vector<int>&parent,int n,vector<vector<int>> &dp) {
    for(int i=1 ;i<=n ;i++) {
        for(int j=0; j < log2(n) ;j++) {
            if(j == 0) dp[i][j] = parent[i];
            else dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }

    // for(auto i:dp) {
    //     for(auto j:i) {
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
}

int ancestor(int u,int v , vector<int>&lv,int n,vector<vector<int>> &dp) {
    if(lv[u] < lv[v]) {
        swap(u,v);
    }
    int diff = lv[u] - lv[v];
    for(int i=0;i<log2(n);i++) {
        if((1<<i) & diff) {
            u = dp[u][i];
        }
    }

    if(u == v) return u;
    // cout<<u;

    for(int i= log2(n)-1; i>=0 ;i--) {
        if(dp[u][i] != dp[v][i]) {
            u = dp[u][i];
            v = dp[v][i];
        }
    }

    return dp[u][0];
}


int main( ) {
    clock_t begin = clock();
    // file_i_o();
    // Write your code here....
    int t;
    cin>>t;
    for(int k=1; k<=t; k++) {
        int n;
        cin>>n;
        vector<int>p(n+1),lv(n+1,0);
        p[1] = 1;
        for(int i=1;i<=n;i++) {
            int m;
            cin>>m;
            loop(j,0,m) {
                int x;
                cin>>x;
                p[x] = i;
                lv[x] = lv[i]+1;
            }
        }
        vector<vector<int>>dp(n+1,vector<int>(log2(n)));
        storeparent(p,n,dp);
        int q;
        cin>>q;
        cout<<"Case "<<k<<":"<<endl;
        while(q--) {
            int u,v;
            cin>>u>>v;
            cout<<ancestor(u,v,lv,n,dp)<<endl;
        }
    }


     

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*100<<" seconds";
    #endif 
    return 0;
}