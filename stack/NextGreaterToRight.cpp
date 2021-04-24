//SATYAM SINGH
#include <iostream>
#include <bits/stdc++.h>
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
#define  looprev(i,a,b)  for(int i=(a);i>=(b);i--)

void file_i_o()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void nextgreater(vc<int> &v, vc<int> &ans, int n)
{
	stack<int> st;
	looprev(i, n - 1, 0)
	{
		if (st.size() == 0)
		{
			ans.pb(-1);
		}
		else if (st.size() > 0 and st.top() > v[i])
		{
			ans.pb(st.top());
		}
		else if (st.size() > 0 and st.top() <= v[i])
		{
			while (st.size() > 0 and st.top()<= v[i])
			{
				st.pop();
			}
			if (st.size() == 0)
			{
				ans.pb(-1);
			}
			else {
				ans.pb(st.top());
			}
		}
		st.push(v[i]);
	}
}
int main()
{
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	int n;
	cin >> n;
	vc<int> v(n);
	inpv(v, n);
	vc<int> ans;
	nextgreater(v, ans, n);
	reverse(ans.begin(),ans.end());
	loop(i,0,n) {
		cout<<v[i]<<" "<<ans[i]<<endl;
	}

	// code ends here !!!!!!
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC << " seconds";
#endif
	return 0;
}
