//SATYAM SINGH  
// problem link  --> https://www.codechef.com/submit/DISHOWN
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll 				long long int
#define pb 				push_back
#define mod             1000000007
#define inf             1e18
#define vi              vector<ll>
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

int Get(vi &parent,int a) {
    return parent[a] = (parent[a] == a?a:Get(parent,parent[a]));
}

void Union_(vi &parent,vi &score,int a,int b) {
    a = Get(parent,a);
    b= Get(parent,b);
    if(score[a] > score[b]) {
        parent[b] = a;
    } else if(score[a] < score[b] ) {
        parent[a] = b;
    }
}
int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vi v(n+1);
        v[0] =0;
        loop(i,1,n+1) {
            cin>>v[i];
        }
        int q;
        cin>>q;
        vi parent(n+1);
        loop(i,1,n+1) parent[i] = i;
        while(q--) {
            int a;
            cin>>a;

            if(not a) {
                int x,y;
                cin>>x>>y;
                ll m = Get(parent,x);
                ll p =Get(parent,y);
                if(m == p ) {
                    cout<<"Invalid query!"<<endl;
                } else {
                    Union_(parent,v,m,p);
                }
            } else {
                int c;
                cin>>c;
                cout<<Get(parent,c)<<endl;
            }
        }
        // cout<<endl;
        // outv(parent);
    } 

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
    #endif 
    return 0;
}
