// problem link --> https://www.hackerrank.com/challenges/synchronous-shopping/problem
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

#define ppi pair<int,pair<int,int>>


void Main() {
	int n,m,k;
	cin>>n>>m>>k;
	vector<int>fish(n+1,0); // bitmask for fishes 

    // store the fishes in mask
	for(int i=1;i<=n;i++) {
		int t;
		cin>>t;
		while(t--) {
			int x;
			cin>>x;
			fish[i] |= (1<<(x-1));
		}
	}

    // graph for connected roads 

	vector<pair<int,int>>adj[n+1];
	for(int i=0;i<m;i++) {
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}

    // 2d matrix to store the state (n,msk)  (curr vertex, no of fishes till these vertex )
	vector<vector<int>>dp(n+1,vector<int>(1024,INT_MAX));

    // priority queue for dijktra traversal 
	priority_queue<ppi,vector<ppi>,greater<ppi>>pq;

	pq.push({0,{1,fish[1]}});
	dp[1][fish[1]] = 0;

	while(pq.size() > 0) {
		int u = pq.top().second.first;
		int d =pq.top().first;
		int msk = pq.top().second.second;
		pq.pop();
		if(d > dp[u][msk]) continue; // if the dist is greater which means we already have an smaller distance so continue  
		for(auto neigh:adj[u]) {
			int v = neigh.first;
			int w = neigh.second;
			int newmsk = msk | fish[v];  // new mask from source to des 
			if(dp[v][newmsk] > d + w) {
				dp[v][newmsk] = d +w;
				pq.push({d+w,{v,newmsk}});
			}
		} 
	}

	int ans = INT_MAX;

    // check for the 2 cats that when they combine collects all the fishes we need to calculate the ans 
	for(int i=0;i<(1<<k);i++) {
		for(int j=i;j<(1<<k);j++) {
			if((i|j) == ((1<<k)-1)) {
				ans = min(ans,max(dp[n][i],dp[n][j]));  // max of two because we need to find the cat which came late 
			}
		}
	}
	cout<<ans<<endl;
}

int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    Main();

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
    #endif 
    return 0;
}