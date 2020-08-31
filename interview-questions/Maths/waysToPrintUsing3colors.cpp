/*
Author : RachitG
Question:  Number of Ways to Paint N × 3 Grid
Question link: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vl vector<ll>
#define vi vector<int>
#define fo(i, x, n) for (int i = x; i < n; i++)
#define pb push_back
#define debug(n) cout << n << endl;
#define debug_arr(arr)                   \
    for (int i = 0; i < arr.size(); i++) \
        cout << arr[i] << " ";
#define debug_2darr(arr)                        \
    for (int i = 0; i < arr.size(); i++)        \
    {                                           \
        for (int j = 0; j < arr[i].size(); j++) \
            cout << arr[i][j] << " ";           \
        cout << endl;                           \
    }
#define newline cout << endl;
#define mod 1000000007

// Can be solved using pnc easily

int numOfWays(int n)
{
    ll twoWays = 6;
    ll threeWays = 6;

    fo(i, 1, n)
    {
        ll x = twoWays, y = threeWays;
        twoWays = ((x * 3) % mod + (y * 2) % mod) % mod;
        threeWays = ((x * 2) % mod + (y * 2) % mod) % mod;
    }
    return (twoWays + threeWays) % mod;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    debug(numOfWays(n));

    return 0;
}
