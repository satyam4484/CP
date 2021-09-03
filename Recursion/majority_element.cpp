//SATYAM SINGH
// problem link -- >  https://leetcode.com/problems/majority-element/
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
template<typename T, typename ... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << endl;
    err(++it, args...);
}

void file_i_o()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// =============== CODE STARTS HERE DO NOT BOTHER ABOUT THE TEMPLATE IT"S FOR SIMPLICITY ==============================================================================================================================================

class Solution {
public:
    int countmaj(vector<int>&v, int ans, int lo, int hi) {
        int count = 0;
        int i = lo;
        while (i < hi) {
            if (v[i] == ans) count++;
            i++;
        }
        return count;
    }
    int solve(vector<int>&v, int lo, int hi) {
        if (lo == hi) {
            return v[lo];
        }
        int mid = (hi - lo) / 2 + lo;
        int left = solve(v, lo, mid);
        int right = solve(v, mid + 1, hi);
        if (left == right) return left;

        int countleft = countmaj(v, left, lo, hi);
        int rightcount = countmaj(v, right, lo, hi);

        if (countleft > rightcount) return left;
        return right;
    }
    int majorityElement(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }
};

void Main() {
    vector<int>v{3, 2, 3};
    Solution s;
    cout << s.majorityElement(v);

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
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 100 << " seconds";
#endif
    return 0;
}