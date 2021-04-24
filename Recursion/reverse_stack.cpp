// reverse a stack using recursion
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Insert the element at last according to condition
void insert(stack<int> &s, int temp)
{
    if (s.size() == 0)
    {
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insert(s, temp);
    s.push(val);
    return;
}

// reversing function to remove and insert elements 
void reverses(stack<int> &s)
{
    if (s.size() == 1)
    {
        return;
    }
    int temp = s.top();
    s.pop();
    reverses(s);
    insert(s, temp);
    // return;
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    //initially stack    50 40 30 20 10
    reverses(s);
    while (s.size() != 0)
    {
        cout << s.top() << " ";
        s.pop();
    }
    // After reversing the stack   10 20 30 40 50
    return 0;
}