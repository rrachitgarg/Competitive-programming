/*
Author : RachitG
Question: Longest palindromic subsequence
Question link: https://leetcode.com/problems/longest-palindromic-subsequence/
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

int longestPalindrome(string s)
{
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 1));

    for (int k = 2; k <= n; k++)
    {
        for (int i = 0; i < n - k + 1; i++)
        {
            int j = i + k - 1;
            if (s[i] == s[j] && k == 2)
                dp[i][j] = 2;
            else if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][n - 1];
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    cout << longestPalindrome(s) << endl;

    return 0;
}
