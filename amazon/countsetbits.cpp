// problem link --> https://classroom.codingninjas.com/app/practice/2245717/9966/count-set-bits
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define mod 1000000007
#define inf 1e18
#define ump unordered_map

#define inpv(v, n)              \
    for (int i = 0; i < n; i++) \
    cin >> v[i]
#define outv(v)      \
    for (auto i : v) \
    cout << i << ' '
#define loop(i, a, b) for (int i = (a); i < (b); i++)
#define looprev(i, a, b) for (int i = (a); i >= 0; i--)

void file_i_o()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int largestPower(int n)
{
    int x = 0;
    while ((1 << x) <= n)
        x++;
    return x - 1;
}

int countSetBits(int n)
{
    if (n == 0)
        return 0;
    int x = largestPower(n);
    int left = (1 << (x - 1)) * x;
    int middle = (n - (1 << x) + 1);
    int left = n - (1 << x);
    return (left + middle + countSetBits(left)) % mod;
}
void Main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << countSetBits(n) << endl;
    }
}

int main()
{
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    Main();

// code ends here !!!!!!
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC << " seconds";
#endif
    return 0;
}