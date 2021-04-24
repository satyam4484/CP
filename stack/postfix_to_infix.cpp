/* 
1:put operand directly to stack .
2:If operator comes then pop two elements from stack .
3:The top elements is ' a  ' and next element is ' b ' .
4:Then push the result in stack into the form ( b + operator + a ) .
5:Again repeat the same steps till the length .
6:Print the top element and it will be prefix expression  
*/

// postfix to infix conversion
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// fumtion for conversion
void post_to_inf(string s)
{
    stack<string> st; // take a string os stack
    int l = s.length();
    for (int i = 0; i < l; i++) // traverse the loop
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            string p(1, s[i]); // push string into the stack
            st.push(p);
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            string a = st.top();  // 1st top element 
            st.pop();
            string b = st.top(); // 2nd top element 
            st.pop();
            //  push back to the stack 
            st.push('(' + b + s[i] + a + ')');
        }
    }
    //print the top string on the stack 
    cout<<st.top()<<endl;
}

int main()
{
    string s = "ab+c+d+";
    post_to_inf(s);
    // after conversion the expression looks like 
    // (((a+b)+c)+d)
    return 0;
}