/*
1:Reverse the given string .
2:Print operands as they arrive .
3:If stack is empty or contains  a left parenthesis on top ,push the incoming operator onto the stack .
4:If the incoming symbol is ")" push it into the stack.
5:If the incoming symbol is "(" ,Pop the stack  & print the operators until right   parenthesis is found .
6:If the incoming operator has higher precedence than the top of the stack ,push it on the stack.
7:If the incoming symbol has lower precedence than the top of the stack , pop & print the top.Then test the incoming operator against the new top of the stack .
8:If the incoming operator has equal precedence with the top of the stack ,use associativity rule .
9:At the end of expression ,pop & print all operators of the stack .
10:Reverse the string again 
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int precision(char c){     // check the precison 
     if (c=='^')
     {
          return 3;
     }
     else if (c=='*' || c=='/')
     {
          return 2;
     }
     else if (c=='+' || c=='-')
     {
          return 1;
     }
     else
     {
          return -1;
     } 
}
// function to infix to postfix 
void infix_to_postfix(string s){
     stack<char>st;
     st.push('N');
     reverse(s.begin(),s.end());   // reversing the string 
     int l=s.length();
     string pos;
     for (int i = 0; i < l ; i++)
     {
          if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
          {
               pos+=s[i];  // if no operand then print 
          }
          else if (s[i]==')')
          {
               st.push(')');    // push into the stack 
          }
          else if (s[i]=='(')
          {
               while (st.top()!='N' && st.top()!=')')   //pop till ( comes 
               {
                    char c=st.top();
                    st.pop();
                    pos+=c;
               }
               if (st.top()==')')
               {
                    st.pop();
               }   
          }
          else
          {   //condition preference 
               while (st.top()!='N' && precision(s[i])<=precision(st.top()))
               {
                    char c=st.top();
                    st.pop();
                    pos+=c;
               }
               st.push(s[i]);   // more precison push directly 
          }  
     }
     while (st.top()!='N')    // last step to print all
     {
          char c=st.top();
          st.pop();
          pos+=c;
     }
     reverse(pos.begin(),pos.end()) ;  //again reversing the string 
     cout<<pos<<endl;
}

int main(){
     string s="K+L-m*n+(o^p)*w/u/v*t+q^a^s";
     infix_to_postfix(s);
     return 0;
}