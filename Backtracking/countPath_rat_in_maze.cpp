//SATYAM SINGH  
// problem link -- > https://www.codechef.com/problems/BPHC03

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

void file_i_o()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

// count the total path 
int countways=0;

//  function to check whether the step which we want to move is safe or not 
bool issafe(int i,int j,int n,vector<vector<bool> >&visited) {
	return i>=0 and j>=0 and i<n and j<n  and visited[i][j]==false;
}
// helper function to solve the rat in maze path counts 
void helper(int i,int j,int n,vector<vector<int>>& board,vector< vector<bool> >& visited) {
	// when we reach to destination count the path and return from that path 
	if(i ==n-1 and j==n-1 ) {
		countways++;
		return ;
	}
	// if the position is not safe then return from here itself 
	if(not issafe(i,j,n,visited))   {
		return ;
	}
	// mark the visited position true 
	visited[i][j]=true;

	// check whether i am able to move upward or not if yes then move 
	if(i-1>=0 and board[i-1][j]== 0) {
		helper(i-1,j,n,board,visited);
	}

	// check whether i am able to move left  or not if yes then move 
	if(j-1>=0 and board[i][j-1] == 0) {
		helper(i,j-1,n,board,visited);
	}
	// check whether i am able to move downward or not if yes then move 
	if(i+1 <n and board[i+1][j] == 0) {
		helper(i+1,j,n,board,visited);
	}
	// check whether i am able to move rightside or not if yes then move 
	if(j+1 <n  and board[i][j+1] == 0) {
		helper(i,j+1,n,board,visited);
	}
	// bactracting 
	// since i am coming back i need to unmark these place for the next path 
	visited[i][j]=false;
	return ;	
}

// fun
int solve_maze(int n,vector<vector<int>>& board) {
	// visited array to keep track on places i visited 
	vector<vector<bool>>visited(n,vector<bool>(n,false));
	helper(0,0,n,board,visited);
	return countways;
}

int main( ) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n;
	cin>>n;
	vector<vector<int>>board(n,vector<int>(n,0)); 
	loop(i,0,n) {
		loop(j,0,n) {
			cin>>board[i][j];
		}
	}
	cout<<solve_maze(n,board);
	
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC <<" ms";
	#endif 
	return 0;
}
