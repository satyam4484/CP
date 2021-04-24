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

// **************************************************************
// function to find the permuataion 
void Permutation(int n,int start,string integer ) {
    if(start == n-1 ){
        cout<<integer <<endl;
    }
    else {
        for(int i=start; i<n ; i++) {
            swap(integer[i],integer[start]);
            Permutation(n,start+1,integer);
            swap(integer[i],integer[start]);
        }
    }
}

// it will generate integer from 1 to n in string format 
void getinteger( ) {
    int n;
    cin>>n ;
    string integer="";
    int i=1;
    while(i<=n ) {
        integer.pb(i+'0');
        i++;
    }
    Permutation(n,0,integer);
}

// **************************************************************

// **************************************************************
// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         int i;
//         for(i=nums.size() -2;i>=0 ; i--) {
//             if(nums[i] < nums[i+1]) {
//                 break;
//             }
//         }
//         if(i<0) {
//             reverse(nums.begin(),nums.end());
//         }
//         else {
//             int l;
//             for(l=nums.size()-1; l>i;l--) {
//                 if(nums[l] > nums[i]) break;
//             }
//             swap(nums[i],nums[l]);
//             reverse(nums.begin()+i+1,nums.end());
//         }
//     }
// };


// void NextPermutation() {
//     // problem link -- > https://leetcode.com/problems/next-permutation/ 
//     // int n;
//     // cin>>n;
//     vector<int>v{1,2,3};
//     // loop(i,0,n) {
//     //     v.pb(i+1);
//   // }
//     Solution s;
//     outv(v);
//     cout<<endl;
//     s.nextPermutation(v);
//     cout<<"next permuatation is :: ";
//     outv(v);
// }
// ************************************************************************
vector<int>fact(11,0);

class Solution {
public:
    void factorial (){
    fact[0]=fact[1]=1;
    for(int i=2;i<=11 ;i++) {
        fact[i] = i*fact[i-1];
    }
    // outv(fact);
}
    string getPermutation(int n, int k) {
        factorial();
        vector<int>v;
        for(int i=0;i<n;i++) {
            v.push_back(i+1);
        }
        string ans = "";
        int id;
        while(n) {
            id=k/fact[n-1];
            if(k%fact[n-1] == 0) id--;
            k=k-fact[n-1]*id;
            char c = v[id];
            c=c+48;
            ans+=c;
            n--;
            v.erase(v.begin()+id);
        }
        return ans ;
    }
};


void PermutationSequence() {
    int n,k;
    cin>>n >> k;
    Solution s;
    cout<<s.getPermutation(n,k);
}
int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here...;
    // NextPermutation();
    // factorial();
    PermutationSequence();



    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
    #endif 
    return 0;
}

/*

 pemutation of  ( 1 2 3 4 )

    1 2 3 4     1 2 3 4       1 2 3 4       1 2 3 4 

    1 2 3 4     2 1 3 4       3 2 1 4       4 2 3 1
    1 2 4 3     2 1 4 3       3 2 4 1       4 2 1 3
    1 3 2 4     2 3 1 4       3 1 2 4       4 3 2 1
    1 3 4 2     2 3 4 1       3 1 4 2       4 3 1 2
    1 4 3 2     2 4 3 1       3 4 1 2       4 1 3 2
    1 4 2 3     2 4 1 3       3 4 2 1       4 1 2 3

 pemutation of  ( 1 2 3 4 5 )

    1 2 3 4 5      1 2 3 4 5        1 2 3 4 5        1 2 3 4 5        1 2 3 4 5 
      
    1 2 3 4 5      2 1 3 4 5        3 2 1 4 5        4 2 3 1 5        5 2 3 4 1   
    1 2 3 5 4      2 1 3 5 4        3 2 1 5 4        4 2 3 5 1        5 2 3 1 4
    1 2 4 3 5      2 1 4 3 5        3 2 4 1 5        4 2 1 3 5        5 2 4 3 1
    1 2 4 5 3      2 1 4 5 3        3 2 4 5 1        4 2 1 5 3        5 2 4 1 3
    1 2 5 4 3      2 1 5 4 3        3 2 5 4 1        4 2 5 1 3        5 2 1 4 3
    1 2 5 3 4      2 1 5 3 4        3 2 5 1 4        4 2 5 3 1        5 2 1 3 4
    1 3 2 4 5      2 3 1 4 5        3 1 2 4 5        4 3 2 1 5        5 3 2 4 1
    1 3 2 5 4      2 3 1 5 4        3 1 2 5 4        4 3 2 5 1        5 3 2 1 4
    1 3 4 2 5      2 3 4 1 5        3 1 4 2 5        4 3 1 2 5        5 3 4 2 1
    1 3 4 5 2      2 3 4 5 1        3 1 4 5 2        4 3 1 5 2        5 3 4 1 2
    1 3 5 4 2      2 3 5 4 1        3 1 5 4 2        4 3 5 1 2        5 3 1 4 2
    1 3 5 2 4      2 3 5 1 4        3 1 5 2 4        4 3 5 2 1        5 3 1 2 4
    1 4 3 2 5      2 4 3 1 5        3 4 1 2 5        4 1 3 2 5        5 4 3 2 1
    1 4 3 5 2      2 4 3 5 1        3 4 1 5 2        4 1 3 5 2        5 4 3 1 2
    1 4 2 3 5      2 4 1 3 5        3 4 2 1 5        4 1 2 3 5        5 4 2 3 1
    1 4 2 5 3      2 4 1 5 3        3 4 2 5 1        4 1 2 5 3        5 4 2 1 3
    1 4 5 2 3      2 4 5 1 3        3 4 5 2 1        4 1 5 2 3        5 4 1 2 3
    1 4 5 3 2      2 4 5 3 1        3 4 5 1 2        4 1 5 3 2        5 4 1 3 2
    1 5 3 4 2      2 5 3 4 1        3 5 1 4 2        4 5 3 1 2        5 1 3 4 2
    1 5 3 2 4      2 5 3 1 4        3 5 1 2 4        4 5 3 2 1        5 1 3 2 4
    1 5 4 3 2      2 5 4 3 1        3 5 4 1 2        4 5 1 3 2        5 1 4 3 2
    1 5 4 2 3      2 5 4 1 3        3 5 4 2 1        4 5 1 2 3        5 1 4 2 3
    1 5 2 4 3      2 5 1 4 3        3 5 2 4 1        4 5 2 1 3        5 1 2 4 3
    1 5 2 3 4      2 5 1 3 4        3 5 2 1 4        4 5 2 3 1        5 1 2 3 4


*/