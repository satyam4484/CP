//SATYAM SINGH  
// problem link --> https://leetcode.com/problems/maximum-product-subarray/
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
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = nums[0];
        int max_s = nums[0];
        int min_s = nums[0];
        for(int i=1;i<nums.size();i++) {
            int tmp = max_s;
            max_s = max({nums[i],max_s*nums[i],min_s*nums[i]});
            min_s = min({nums[i],tmp*nums[i],min_s*nums[i]});
            mx = max(mx,max_s);
        }
        return mx;
    }
};

void Main() {
    
    
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