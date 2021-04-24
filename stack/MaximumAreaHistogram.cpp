//SATYAM SINGH  
// problem link --> https://leetcode.com/problems/largest-rectangle-in-histogram/
			    // --> https://www.codechef.com/problems/SPC1704
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

// **********************************************************************************************
/// Approach 1 : using the concept of next greater to left and right by using some extra space                                                                   
                                                                  
// function to find the next smaller element to right side of the array                                                                   
void  NextSmallerRight(vc<int> &v,vc<int> &ans ){                                                                  
	stack<pair<int,int>>st;                                                                  
	for(int i=v.size() ; i>=0;i--) {                                                                  
		if(st.size() == 0){                                                                  
			ans.push_back(v.size());                                                                  
		}                                                                  
		else if(st.size() > 0 and st.top().first <= v[i]) {                                                                  
			ans.push_back(st.top().second);                                                                  
		}                                                                  
		else if(st.size() > 0 and st.top().first >= v[i]) {                                                                  
			while(st.size()>0 and st.top().first >= v[i]) {                                                                  
				st.pop();                                                                  
			}                                                                  
			if(st.size() == 0){                                                                  
				ans.push_back(v.size());                                                                  
			}                                                                  
			else {                                                                  
				ans.push_back(st.top().second);                                                                  
			}                                                                  
		}                                                                  
		st.push(mp(v[i],i));                                                                  
	}                                                                  
	reverse(ans.begin(),ans.end());                                                                  
}                                                                  
                                                                  
                                                                  
// function to find the next smaller element to the left side of the array                                                                   
void NextSmallerLeft(vc<int> &v,vc<int> &ans ){                                                                  
	stack<pair<int,int>>st;                                                                  
	for(int i=0; i<v.size() ; i++ ){                                                                  
		if(st.size() == 0 ){                                                                  
			ans.push_back(-1);                                                                  
		}                                                                  
		else if(st.size() > 0 and st.top().first <= v[i]) {                                                                  
			ans.push_back(st.top().second);                                                                  
		}                                                                  
		else if(st.size() > 0 and st.top().first >= v[i]) {                                                                  
			while(st.size() > 0 and st.top().first >= v[i]) {                                                                  
				st.pop();                                                                  
			}                                                                  
			if(st.size() == 0){                                                                  
				ans.push_back(-1);                                                                  
			}                                                                  
			else {                                                                  
				ans.push_back(st.top().second);                                                                  
			}                                                                  
		}                                                                  
		st.push(mp(v[i],i));                                                                  
	}                                                                  
}          

// finally calculate by subtracting the index and muliplyt the value and calcualte the max area 
void solve(vc<int> &v) {                                                                  
	vc<int>NSR,NSL;                                                                  
	NextSmallerRight(v,NSR);                                                                  
	NextSmallerLeft(v,NSL);                                                                  
                                                                  
	int maxH=INT_MIN;                                                                  
	for(int i=0; i<v.size() ; i++) {                                                                  
		int ans = v[i]*(NSR[i]-NSL[i]-1);                                                                  
		if(maxH< ans) {                                                                  
			maxH=ans;                                                                  
		}                                                                  
	}                                                                  
	cout<<"Maximum area is : "<<maxH<<endl;                                                                  
}                                                                  

// ********************************************************************************************************      
// using single stack 
void solveHistogram(vc<int> &v) {
	stack<int>st;
	int maxAns=INT_MIN;
	int id;
	int i=0;
	while (i < v.size()) {
		if(st.empty() or v[st.top()] <= v[i] ){
			st.push(i++);
		}
		else {
			int id=st.top();
			st.pop();
			int area=v[id]*(st.empty() ?i:i-st.top()-1 );
			cout<<i<<" "<<area<<endl;
			if(maxAns<area) {
				maxAns=area;
			}
		}
	}
	while(st.empty() == false){
		int id=st.top();
		st.pop();
		int area=v[id]*(st.empty() ?i:i-st.top()-1);
		if(maxAns<area) {
			maxAns=area;

		}
	}
	cout<<maxAns<<endl;
}                       

int main( ) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	 vc<int>v {6,2,5,4,5,1,6};
	//  solve(v);
	solveHistogram(v);

// code ends here !!!!!! 
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
	#endif 
	return 0;
}
