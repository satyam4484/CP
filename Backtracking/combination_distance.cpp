//SATYAM SINGH  

// the complexcity of the algorithm is exponential since every places we have two choices 
// approx -> 2^n*n;

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

// =============================================================================================================================================================
bool ans = false;
void solve(vector<int>&v,int x,int n){
    if(x>n) {
        ans = true;
        outv(v);
        cout<<endl;
    }
    for(int i=0;i<2*n;i++) {
        if(v[i] == -1 and (i+x+1)<2*n and v[i+x+1] == -1) {
            v[i] = x,v[i+x+1]=x;
            solve(v,x+1,n);
            v[i] = -1,v[i+x+1]=-1;

        }
    }
}
void Main() {
    int n;
    cin>>n;
    vector<int>v(2*n,-1);
    solve(v,1,n);
    if(not ans) cout<<"Answer does not exist"<<endl;

    
}


// ============================================================================================================================
int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    
     Main();

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*100<<" seconds";
    #endif 
    return 0;
}