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


// It will give us the gcd of two number 
int GCD(int a,int b) {
    if(b == 0 ) return a;
    return GCD(b,a%b);
}


// it will give the lcm of two numbers 
int LCM (int a,int b) {
    return (a*b)/GCD(a,b);
}

// it will give the gcd of the whole array 
int GcdArray(vector<int> &v) {
    int ans =v[0];
    for(int i=1 ; i<v.size() ; i++) {
        ans =GCD(ans,v[i]) ;
    }
    return ans ;
}


// it will find the Lcm of the whole array 
int LcmArray(vector<int> &v) {
    int ans=v[0] ;

    for(int i=1 ;i<v.size() ; i++) {
        ans=(ans*v[i]/GCD(ans,v[i]));
    }
    return ans ;
}

int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....


    // In any mathematical equal consiting two numbers
    // let a and b the two numbers 
    // gcd(a,b) * lcm(a,b) == a*b 

    // gcd and lcm 
    // int a,b;
    // cin>>a >> b;
    // cout<<"GCD of "<<a<<" and "<<b<<" is :: "<<GCD(a,b)<<endl;
    // cout<<"LCM of "<<a<<" and "<<b<<" is :: "<<LCM(a,b)<<endl;

    // gcd and lcm for then 2 terms 
    vector<int> v{2,7,3,9,4};
    cout<<"Gcd of the array is :: "<<GcdArray(v)<<endl;
    cout<<"Lcm of the array is :: "<<LcmArray(v)<<endl;


    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
    #endif 
    return 0;
}
