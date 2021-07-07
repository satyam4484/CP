//SATYAM SINGH  
// problem linkk -> https://www.interviewbit.com/problems/nearest-smaller-element/
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
vector<int>prevSmaller(vector<int> &A) {
    vector<int>ans;
    stack<int>st;
    int n=A.size();
    for(int i=0;i<n;i++) {
        if(st.empty()) {
            ans.pb(-1);
            st.push(A[i]);
        } else if(st.top() < A[i]) {
            ans.pb(st.top());
            st.push(A[i]);
        } else if(st.top() >= A[i]) {
            while(not st.empty() and st.top() >=A[i]) {
                st.pop();
            }
            if(st.empty()) ans.pb(-1);
            else ans.pb(st.top());
            st.push(A[i]);
        }
    }  
    return ans;
} 


int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    vector<int>v{39, 27, 11, 4, 24, 32, 32, 1 };
    outv(prevSmaller(v));
    
     

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*100<<" seconds";
    #endif 
    return 0;
}