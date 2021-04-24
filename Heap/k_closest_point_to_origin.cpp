#include<iostream>
#include<bits/stdc++.h>

using namespace std;
// find k closest point to origin 
int main(){
    // we create a pair of vector to get corridnates 
    vector<pair<int,int>>v{{1,0},{2,1},{3,6},{-5,2},{1,-4}};
    int k=3;
    // here we created a maximum priority queue to get the minimum point closest to origin 
    priority_queue<pair<int,pair<int,int>>>p;
    for(int i=0;i<v.size();i++){
        // we can use distance formula 
        // sqrt((x-0)^2+(y-0)^2)----> sqrt(x^2+y^2)
        // we can push direct square term instead of squareroot 
        int x=v[i].first*v[i].first;  // calculation of x^2
        int y=v[i].second*v[i].second;  // calcuation oy y^2
        p.push({x+y,{v[i].first,v[i].second}}); // pushing the data into heap 
        if(p.size()>k){
            p.pop();
        }
    }
    // atlast we will get the k points which are closer to origin 
    while(p.size()>0){
        // creating a pair to strore element of heap 
        pair<int,pair<int,int>>ans=p.top();
        cout<<ans.second.first<<" "<<ans.second.second<<endl;
        p.pop();
    }
    return 0;
}