//SATYAM SINGH  
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
int ans=0;

// function to display the board 
void display(vc<vc<bool> > &grid,int n) {
    for(int i=0;i<n ; i++ ){
        for(int j=0 ;j <n ;j++) {
            if(grid[i][j]) cout<<"K";
            else cout<<"*";
        }
        cout<<endl;
    }
    cout<<"---------------------------------"<<endl;
}

// function to check whehter is it safe or not 
bool IsitSafe(int i,int j,vc<vc<bool> > &grid,int n) {
    if(i-2>=0 and j-1>=0 and grid[i-2][j-1]) return false;
    if(i-1>=0 and j-2>=0 and grid[i-1][j-2]) return false;
    if(i-2>=0 and j+1<n and grid[i-2][j+1]) return false;
    if(i-1>=0 and j+2>=0 and grid[i-1][j+2]) return false;
    return true;
}
void KnightP(int row,int col,int n,vc<vc<bool> > &grid,int k) {
    if(k == 0) {
        cout<<"s"<<endl;
        ans++;
        // display(grid,n);
        return ;
    }

    for(int i=row;i<n; i++) {
        for(int j = (i==row)?col:0;j<n;j++) {
            if(IsitSafe(i,j,grid,n)) {
                grid[i][j] = true;
                KnightP(i,j+1,n,grid,k-1);
                grid[i][j] = false;
            }
        }
    }
}
int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n;
    cin>>n;
    // int k=13;
    // cin>>k;
    vc<vc<bool> >grid(n,vc<bool>(n,false));
    KnightP(0,0,n,grid,13);
     cout<<ans<<endl;

// code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
    #endif 
    return 0;
}
// 1 6 36 143 