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

int solve(string s,string exp) {
    int n=s.size();
    vector<vector<int>>dpT(n,vector<int>(n,0));
    vector<vector<int>>dpF(n,vector<int>(n,0));

    for(int g=0;g<n;g++) {
        for(int i=0 ,j=g;j<n;j++,i++) {
            if(g == 0) {
                if(s[i] == 'T') {
                    dpF[i][j] = 0;
                    dpT[i][j] =1;
                } else if(s[i] == 'F') {
                    dpF[i][j] =1;
                    dpT[i][j] =0;
                }
            } else{
                for(int k=i;k<j;k++) {
                    int lT = dpT[i][k];
                    int lF = dpF[i][k];
                    int rT = dpT[k+1][j];
                    int rF = dpF[k+1][j];

                    char c = exp[k];
                    if(c == '&') {
                        dpT[i][j] += lT*rT;
                        dpF[i][j] += lT*rF + lF*rT + lF*rF;
                    } else if(c == '|') {
                        dpT[i][j] += lT*rT + lT*rF + lF*rT ;
                        dpF[i][j] += lF*rF;
                    } else if(c =='^') {
                        dpT[i][j] += lT*rF + lF*rT ;
                        dpF[i][j] += lT*rT + lF*rF;
                    }
                }
            }
        }
    }
    return dpT[0][n-1];
}
int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    string s,exp;
    cin>>s>>exp;
    cout<<solve(s,exp);
     

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*100<<" seconds";
    #endif 
    return 0;
}