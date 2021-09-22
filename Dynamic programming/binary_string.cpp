//SATYAM SINGH
// problme link https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/count-binary-strings-official/ojquestion
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


// recursive approach
/*
void solve(int n, bool val, ll &count) {
if (n == 0) {
	count++;
	return;
}
if (val) {
	solve(n - 1, false, count);
	solve(n - 1, true, count);
} else {
	solve(n - 1, true, count);
}
}

void Main() {
int n;
cin >> n;
ll  count = 0;
solve(n - 1, false, count);
solve(n - 1, true, count);
cout << count << endl;
}
*/

// memoziation approach
/*

int solve(int n, int &val, vector<vector<int>>&dp) {
	if (n == 0) {
		return 1;
	}
	if (dp[n][val] != -1) return dp[n][val];
	if (val) {
		dp[n][val] = solve(n - 1, 0, dp) + solve(n - 1, 1, dp);
	} else {
		dp[n][val] = solve(n - 1, 1, dp);
	}
	return dp[n][val];
}

void Main() {
	int n;
	cin >> n;
	vector<vector<int>>dp(n + 1, vector<int>(2, -1));
	dp[n][0] = solve(n - 1, 0, dp);
	dp[n][1] = solve(n - 1, 1, dp);
	cout << dp[n][0] + dp[n][1] << endl;
}

*/

// dp approach
void Main() {
	int n;
	cin >> n;
	vector<vector<int>>dp(n + 1, vector<int>(2, 0));
	dp[1][0] = dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1];
		dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
	}
	cout << dp[n][0] + dp[n][1] << endl;
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