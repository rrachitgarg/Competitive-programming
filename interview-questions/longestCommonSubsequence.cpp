/*
Author : RachitG
Question: Longest Common Subsequence
Question link:
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
#define mod 1e9 + 7

// BASIC RECURSION
int LCS(string x, string y, int n, int m, vector<vector<int>> t)
{
    if (n == 0 || m == 0) // BASE CONDITION
        return 0;

    if (t[n][m] != -1)
        return t[n][m];

    if (x[n - 1] == y[m - 1]) // CHOICE DIAGRAM
    {
        t[n][m] = 1 + LCS(x, y, n - 1, m - 1, t);
        return t[n][m];
    }
    else
    {
        t[n][m] = max(LCS(x, y, n - 1, m, t), LCS(x, y, n, m - 1, t));
        return t[n][m];
    }
}

int LCS_DP(string x, string y, int n, int m)
{
    int dp[n + 1][m + 1];

    fo(i, 0, n + 1)
    {
        fo(j, 0, m + 1)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string x, y;
    cin >> x >> y;
    int n = x.length(), m = y.length();
    vector<vector<int>> t(n + 1, vector<int>(m + 1, -1));
    debug(LCS(x, y, n, m, t));
    return 0;
}
