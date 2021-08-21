//SATYAM SINGH  
// problem link --> https://www.codingninjas.com/codestudio/problems/minimum-sum-of-two-numbers-formed-from-digits-of-an-array_1171162?leftPanelTab=2
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll                 long long int
#define pb                 push_back
#define mod                     1000000007
#define inf                     1e18
#define ump                unordered_map
#define mp                 make_pair
#define all(v)                   v.begin(),v.end()

#define  inpv(v,n)  for(int i=0;i<n;i++) cin>>v[i]
#define  outv(v)    for(auto i:v) cout<<i<<' ' 
#define  loop(i,a,b)  for(int i=(a);i<(b);i++)
#define  looprev(i,a,b)  for(int i=(a);i>=0;i--)
#define log(args...)  {string _s = #args ;replace(_s.begin(),_s.end(),',',' ') ; stringstream _ss(_s); istream_iterator<string> _it(_ss) ; err(_it,args);}
void err(istream_iterator<string> it) {}
template<typename T,typename ... Args>
void err(istream_iterator<string> it, T a,Args... args) {
      cout<<*it<<" = "<<a<<endl;
   err(++it,args...);
}


void file_i_o()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

// =============== CODE STARTS HERE DO NOT BOTHER ABOUT THE TEMPLATE IT"S FOR SIMPLICITY ==============================================================================================================================================


void Main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		vector<int>arr(n);
		inpv(arr,n);

		// sort the array in ascending order 
		sort(arr.begin(),arr.end());
		// two string for storing min values 
		string a="",b="";

		for(int i=0;i<n;i++) {
			if(i%2) a.push_back(arr[i]+'0');
			else b.push_back(arr[i]+'0');
		}


		int i=a.size()-1,j=b.size()-1,carry = 0;
		// string to ans the ans of addition of two numbers 
		string ans;
		// traverse till both of them becomes less than zero 
		while(i>=0 or j>=0) {
			// take the value is anyone index  is less than zero than take zero itself 
			int val = (i>=0?a[i]-'0':0) + (j>=0?b[j]-'0':0) + carry;
			// push the remainder after taking with 10 
			ans.push_back((val)%10 + '0');
			// update the carry value 
			carry = val/10;
			i--,j--;
		}

		// if carry is greater than zero means we still have some ans left then push to ans string 
		if(car) ans.push_back(car+'0');

		i=ans.size()-1;

		// remove zeros from back if ans size is greater than one because there may be empty number so ans 0 should be there 
		// that's why remove zero only when we have size greater than one 
		while(ans[i] == '0' and ans.size() > 1){
			ans.pop_back();
			i--;
		}
		// finally reverse the ans 
		reverse(ans.begin(),ans.end());
		cout<<ans<<endl;
	}
	
}

// we only require sorting to be done in ascending order which need O( N logN) time and O( n ) for calculating the ans . So overall complexcity becomes O ( N LOG N ).
// The approach is similar to above one but with small code with helps to understande very easy 

// ============================================================================================================================
int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    
     Main();

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*100<<" seconds";
    #endif 
    return 0;
}