//SATYAM SINGH  

/* 
problem -- >  You have n person standing in a row at position [ 1 - n] inclusive. 
                you hav tow type of queries and you can perform that operations 
                type 1 :  - x  -- > The person at position 'x' left that position 
                tyep 2 :  ? X  -- > Find the nearst person to the right of 'x'  that is still standing(not left )
            # constraints 
            n<=10^6 and Q <=10^6;
            input -- >  1 2 3 4 5 
                        -3  --> 3 left 
                        ? 3 print(4)
                        -2  --> 2 left 
                        ?1  print(4) 
            if no person is standing to right of it then print (-1) as the ans 
            

*/             

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

int Get(vector<int>&parent,int a) {
    return parent[a] = (parent[a] == a?a:Get(parent,parent[a]));
}

void Union(vector<int>&parent,int a,int b) {
    a = Get(parent,a);
    b = Get(parent,b);
    parent[a] = b;
}

int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    inpv(v,n);
    vector<int>parent(n+1);

    loop(i,1,n+1) {
        parent[i] = i;
    }

    loop(i,0,q) {
        char c;
        int x;
        cin>>c>>x;
        if(c=='-') {
            Union(parent,x,x+1);
        } else {
            cout<<"The Person standing at position "<<x<<" is  :: "<<Get(parent,x)<<endl;
        }
    } 

     

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
    #endif 
    return 0;
}
