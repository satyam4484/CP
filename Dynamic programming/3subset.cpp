// 3 subset partition 
/* problem statement  -->check whther the elements of array can be partioned into 
3 subset of equal sum
*/


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

// recursive approach 
bool solve(vector<int>&v,int n,int a,int b,int c,unordered_map<string,bool>&mp,vector<int>&va,vector<int>&vb,vector<int>&vc) {
    if(a == 0 and b==0 and c==0) {
        outv(va);
        cout<<endl;
        outv(vb);
        cout<<endl;
        outv(vc);
        cout<<endl;
        return true;
    }
    if(n<0) return false;

    string s=to_string(a)+"|"+to_string(b)+"|"+to_string(c)+"|"+to_string(n);
    // string s="";
    // cout<<a<<" "<<b<<" "<<c<<" "<<n<<endl;
    if(not mp[s]) {
        bool A=false;
        if(a-v[n]>=0) {
            va.push_back(v[n]);
            A = solve(v,n-1,a-v[n],b,c,mp,va,vb,vc);
            if(not A) va.pop_back();
        }
        bool B = false;
        if(not A and b-v[n]>=0) {
            vb.push_back(v[n]);
            B = solve(v,n-1,a,b-v[n],c,mp,va,vb,vc);
            if(not B) vb.pop_back();
        }
        bool C = false;
        if(not A and not B and c-v[n]>=0) {
            vc.push_back(v[n]);
            C = solve(v,n-1,a,b,c-v[n],mp,va,vb,vc);
            if(not C) vc.pop_back();
        }
        mp[s] = A or B or C;
    }
    
    return mp[s];
}

// optmised Dp approach 

void Main() {
    vector<int>v{ 7, 3, 2, 1,5, 4, 8};
    int sum = 0;
    for(auto i:v) {
        sum+=i;
    }
    if(sum %3 != 0) {
        cout<<"false"<<endl;
        return ;
    }
    // these for printing the values 
    
    vector<int>va,vb,vc;
    unordered_map<string,bool>mp;
    
    if(solve(v,v.size()-1,sum/3,sum/3,sum/3,mp,va,vb,vc)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    // for(auto i:mp) {
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    
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