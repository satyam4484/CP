#include<iostream>
using namespace std;
// givem a string of alphnumeric characters find all possible combination by converting each letter to uppercase 

void casepermutation(string input,string ouput) {
    if(input.size()==0) {
        cout<<ouput<<" ";
        return ;
    }
    string subs=input.substr(1);

    // if string is lowercase 
    if(input[0]>='a' && input[0]<='z') {
        casepermutation(subs,ouput+input[0]);
        casepermutation(subs,ouput+(char)(input[0]-32));
    } 

    // if string is uppercase 
    else if(input[0]>='A' && input[0]<='Z') {
        casepermutation(subs,ouput+input[0]);
        casepermutation(subs,ouput+(char)(input[0]+32));
    }
    // if it is digit then
    else{
        casepermutation(subs,ouput+input[0]);
    }
    
}   
int main(){
    string inp="1a2b";
    string out="";
    casepermutation(inp,out);
    return 0;
}