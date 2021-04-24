//SATYAM SINGH 

// problem link --> https://www.codechef.com/LRNDSA02/problems/INPSTFIX
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
int Precision(char c) {
	if(c == '^') return 3;
	else if( c== '*' or c == '/') return 2;
	else if( c== '+' or c == '-') return 1;
	else return -1;
}

string Postfix(string s) {
	stack<char>st;
	st.push('$');
	string ans;
	for(int i=0; i<s.length() ; i++) {
		if( (s[i] >='a' and s[i]<= 'z' ) or (s[i] >= 'A' and s[i]<= 'Z') ) {
			ans.pb(s[i]);
		}
		else if(s[i] == '(') {
			st.push(s[i]);
		}
		else if( s[i] ==')') {
			while(st.top() != '$' and st.top()!= '(') {
				ans.pb(st.top());
				st.pop();
			}
			if(st.top() == '(') st.pop();
		}
		else {
			while(st.top()!= '$' and Precision(s[i]) <= Precision(st.top())) {
				ans.pb(st.top());
				st.pop();
			}
			st.push(s[i]);
		}
	}

	while(st.top()!='$') {
		ans.pb(st.top());
		st.pop();
	}
	return ans;
}

int main( ) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int t;
	cin>>t; 
	while(t--) {
		int n;
		cin>>n;
		string s;
		cin>>s;
		cout<<Postfix(s) <<endl;
	}

// code ends here !!!!!! 
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
	#endif 
	return 0;
}
