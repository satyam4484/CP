#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// connect n ropes with minimum cost
int main()
{
    // vector of ropes 
    vector<int> v{4, 3, 2, 6};
    // min heap to get the min at the top so that we can take minimum ropes to get minimum cost 
    priority_queue<int, vector<int>, greater<int>> p;

    // insert elements into heap
    for (int i = 0; i < v.size(); i++)
    {
        p.push(v[i]);
    }
    // cost value to add
    int cost = 0;
    // traversing the heap 
    while (p.size() > 0)
    {
        // take two minimum elements from top
        int a=p.top();
        p.pop();
        int b=p.top();
        p.pop();
        // add those values 
        cost+=(a+b);
        // push again that value to heap 
        p.push(a+b);
        if(p.size()==1){break;}
    }
    cout<<cost;

    return 0;
}