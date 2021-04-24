/*
There are n people standing in a circle waiting to be executed. The counting out begins at some point in the circle and proceeds around the circle in a fixed direction. In each step, a certain number of people are skipped and the next person is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom. Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle. The task is to choose the place in the initial circle so that you are the last one remaining and so survive.

For example, if n = 5 and k = 2, then the safe position is 3. Firstly, the person at position 2 is killed, then person at position 4 is killed, then person at position 1 is killed. Finally, the person at position 5 is killed. So the person at position 3 survives.
If n = 7 and k = 3, then the safe position is 4. The persons at positions 3, 6, 2, 7, 5, 1 are killed in order, and person at position 4 survives.
*/

#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>v,int k,int i,int &ans){
    if(v.size()==1){
        ans=v[0];
        return;
    }
    i=((i+k)%v.size());
    v.erase(v.begin()+i);
    solve(v,k,i+1,ans);
    return ;
}
int main(){
    cout<<"Enter the number people : ";
    int n,k;
    cin>>n;
    cout<<"Enter the steps after which we should remove : ";
    cin>>k;
    vector<int>v;
    for (int i = 0; i < n ; i++)
    {
        v.push_back(i+1);
    }
    k=k-1;
    int ans=-1;
    // int i=0;
    solve(v,k,0,ans);
    cout<<"The person who want to surviv: "<<ans<<endl;
    return 0;