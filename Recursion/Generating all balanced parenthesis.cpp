#include<iostream>
#include<vector>
using namespace std;
void solve(int o,int c,string op,vector<string>&v){
     /* when open and close parenthesis are over we get the
        a balanced parenthsis then we push it to vector 
    */ 
   //base condition 
    if(o==0 && c==0){ 
        v.push_back(op);
        return ;
        /* if not return then segmentation 
        fault will come as its a recusion and will not stop 
        */
    }
    /* every time we have a choice that we can opening parenthesis 
        and we can take till our opening parenthesis count becomes zero
    */
    if(o!=0){
        //update the ouput to new string so that it can make decision 
        string op1=op;
        //push the opening parenthesis 
        op1.push_back('(');
        //call again the recursive function 
        solve(o-1,c,op1,v);
    }
    /* we can only choose closing parenthesis only when the number of closing 
        parenthesis is more than opening parenthis and if not greater than its not 
        valid parenthesis 
    */
    if(c>o){
        string op2=op;
        //push the closing parenthesis into the string 
        op2.push_back(')');
        // call again the recursive function 
        solve(o,c-1,op2,v);
    }
    return ;
}
vector<string>a(int n){
    vector<string>v;
    int c=n; //number of closing parenthesis 
    int o=n; // number of opening parenthesis 
    string op=""; // create a blank string to store 
    solve(o,c,op,v); // call the recursive function 
    return v; // return the vector 
}

int main(){
    int n;
    cout<<"Enter the of balanced parenthesis want : ";
    cin>>n;
    vector<string>s=a(n);
    for (int i = 0; i < s.size(); i++)
    {
        cout<<s[i]<<endl;
    }
    
    return 0;
}