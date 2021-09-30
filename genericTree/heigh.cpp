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

struct Tree {
	int data;
	vector<Tree*>children;
};
Tree * root;

void CreateTree(vector<int>&v) {
	stack<Tree*>st;

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == -1) {
			st.pop();
		} else {
			Tree*newnode = new Tree;
			newnode->data = v[i];

			if (st.size() > 0) {
				st.top()->children.emplace_back(newnode);
			} else {
				root = newnode;
			}
			st.push(newnode);
		}
	}
}


void display(Tree*head) {
	cout << head->data << "->";
	for (auto i : head->children) {
		cout << i->data << " , ";
	}
	cout << endl;
	for (auto i : head->children) {
		display(i);
	}
}

int height(Tree*temp) {
	int mx = 0;
	for (auto i : temp->children) {
		mx = max(mx, 1 + height(i));
	}
	return mx;
}

void Main() {
	int n;
	cin >> n;
	vector<int>v(n);
	loop(i, 0, n) {
		cin >> v[i];
	}

	CreateTree(v);
	Tree * head = root;
	// display(head);
	cout << height(head);

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