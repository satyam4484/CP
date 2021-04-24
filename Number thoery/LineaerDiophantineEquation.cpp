//SATYAM SINGH  
// problem link ---> https://www.spoj.com/problems/CEQU/
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
// extended Euclioid algorithm 
int ExtendedGcd(int a,int b,int &x,int &y ) {
    if(b==0) {
        x=1,y=0;
        return a;
    }
    int x1,y1;
    int d =ExtendedGcd(b,a%b,x1,y1);
    x=x1;
    y = x1-y1*(a/b);
    return d;
}
bool issolution(int a,int b,int c,int&x,int &y,int &g) {
    g= ExtendedGcd(abs(a),abs(b),x,y);
    if(c%g) return false;
    x*=c/g;
    y*=c/g;
    if(a<0) x= -x;
    if(b<0) x= -y;
    return true;
}

int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    
    int a,b,c,x,y,g;
    cin>>a>>b>>c;
    if(issolution(a,b,c,x,y,g)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
     

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
    #endif 
    return 0;
}
