//SATYAM SINGH  
// problem link -- > https://leetcode.com/problems/cyclically-rotating-a-grid/
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

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>>ans;
        int n = grid.size(),m=grid[0].size();


        for(int i=0;i<min(n,m)/2;i++) {
            vector<int>v;

            for(int j=i;j<m-i-1;j++) {
                v.push_back(grid[i][j]);
            }
            for(int k=i; k<n-i-1;k++) {
                v.push_back(grid[k][m-i-1]);
            }
            for(int j=m-i-1; j>i ; j--) {
                v.push_back(grid[n-i-1][j]);
            }
            for(int k=n-i-1; k>i; k--) {
                v.push_back(grid[k][i]);
            }
            
            int size = v.size();
            int l = k%v.size();
            
            for(int j=i;j<m-i-1;j++) {
                grid[i][j] = v[l++ % v.size()];
            }
            for(int k=i; k<n-i-1;k++) {
                grid[k][m-i-1] = v[l++ % v.size()];
            }
            for(int j=m-i-1; j>i ; j--) {
                grid[n-i-1][j] = v[l++ % v.size()];
            }
            for(int k=n-i-1; k>i; k--) {
                grid[k][i] = v[l++ % v.size()];
            }

        }
        return grid;
    }
};



int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    vector<vector<int>>v{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    Solution s;
    vector<vector<int>>ans = s.rotateGrid(v,2);

    for(auto i:ans) {
        for(auto j:i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
     

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*100<<" seconds";
    #endif 
    return 0;
}