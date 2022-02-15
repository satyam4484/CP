// problem link --> https://www.hackerrank.com/challenges/jack-goes-to-rapture/problem?isFullScreen=false
// dijiktra algorithm
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

void Dijiktra(vector<pair<int,int>>v[],int n) {
	vector<ll>dist(n+1,INT_MAX);
	dist[1] = 0;
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
	pq.push({0,1});
	while(pq.size() > 0) {
		int u = pq.top().second;
		ll d = pq.top().first;
		pq.pop();
		if(dist[u] < d) continue;
		for(auto neigh:v[u]){
			int des = neigh.first;
			ll we = (neigh.second - d > 0?neigh.second - d: 0);
			if(dist[des] > we + d){
				dist[des] = we+ d;
				pq.push({dist[des],des});
			}

		}
	}
	if(dist[n] == INT_MAX) cout<<"NO PATH EXISTS"<<endl;
	else cout<<dist[n]<<endl;
}

void Main() {
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>>v[n+1];
	for(int i=0;i<m;i++) {
		int a,b,c;
		cin>>a>>b>>c;
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}

	Dijiktra(v,n);
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