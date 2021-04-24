//SATYAM SINGH  

// problem link --->  https://leetcode.com/problems/n-queens-ii/

// problem link ---> https://leetcode.com/problems/n-queens/
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


// time complexcity  O(n! + n^2 )
// display function to print the checkboard  
void display(vc<vc<bool> >&grid,int n) {
    for(int i=0 ;i<n ;i++) {
        for(int j=0 ;j<n ;j++) {
            if(grid[i][j]) cout<<"Q";
            else cout<<".";
        }
        cout<<endl;
    }
    cout<<"------------------------"<<endl<<endl;
}

// function to check whether the given postition is safe or not 
bool IsItSafe(vc<vc<bool> >&grid,int row,int col,int n ) {

    // move to upward row and check for that column 
    looprev(i,row-1,0) {
        if(grid[i][col]) return false;
    }

    // move to left diagonala and check whether the queen is present or not 
    for(int i=row-1,j=col-1; i>=0 and j>=0 ; i-- , j--) {
        if(grid[i][j]) return false;
    }

    // move to right  diagonal and check whether the queen can be placed or not 
    for(int i=row-1 , j=col+1 ; i>=0 and j< n ;i-- ,j++ ){
        if(grid[i][j]) return false;
    }
    return true;

}

// function to solve the queen problem 
void SolveQueen(vc<vc<bool> >&grid,int n,int row,int &count ) {
    // when we exceed the chess board so we have founc the one combination so return from here 
    if(row == n) {
        count++;
        display(grid,n);
        return ;
    }

    // traverse all the column and try to find the correct path 
    for(int i=0;i< n; i++) {
        // if the current position is safe then mark the queen and check for remaninig places 
        if(IsItSafe(grid,row,i,n)) {
            grid[row][i] =true;
            SolveQueen(grid,n,row+1,count) ;

            // these is the backtracking step unmark the given mark position before coming back to previous row 
            grid[row][i] =false;

        }
    }
}

// -----------------------------------------------------------------------------------------------------


// Effiecient appraoch using bitmasking 

// optimised nQueen using bitset 
// we will create a bitset of three values ,column,left diagonal ,right diagonal 

bitset<100>col,ld,rd;
// ans to count the no of ways 
int ans=0;

// function to the no of ways to placed the nqueen 
void countQueen(int n,int row) {
    // if we reach the end of rows then we should return from there 
    if(row == n) {
        ans++;
        return ;
    }

    // start from first place and try to place the queen at each cell 
    for(int i=0 ; i<n ; i++) {
        // here we are checking whether the given place is safe or not by using  O(1) time 
        if(not col[i] and not ld[row-i+n-1] and not rd[row+i] ) {
            // if yes then mark these places visited and place for next steps 
            col[i] = ld[row-i+n-1] = rd[row+i] = 1;
            countQueen(n,row+1);
            // while coming back from next row to previous remove the visited place of the queen for next values 
            col[i] = ld[row-i+n-1] = rd[row+i] = 0;
            
        }
    }
}


int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int n;
    cin>>n ;

    vc<vc<bool> >grid(n,vc<bool>(n,false));
    int count=0;
    
    SolveQueen(grid,n,0,count);
    cout<<count<<endl;



// code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
    #endif 
    return 0;
}
