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

void BuildSegment(vector<int>&segment,vector<int>&v,int low,int high,int ind) {
    if(low == high) {
        segment[ind] = v[low];
        return ;
    }

    // find the mid 
    int mid = (low+high)/2;
    // update left part 
    BuildSegment(segment,v,low,mid,2*ind+1);

    // update right part
    BuildSegment(segment,v,mid+1,high,2*ind+2);
    segment[ind] = segment[2*ind+1] + segment[2*ind+2];
}



int Query(vector<int>&segment,int low,int high,int ind,int i,int j) {
    if(low > j or high < i) return 0;
    if(low>=i and high <=j) return segment[ind];
    int mid = (low +high)/2;
    int left = Query(segment,low,mid,2*ind+1,i,j);
    int right = Query(segment,mid+1,high,2*ind+2,i,j);

    return left+right;
}

void Update(vector<int>&segment,vector<int>&v,int low,int high,int ind,int i,int val) {
    if(low == high) {
        v[i] = val;
        segment[ind] = val;
        return ;
    }

    int mid = (low+high)/2;
    if(i>mid) {
        Update(segment,v,mid+1,high,2*ind+2,i,val);
    } else {
        Update(segment,v,low,mid,2*ind+1,i,val);
    }

    segment[ind] = segment[2*ind+1] + segment[2*ind+2];
}


int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    vector<int>v{1,3,5,7,9,11};
    vector<int>segment(4*v.size());
    BuildSegment(segment,v,0,v.size()-1,0);
    // outv(segment);
    int q;
    cin>>q;
    while(q--) {
        int x;
        cin>>x;
        if(x == 1) {
            int i,j;
            cin>>i>>j;
            // log(i,j);
            cout<<Query(segment,0,v.size()-1,0,i,j)<<endl;
        } else {
            int i,y;
            cin>>i>>y;
            Update(segment,v,0,v.size()-1,0,i,y);
        }
    }
     

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*100<<" seconds";
    #endif 
    return 0;
}
