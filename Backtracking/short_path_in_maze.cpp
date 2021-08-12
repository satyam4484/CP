//SATYAM SINGH  
// problem link -- > Find the shortest path in a maze
// https://www.techiedelight.com/find-shortest-path-in-maze/


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

// =============================================================================================================================================================

// Tc - > 3(^n-2*n^2 )

// int row[] = {1,-1,0,0};
// int col[] = {0,0,1,-1};

// bool issafe(int r,int c,vector<vector<int>>&grid,int n) {
//     return (r>=0 and c>=0 and r<n and c<n and grid[r][c] == 1 and grid[r][c]!=-1);
// }

// void solve(int r,int c,int src,int des,vector<vector<int>>&grid,int &maxans,int sum,int n) {

//     if(r==src and c ==des) {
//         maxans = min(maxans,sum);
//         return ;
//     }
//     int x = grid[r][c];
//     grid[r][c] = -1;
//     for(int i=0;i<4;i++) {
//         if(issafe(r+row[i],c+col[i],grid,n)) {
//             solve(r+row[i],c+col[i],src,des,grid,maxans,sum+1,n);
//         }
//     }
//     grid[r][c] = x;

// }
// ==================================================================



bool issafe(int r,int c,vector<vector<int>>&grid,int n) {
    return (r>=0 and c>=0 and r<n and c<n and grid[r][c] == 1 and grid[r][c]!=-1);
}


void Main() {
    int n;
    cin>>n;
    vector<vector<int>>v(n,vector<int>(n));

    loop(i,0,n) {
        loop(j,0,n) {
            cin>>v[i][j];
        }
    }

    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    // int ans = INT_MAX;
    // solve(r1,c1,r2,c2,v,ans,0,n);
    // cout<<ans<<endl;



    // ===========================================
    // bfs approach 

    vector<vector<int>>ans(n,vector<int>(n,INT_MAX));
    ans[r1][c1] = 0;
    queue<pair<int,int>>q;
    q.push({r1,c1});
    int rw[] = {1,-1,0,0};
    int cl[] = {0,0,1,-1};
    while(not q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        if(row == r2 and col == c2) {
            break;
        }
        v[row][col] = -1;
        for(int i=0;i<4;i++) {
            if(issafe(row+rw[i],col+cl[i],v,n)) {
                ans[row+rw[i]][col+cl[i]] = min(ans[row+rw[i]][col+cl[i]],ans[row][col]+1);
                q.push({row+rw[i],col+cl[i]});
            }
        }
    }
    cout<<ans[r2][c2]<<endl;


    
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


/*

10
1 1 1 1 1 0 0 1 1 1 
0 1 1 1 1 1 0 1 0 1
0 0 1 0 1 1 1 0 0 1 
1 0 1 1 1 0 1 1 0 1 
0 0 0 1 0 0 0 1 0 1
1 0 1 1 1 0 0 1 1 0
0 0 0 0 1 0 0 1 0 1
0 1 1 1 1 1 1 1 0 0
1 1 1 1 1 0 0 1 1 1
0 0 1 0 0 1 1 0 0 1
0 0 
1 2

*/