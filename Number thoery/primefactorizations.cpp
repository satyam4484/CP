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

// Tc -- > O(n) space + O(log lon (n))
void using_sieve(int &n, vector<int>&v) {
	for (int i = 0; i <= n; i++) {
		v[i] = i;
	}
	v[1] = 1;
	for (int i = 2; i * i <= n; i++) {
		if (v[i] == i) {
			for (int j = i * i; j <= n; j += i) {
				if (v[j] == j) v[j] = i;
			}
		}
	}

}

// prime factors using O(sqrt(n))
void solve(int &n) {
	// even numbers
	while (n % 2 == 0) {
		cout << 2 << " ";
		n /= 2;
	}
	// odd numbers
	for (int i = 3; i * i <= n; i += 2) {
		while (n % i == 0) {
			cout << i << " ";
			n /= i;
		}
	}

	// prime number case
	if (n > 2) {
		cout << n << endl;
	}
}


// prime factor
void Main() {
	int n;
	cin >> n;
	// solve(n);
	int k  = n;
	vector<int>sieve(n + 1, -1);
	using_sieve(n, sieve);
	// outv(sieve);
	while (sieve[k] != 1) {
		cout << sieve[k] << " ";
		k /= sieve[k];
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