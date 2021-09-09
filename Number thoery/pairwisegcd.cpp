//SATYAM SINGH
// problem link --> https://www.geeksforgeeks.org/count-of-pairs-in-given-array-whose-gcd-is-not-prime/
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

// let n = 10^4
bitset<1000000>prime;
void primes() {
	for (int i = 0; i < prime.size(); i++) {
		prime[i] = 1;
	}
	prime[0] = prime[1] = 0;
	for (int i = 2; i * i < 1000000; i++) {
		if (prime[i]) {
			for (int j = i * i; j < 1000000; j += i) {
				prime[j] = 0;
			}
		}
	}
}
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
void Main() {
	primes();
	int n;
	cin >> n;
	vector<int>v(n);
	inpv(v, n);
	int count = 0;
	// brute force
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int val = gcd(v[i], v[j]);
			if (not prime[val]) {
				count++;

			}
		}
	}

	cout << count << endl;

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
