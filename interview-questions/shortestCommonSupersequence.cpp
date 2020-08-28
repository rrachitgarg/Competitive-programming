/*
Author : RachitG
Question: Printing shortest common supersequence
Question link: https://leetcode.com/problems/shortest-common-supersequence/
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

string shortestSuperSequence(string a, string b)
{
    int n = a.size(), m = b.size();
    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    string ans = "";

    while (n > 0 && m > 0)
    {
        if (a[n - 1] == b[m - 1])
        {
            ans = a[n - 1] + ans;
            n--;
            m--;
        }
        else if (dp[n - 1][m] > dp[n][m - 1])
        {
            ans = a[n - 1] + ans;
            n--;
        }
        else
        {
            ans = b[m - 1] + ans;
            m--;
        }
    }
    while (n > 0)
    {
        ans = a[n - 1] + ans;
        n--;
    }
    while (m > 0)
    {
        ans = b[m - 1] + ans;
        m--;
    }
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;
    cout << shortestSuperSequence(a, b) << endl;
    return 0;
}
