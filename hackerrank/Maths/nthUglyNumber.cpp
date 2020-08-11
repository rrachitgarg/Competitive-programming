/*
Author : RachitG
Question: Nth Ugly Number
Question link: https://leetcode.com/problems/ugly-number-ii/
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

int nthUglyNumber(int n)
{

    int ugly_number[2000], ans;
    ugly_number[0] = 1;
    int first = 2, second = 3, third = 5;
    int fi = 0, si = 0, ti = 0;
    fo(i, 1, n)
    {
        ans = min(first, min(second, third));

        ugly_number[i] = ans;

        if (ans == first)
            first = 2 * ugly_number[++fi];
        if (ans == second)
            second = 3 * ugly_number[++si];
        if (ans == third)
            third = 5 * ugly_number[++ti];
    }
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    debug(nthUglyNumber(n));
    return 0;
}
