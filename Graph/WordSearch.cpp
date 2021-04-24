//SATYAM SINGH 

// problem link --> https://leetcode.com/problems/word-search/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll 				long long int
#define pb 				push_back
#define mod             1000000007
#define inf             1e18
#define ump				unordered_map
#define mp 				make_pair

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

class Solution {
public:
    bool isvalid(int i,int j,int r ,int c) {
    return (i>=0 and j>=0 and i<r and j<c);
}

bool recursive(vector<vector<char>>&grid,string word ,int n,int m,int i,int r,int c) {
    if(i == word.size()-1) return true;
    char ans = grid[r][c] ;
    grid[r][c] = '$';
    int row[]= {-1,1,0,0};
    int col[]= {0,0,-1,1};
    for(int k= 0; k<4;k++) {
        if(isvalid(r+row[k],c+col[k] ,n,m) and grid[r+row[k]][c+col[k]] == word[i+1]) {
            if(recursive(grid,word,n,m,i+1,r+row[k],c+col[k])) {
                return true;
            }
        }
    }
    grid[r][c]  = ans;
    return false;
}
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m =board[0].size();
        loop(i,0,n) {
            loop(j,0,m) {
                if(board[i][j] == word[0] and recursive(board,word,n,m,0,i,j ) ){
                    return true;
            }
        }
    }
    return false;
    }
};

int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n,m;
    cin>>n>>m;
    vector<vector<char >>grid(n,vector<char>(m));
    loop(i,0,n) {
        loop(j,0,m) {
            cin>>grid[i][j];
        }
    }
    string word;
    cin>>word;
    Solution s;
    cout<<s.exist(grid,word );
    

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
    #endif 
    return 0;
}
