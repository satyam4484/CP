// problem link -- > https://practice.geeksforgeeks.org/problems/max-length-chain/1
//  version of LIS ( longes increasing subsequence )

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

// dp 
class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b) {
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),comp);
        // for(auto i:pairs) {
        //     cout<<i[0]<<" "<<i[1]<<endl;
        // }
        // vector<int>dp(pairs.size(),1);
        // int ans = 1;
        // for(int i=1;i<pairs.size();i++) {
        // 	int mx = 0;
        // 	for(int j=i-1;j>=0;j--) {
        // 		if(pairs[j][1] <pairs[i][0]) {
        // 			mx = max(mx,dp[j]);
        // 		}
        // 	}
        // 	dp[i]+=mx;
        // 	ans = max(ans,dp[i]);
        // }
        int ans = 0,curr = INT_MIN;
        for(auto i:pairs) {
            if(curr < i[0]) {
                ans++;
                curr = i[1];
            }
        }
        return ans;
    }
};  


void Main() {
	vector<vector<int>>v{{-6,9},{1,6},{8,10},{-1,4},{-6,-2},{-9,8},{-5,3},{0,3}};
	Solution s;
	cout<<s.findLongestChain(v);
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
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*100<<" seconds";
    #endif 
    return 0;
}