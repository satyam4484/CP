//SATYAM SINGH  
// problem link -- >https://leetcode.com/problems/trapping-rain-water/
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

    // calclulate the maximum in the left subarray 
    void solveLL(vector<int>&height,vector<int>&ans ){
        int maxV=height[0];
        ans.push_back(0);
        for(int i=1;i<height.size() ; i++ ){
            if(maxV >=height[i] ){
                ans.push_back(maxV);
            }
            else {
                ans.push_back(0);
                maxV=height[i];
            }
        }
    }

    // calculate the maximum in the right subarray 
    void solveLR(vector<int>&height,vector<int>&ans ) {
       int maxV=height[height.size()-1];
        ans.push_back(0);
        for(int i=height.size()-2;i>=0  ; i-- ){
            if(maxV >=height[i] ){
                ans.push_back(maxV);
            }
            else {
                ans.push_back(0);
                maxV=height[i];
            }
        }
        reverse(ans.begin() , ans.end());
    }

    //  function to be called in the main funcion 
    int trap(vector<int>& height) {
        if(height.size() == 0)return 0;

        vector<int>LL,LR;
        // calculate the maximum int left array 
        solveLL(height,LL);
        // calculate the maximum in the right array 
        solveLR(height,LR);
        int sum=0;

        // finaaly find the differene between the min height and height of original water tanks 
        for(int i=0;i<height.size() ; i++) {
            int ans=min(LL[i],LR[i]) -height[i];
            sum+=(ans>=0 ?ans:0);
        }
        // return the ans 
        return sum;
    }
};

//  space optimised solution 
// basic of binary search 
int Rainwater(vector<int>&v) {
    int sum=0,LL=0,RR=0;
    int low=0,high=v.size()-1;

    // traverse from left to right 
    while(low<= high ){
        // if value at low is less than at high then check whether it is greater then left max or not 
        if(v[low] < v[high]) {
            // if yes then change the left max 
            if(v[low]>LL) LL = v[low];
            // otherwise calculate the value of these smallest since these may le higher left tank
            else sum+=LL-v[low];
            low++;
        }
        else {
            // if not then check right value is greater than right max or not 
            if(v[high] >RR) RR=v[high];
            // otherwise calcuate the value for that small element which is having less height than the right s
            else sum+=RR-v[high];
            high--;
        }
    }
    // return the ans 
    return sum;
}


int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    vector<int>v{4,2,0,3,2,5};
    // vector<int>v{0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    cout<<s.trap(v);
    // cout<<Rainwater(v);
     

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
    #endif 
    return 0;
}
