// Problem 1:
//given a string find all permutations and put spaces in between 
/*  input : abc
    ouput : a_bc, ab_c, a_b_c, abc;
*/
#include<iostream>
using namespace std;
void solve(string ip,string op){
    if(ip.length()==0){
        cout<<op<<" , ";
        return;
    }
    string op1=op;
    string op2=op;
    op1.push_back('_');
    op1.push_back(ip[0]);
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    solve(ip,op1);
    solve(ip,op2);

}

int main(){
    string s;
    cin>>s;
    string op="";
    op.push_back(s[0]);
    s.erase(s.begin()+0);
    solve(s,op);
    return 0;
}

// Probelem 2:

/* given a string of lowecase letters find all
     permutation with case changes .
    eg : 
    input 1: s="ab"
    output : ab,aB,Ab,AB

    input 2: s="abc"
    output : abc,abC,aBc,aBC,Abc,AbC,ABc,ABC
*/
#include<iostream>
#include<string.h>
using namespace std;
void solve(string ip,string op){
    if(ip.length()==0){
        cout<<op<<" , ";
        return ;
    }
    string op1=op;
    string op2=op;
    // push directly lowecase 
    op1.push_back(ip[0]);
    //push by conveting to uppercase 
    op2.push_back(toupper(ip[0]));
    //remove the push elements 
    ip.erase(ip.begin()+0);
    solve(ip,op1);
    solve(ip,op2);
    return ;
}

int main(){
    string s;
    cout<<"Enter the string : ";
    cin>>s;
    string op="";
    solve(s,op);
    return 0;
}
    