#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll                 long long int
#define pb                 push_back
#define mod             1000000007
#define inf             1e18
#define ump                unordered_map
#define mp                 make_pair

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

int getmax(vector<int>&v){
    int max = INT_MIN;
    int id = 0;
    for(int i=0;i<v.size();i++) {
        if(max < v[i]) {
            max = v[i],id = i;
        }
    }
    return id;
}

int getmin(vector<int>&v) {
    int mn = INT_MAX;
    int id = 0;
    for(int i=v.size()-1;i>=0;i--) {
        if(mn > v[i]) {
            mn = v[i];
            id = i;
        }
    }
    return id;
}

void Main() {
    int n;
    cin>>n;
    vector<int>v(n);
    inpv(v,n);
    int mx = getmax(v);
    int mn = getmin(v);
    int ans = mx+(n-mn-1);
    if(mx > mn) ans--;
    cout<<ans<<endl;


}

int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    Main();

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
    #endif 
    return 0;
}