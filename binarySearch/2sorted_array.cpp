// https://mycode.prepbytes.com/company-questions/top-50-samsung-interview-coding-questions-set-1/KELEMENT

// O(log(min(n,m)))
//SATYAM SINGH  
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
int solve(vector<int>&arr1,vector<int>&arr2,int n,int m,int k )  {
    if(n > m) {
        return solve(arr2,arr1,m,n,k);
    }

    int low = max(0,k-m),high = min(k,n);
    while(low<=high) {
        int cut1 = (low + high) >>1;
        int cut2 = k-cut1;
        int l1 = (cut1 ==0?INT_MIN:arr1[cut1-1]);
        int l2 = (cut2 ==0?INT_MIN:arr2[cut2-1]);
        int r1 = (cut1 ==n?INT_MAX:arr1[cut1]);
        int r2 = (cut2 ==m?INT_MAX:arr2[cut2]);
        if(l1 <= r2 and l2<=r1) {
            return max(l1,l2);
        } else if(l1 > r2) {
            high = cut1-1;
        } else {
            low = cut1+1;
        }
    }
    return 1;
}


void Main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m,k;
        cin>>n>>m>>k;
        vector<int>v1(n),v2(m);
        inpv(v1,n);
        inpv(v2,m);

        cout<<solve(v1,v2,n,m,k)<<endl;
    }
    
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