//SATYAM SINGH  
// problem link-->https://codeforces.com/contest/1530/submission/122847650
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


int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n;
    cin>>n;
    for(int t=0;t<n;t++) {
        int r,c;
        cin>>r>>c;
        vector<vector<char>>v(r,vector<char>(c,'0'));
        for(int i=0;i<r;i+=2) {
            for(int j=0;j<c;j++) {
                if(i == 0 or i==r-1) {
                    if(v[(i-1>=0?i-1:0)][j] != '1') v[i][j] = '1';
                    j++;
                }
                if(j==0 or j==c-1) {
                    if(v[i][(j-1>=0?j-1:0)]!='1') v[i][j] = '1';
                }
            }
        }

        if(r%2==0) {
            for(int j=2;j<c-2;j+=2) v[r-1][j] = '1'; 
        }

        for(auto i:v) {
            for(auto j:i) cout<<j;
            cout<<endl;
        }
        cout<<endl;
    }
     

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*100<<" seconds";
    #endif 
    return 0;
}