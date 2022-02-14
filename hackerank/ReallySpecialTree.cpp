// problem link --> https://www.hackerrank.com/challenges/kruskalmstrsub/problem?isFullScreen=false
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
#define ppi pair<int,pair<int,int>>


void file_i_o()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}


int  FindParent(int a,vector<int>&parent) {
	if(parent[a] == -1) return a;
	return parent[a] = FindParent(parent[a],parent);
}

void Union(int a,int b,vector<int>&parent,vector<int>&rank) {
	a = FindParent(a,parent);
	b = FindParent(b,parent);
	if(rank[a] > rank[b]) parent[b] = a;
	else if(rank[a] < rank[b]) parent[a] = b;
	else{
		parent[b] = a;
		rank[a]++;
	}
}



void Main() {
	int n,m;
	cin>>n>>m;
	vector<ppi>v;
	for(int i=0;i<m;i++) {
		int a,b,c;
		cin>>a>>b>>c;
		v.push_back({c,{a,b}});
	}

	int ans = 0,count = 0;
	sort(v.begin(),v.end());
	vector<int>parent(n+1,-1),rank(n+1,0);
	for(auto i:v) {
		if(count == n-1) break;
		int u = i.second.first;
		int v = i.second.second;
		int w = i.first;

		if(FindParent(u,parent) != FindParent(v,parent)) {
			Union(u,v,parent,rank);
			count++;
			ans+=w;
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