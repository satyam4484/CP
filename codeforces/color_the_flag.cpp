//SATYAM SINGH  
// problem link  --> https://codeforces.com/problemset/problem/1534/A
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

void display(vector<vector<int>>&v) {
    for(auto i:v) {
        for(auto j:i) {
            if(j) cout<<"R";
            else cout<<"W";
        }
        cout<<endl;
    }
}

bool getans(vector<vector<int>>&grid,vector<vector<int>>&v) {
    for(int i=0;i<grid.size();i++) {
        for(int j=0;j<grid[0].size();j++) {
            if(grid[i][j]!= -1 and grid[i][j]!=v[i][j]) {
                return false;
            }
        }
    }
    return true;
}
int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        vector<vector<int>>grid(n,vector<int>(m,0));

        // R -- > 1
        // W -- >0 
        // bla-- > -1


        loop(i,0,n) {
            loop(j,0,m) {
                char c;
                cin>>c;
                if(c == '.') grid[i][j] = -1;
                else if(c == 'R') grid[i][j] = 1;
                else grid[i][j] = 0;
            }
        }

        vector<vector<int>>ans(n,vector<int>(m,0));
        loop(i,0,n ) {
            bool even = 0;
            if(i & 1) even = 1;

            loop(j,0,m) {
                ans[i][j] = even;
                even = 1-even;
            }
        }

        if(getans(grid,ans)) {
            cout<<"YES"<<endl;
            display(ans);
        } else {
            loop(i,0,n ) {
                bool even = 1;
                if(i & 1) even = 0;

                loop(j,0,m) {
                    ans[i][j] = even;
                    even = 1-even;
                }
            }
            if(getans(grid,ans)) {
                cout<<"YES"<<endl;
                display(ans);
            } else cout<<"NO"<<endl;
        }


    }
     

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*100<<" seconds";
    #endif 
    return 0;
}