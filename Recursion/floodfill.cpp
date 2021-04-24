
#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    void display(vector<vector<int>>&ans ) {
      for(auto i:ans) {
        for(auto j:i) {
          cout<<j<<" ";
        }
        cout<<endl;
      }
    }

    bool isvalid(vector<vector<int>>&ans,int n,int m,int p1,int p2,int newc,int pcolor ) {
      if(p1 <0 or p1>=n  or p2<0 or p2>=m or ans[p1][p2]!=pcolor or ans[p1][p2] == newc) return false;
      return true;
    }

    void solve(vector<vector<int>>&ans,int x,int y,int newc,int pcolor ){
      queue<pair<int,int>>q;
      q.push({x,y});
      ans[x][y] = newc;
      int n = ans.size();
      int m = ans[0].size();

      while(q.size()>0) {
        pair<int,int>currpixel = q.front();
        q.pop();
        int newx = currpixel.first;
        int newy = currpixel.second;

        if(isvalid(ans,n,m,newx+1,newy,newc,pcolor)) {
          ans[newx + 1][newy] = newc;
          q.push({newx+1,newy});
        }
        if(isvalid(ans,n,m,newx,newy+1,newc,pcolor)) {
          ans[newx][newy+1] = newc;
          q.push({newx,newy+1});
        }
        if(isvalid(ans,n,m,newx-1,newy,newc,pcolor)) {
          ans[newx -1][newy] = newc;
          q.push({newx-1,newy});
        }
        if(isvalid(ans,n,m,newx,newy-1,newc,pcolor)) {
          ans[newx][newy-1] = newc;
          q.push({newx,newy-1});
        }
      }

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>>ans = image;
        solve(ans,sr,sc,newColor,image[sr][sc]);
        return ans;
    }
};


int main(){
  #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
  int tc;
  cin >> tc;
  while(tc--){
    int n, m;
    cin >> n >> m;
    vector<vector<int>>image(n, vector<int>(m,0));
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++)
        cin >> image[i][j];
    }
    int sr, sc, newColor;
    cin >> sr >> sc >> newColor;
    Solution obj;
    vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
    for(auto i: ans){
      for(auto j: i)
        cout << j << " ";
      cout << "\n";
    }
  }
  return 0;
}
