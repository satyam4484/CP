//SATYAM SINGH  
// problem link --> https://www.codingninjas.com/codestudio/problems/rat-in-a-maze-all-paths_758966?topList=striver-sde-sheet-problems&leftPanelTab=0
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
int row[] = {0,0,1,-1};
int col[] = {1,-1,0,0};

bool valid(int r,int c,vector<vector<int>>&maze,int n) {
	return (r>=0 and c>=0 and r<n and c<n and maze[r][c] ==1);
}

void solve(vector<vector<int>>&maze,int r,int c,vector<vector<int>>&ans,vector<pair<int,int>>&v,int n) {
	if(r == n-1 and c==n-1) {
		vector<vector<int>>a(n,vector<int>(n,0));
		for(auto i:v) {
			a[i.first][i.second] = 1;
		}
		a[r][c] = 1;
		vector<int>k;
		for(auto i:a) {
			for(auto j:i) {
				k.push_back(j);
			}
		}
		ans.push_back(k);
		return ;
	}
	v.push_back({r,c});
	maze[r][c] = 0;

	for(int i=0;i<4;i++) {
		if(valid(row[i] +r,col[i] + c,maze,n)) {
			solve(maze,r+row[i],c+col[i],ans,v,n);
		}
	}

	v.pop_back();
	maze[r][c] = 1;

}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  vector<vector<int>>ans;
  vector<pair<int,int>>v;
  if(maze[0][0] == 0) return ans;
  solve(maze,0,0,ans,v,n);
  return ans;
}

void Main() {
	int n;
	cin>>n;
	vector<vector<int>>v(n,vector<int>(n));
	loop(i,0,n) {
		loop(j,0,n) {
			cin>>v[i][j];
		}
	}
	vector<vector<int>>ans = ratInAMaze(v,n);
	for(auto i:ans){
		outv(i);
		cout<<endl;
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