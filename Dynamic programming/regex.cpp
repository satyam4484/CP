//SATYAM SINGH   
// problem link  -- > https://leetcode.com/problems/regular-expression-matching/
// problem link  -- > https://leetcode.com/problems/wildcard-matching/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll 				long long int
#define pb 				push_back
#define mod             1000000007
#define inf             1e18
#define vi              vector<int>
#define vL              vector<ll>
#define vs             vector<string>
#define ump				unordered_map
#define mp 				make_pair
#define all(v)           v.begin(),v.end()

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

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool> >dp(p.size() + 1,vector<bool>(s.size() +1 ,false));

        loop(i,0,p.size() +1 ) {
            loop(j,0,s.size()+1) {
                if(i ==0 and j ==0) {
                    dp[i][j] = true;
                } else if(i == 0) {
                    dp[i][j] = false;
                } else if(j ==0) {
                    if(p[i-1] == '*') dp[i][j] = dp[i-2][j];
                    else dp[i][j] = false;
                } else {
                    char pt = p[i-1];
                    char st = s[j-1];
                    if(pt == '*') {
                        dp[i][j] = dp[i-2][j];
                        char ans  = p[i-2];
                        if(ans == '.' or ans == st) {
                            dp[i][j] = dp[i][j] or dp[i][j-1];
                        }
                    } else if(pt =='.') {
                        dp[i][j] = dp[i-1][j-1];
                    } else if(pt == st) {
                        dp[i][j] = dp[i-1][j-1];
                    } else {
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[p.size()][s.size()];
    }
};

int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    string s = "mississippi";
    string p = "mis*is*p*.";    // take this for wrong value 
    string p1= "mis*i.*p*i";     // true value 
    Solution obj;
    cout<<obj.isMatch(s,p1);

     

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
    #endif 
    return 0;
}
