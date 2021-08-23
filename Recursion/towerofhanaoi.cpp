//SATYAM SINGH  
// problem link --> https://www.codingninjas.com/codestudio/guided-paths/competitive-programming/content/148627/offering/1792819
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

// =============== CODE STARTS HERE DO NOT BOTHER ABOUT THE TEMPLATE IT"S FOR SIMPLICITY ==============================================================================================================================================
void solve(int n,int src,int help,int dest,vector<vector<int>>&ans) {
	if(n == 1) {
		ans.push_back({src,dest});
		return ;
	}
	solve(n-1,src,dest,help,ans);
	ans.push_back({src,dest});
	solve(n-1,help,src,dest,ans);
}
vector<vector<int>> towerOfHanoi(int n)
{
    vector<vector<int>>ans;
    solve(n,1,2,3,ans);
    return ans;
}


void Main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		vector<vector<int>>ans  = towerOfHanoi(n);
		for(auto i:ans) {
			outv(i);
			cout<<endl;
		}
	}
	
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