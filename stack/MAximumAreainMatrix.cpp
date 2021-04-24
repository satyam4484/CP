//SATYAM SINGH  
// problem link -- > https://leetcode.com/problems/maximal-rectangle/
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

class Solution {
public:
    int MAH(vector<int> &v) {
        stack<int>st;
        int max_ans=0;
        int i=0;
        // outv(v);
        // cout<<endl;
        while(i<v.size()) {

            if(st.empty() or v[st.top()] <= v[i]){
                st.push(i++);
            }
            else {
                int id=st.top();
                st.pop();
                int area=v[id]*(st.empty()?i:i-st.top()-1);
                if(max_ans<area) {
                    max_ans=area;
                }
            }
        }
        while(st.empty() == false) {
            int id=st.top();
            st.pop();
            int area=v[id]*(st.empty()?i:i-st.top()-1);
            if(max_ans<area) {
                max_ans=area;
            }
        }
        // cout<<"m : "<<max_ans<<endl;
        return max_ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 or matrix[0].size() == 0) return 0;
        int ans=0;
        vector<int>v(matrix[0].size(),0);
        for(int i=0;i<matrix.size(); i++ ){
            for(int j=0;j<matrix[0].size();j++) {
                if(matrix[i][j] == '1') {
                    v[j]+=1;
                }
                else v[j]=0;
            }
            int value =MAH(v);
            if(ans<value) {
                ans=value;
            }
        }
        return ans;
    }
};


int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    vc<vc<char>> v {{'1','0'}};
    Solution s;
    cout<<s.maximalRectangle(v);
     

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
    #endif 
    return 0;
}
