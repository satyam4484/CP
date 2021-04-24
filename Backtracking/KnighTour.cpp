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


void display(vc<vc<int>>&grid) {
    for(auto row:grid) {
        for(auto col:row) {
            cout<<col<<" ";
        }
        cout<<endl;
    }
    cout<<"-----------------------"<<endl;
}
bool IsItSafe(int i,int j,int n,vc<vc<bool> > &visited) {
    return i>=0 and j>=0 and i<n and j<n  and visited[i][j]==false ;
}

void KnightTour(int row,int col,int n,vc<vc<int > >&grid,int counter,vc<vc<bool > >&visited ) {
    if(counter == n*n-1) 
    {
        grid[row][col] = counter;
        display(grid);
        return ;
    }
    if(counter>=n*n) {
        return ;
    }

    int xdir[8] = {-2,-2, -1,-1,2, 2,1, 1};
    int ydir[8] = {1, -1,  2,-2,1,-1,2,-2};

    visited[row][col]=true;
    grid[row][col] = counter ;
    for(int i=0;i<8;i++) {
        if(IsItSafe(row+xdir[i],col+ydir[i],n,visited)) {
            KnightTour(row+xdir[i],col+ydir[i],n,grid,counter+1,visited);
        }
    }
    grid[row][col] = -1;
    visited[row][col]=false;
    return;
}

int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int n;
    cin>>n;
    vc<vc<int> >grid(n,vc<int>(n,-1));
    vc<vc<bool> >visited(n,vc<bool > (n,false));

    KnightTour(0,0,n,grid,0,visited);
    // display(grid);



// code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
    #endif 
    return 0;
}
