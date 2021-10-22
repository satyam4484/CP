//SATYAM SINGH
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

void getsum(vector<int>&v, int &st, int &mx) {
	for (auto i : v) {
		st += i;
		mx = max(mx, i);
	}
}

bool isvalid(vector<int>&v, int &m, int &mx) {
	int stud = 1;
	int sum  = 0;
	for (auto i : v) {
		sum += i;
		if (sum > mx) {
			stud++, sum = i;
		}
	}
	return stud <= m ? true : false;
}
int allocateBooks(vector<int> arr, int n, int m) {
	int st = 0, end = 0;
	getsum(arr, end, st);
	if (n < m) return -1;
	if (n == m) return st;
	int ans = -1;
	while (st <= end) {
		int mid = (st + end) / 2;
		if (isvalid(arr, m, mid)) {
			ans = mid;
			end = mid - 1;
		} else {
			st = mid + 1;
		}
	}
	return ans;
}

void Main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int>v(n);
		inpv(v, n);
		cout << allocateBooks(v, n, m) << endl;
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
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 100 << " seconds";
#endif
	return 0;
}