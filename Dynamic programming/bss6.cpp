//SATYAM SINGH
// problem link --> https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll                 long long int
#define pb                 push_back
#define mod                     1000000007
#define inf                     1e18
#define ump                unordered_map
#define mp                 make_pair
#define nline                 "\n"
#define all(v)                   v.begin(),v.end()

#define  inpv(v,n)  for(int i=0;i<n;i++) cin>>v[i]
#define  outv(v)    for(auto i:v) cout<<i<<' '
#define  loop(i,a,b)  for(int i=(a);i<(b);i++)
#define  looprev(i,a,b)  for(int i=(a);i>=0;i--)
#define log(args...)  {string _s = #args ;replace(_s.begin(),_s.end(),',',' ') ; stringstream _ss(_s); istream_iterator<string> _it(_ss) ; err(_it,args);}
void err(istream_iterator<string> it) {}
template<typename T, typename ... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}

void file_i_o()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif
}

// =============== CODE STARTS HERE DO NOT BOTHER ABOUT THE TEMPLATE IT"S FOR SIMPLICITY ==============================================================================================================================================
class Solution {
public:
	int maxProfit(int k, vector<int>& v) {
		int n = v.size();
		vector<vector<int>>dp(k + 1, vector<int>(n, 0));

		for (int i = 1; i <= k; i++) {
			int mx = INT_MIN;
			// outv(profit);
			// cout << endl;
			for (int j = 1; j < n; j++) {
				if (dp[i - 1][j - 1] - v[j - 1] > mx) {
					mx = dp[i - 1][j - 1] - v[j - 1];
				}
				if (mx + v[j] > dp[i][j - 1]) {
					dp[i][j] = mx + v[j];
				} else {
					dp[i][j] = dp[i][j - 1];
				}


			}
		}
		return dp[k][n - 1];
	}
};

void Main() {
	int n, k;
	cin >> n;
	vector<int>v(n);
	inpv(v, n);
	cin >> k;
	Solution s;
	cout << s.maxProfit(k, v);

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
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 100 << " seconds";
#endif
	return 0;
}