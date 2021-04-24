//SATYAM SINGH  
// problem  link --> https://leetcode.com/problems/online-stock-span/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll 				long long int
#define pb 				push_back
#define mod             1000000007
#define inf             1e18
#define ump				unordered_map
#define mp 				make_pair
#define vc               vector

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
void solve (vc<int> &v,vc<int> &ans) {
	stack<pair<int,int>>st;
	for(int i=0;i<v.size( ) ; i++ ){
		if(st.size() == 0) {
			ans.pb(-1);
		}
		else if(st.size() > 0 and st.top().first > v[i] ) {
			ans.push_back(st.top().second);
		}
		else if(st.size() > 0 and st.top().first <= v[i]) {
			while(st.size() > 0 and st.top().first <= v[i]) {
				st.pop();
			}
			if(st.size() ==0) ans.push_back(-1);
			else ans.push_back(st.top().second);
		}
		st.push(mp(v[i],i));
	}
	for(int i=0;i<ans.size() ; i++) {
		ans[i] = i-ans[i];
	}

}

int main( ) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	vc<int>v{10, 4, 5, 90, 120, 80 }; 
	vc<int>ans;
	solve(v,ans);
	outv(ans);

// code ends here !!!!!! 
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
	#endif 
	return 0;
}
