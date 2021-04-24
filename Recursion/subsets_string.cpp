#include<iostream>
using namespace std;

//ip denotes input and op denotes ouput 

void solve(string ip,string op){
    if(ip.length()==0){
        //leaf node condition 
        cout<<"{"<<op<<"},"<<" ";
        return ;
    }
    string op1=op;  //Divide the parts into two 
    string op2=op;  
    // decision to take first term 
    op2.push_back(ip[0]);
    // remove the first term 
    ip.erase(ip.begin()+0);
    // again call for 2 different ip // op 
    solve(ip,op1);
    solve(ip,op2);
    return;
}

int main(){
    string s="abc";
    solve(s,"");
    return 0;
    //ouput will be 
    // {},{c},{b},{bc},{a},{ac},{ab},{abc}
}