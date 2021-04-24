
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

void file_i_o()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

//  starts here 

// array to store elements in particular row 
vector<vector<int>>row(9,vector<int>(10,0));
// array to store the elements in particular column 
vector<vector<int>>col(9,vector<int>(10,0));

// array to store the elements inside the 3*3  box 
vector<vector<int>>box(9,vector<int>(10,0));

//  the whole suduo board 
vector<vector<int>>board(9,vector<int>(9));


bool isSudukoSolved=false;

// function to check whether we can place the value at the position or not s
bool canplace(int d,int r,int c) {
	int i=(r/3)*3 + (c/3) ;
	return row[r][d] + col[c][d] + box[i][d] == 0 ;
}

// function to add the vaue at the position 
void addDigit(int d,int r,int c) {
	int i=(r/3)*3 + (c/3);
	cout<<r<<" "<<c<<" "<<i<<endl;
	row[r][d]++;
	col[c][d]++;
	box[i][d]++;

	board[r][c] = d;
}

//  function to remove the value from the position 
void removeDigit(int d,int r,int c) {
	int i=(r/3)*3 + (c/3);
	row[r][d]--;
	col[c][d]--;
	box[i][d]--;

	board[r][c] = 0;
}

// helper function for suduko solver 
void helper(int r,int c) {
    // if the current position contain no values 
	if(board[r][c] == 0) {
        // then check for each of the values whether they are present at that posision or not 
		for(int d=1; d<= 9 ;d++) {
            // if we can place that value at that posito we will and move to place the next numbers 
			if(canplace(d,r,c)) {
				addDigit(d,r,c);

                // at some point of time if we reach the last value then we have solved the suduko and make the value true 
				if(r==8 and c==8) {
					isSudukoSolved = true;
				}
                // else if we reach end of the column then move to next row ans starting point 
				else {
					if(c==8) helper(r+1,0);
                    // else move to next column for placing more numbers 
					else helper(r,c+1);
				}
                // if we were unable to place that value at that point then backtrack from there and remove that value 
				if(!isSudukoSolved) removeDigit(d,r,c);
			}
		}
	}
    // if the current board is not empty then move forward 
	else {
		if(r==8 and c==8) {
			isSudukoSolved = true;
		}
		else {
            // else if we reach end of the column then move to next row ans starting point 
			if(c==8) helper(r+1,0);
            // else move to next column for placing more numbers 
			else helper(r,c+1);
		}
	}
}
// function for suduko
void Suduko() {
	helper(0,0);
}

// functio t display the board 
void display() {
	for(auto i:board) {
		for(auto j:i) {
			cout<<j<<" ";
		}
		cout<<endl;
	}
	cout<<"----------------------------------"<<endl;
}

int main( ) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	
    // take input and storr it to different arrays 
	for(int i=0;i<9 ;i++) {
		for(int j=0;j<9;j++) {
			int x;
			cin>>x;
			addDigit(x,i,j);
		}
	}

	Suduko();
    //  if suduko is solved then print that 
	// if(isSudukoSolved) display();
    // // else no solution exit for that value 
	// else cout<<"No solution"<<endl;

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
