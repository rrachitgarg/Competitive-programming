/*
Author : RachitG
Question: Maximal square
Question link: https://leetcode.com/problems/maximal-square/
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

int solve(vector<vector<int>> &matrix)
{
    // Write your code here

    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 1;
            else if (matrix[i][j] == matrix[i - 1][j] && matrix[i][j] == matrix[i - 1][j - 1] && matrix[i][j - 1] == matrix[i][j])
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
            else
                dp[i][j] = 1;
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));

    fo(i, 0, n)
    {
        fo(j, 0, m)
        {
            cin >> arr[i][j];
        }
    }
    debug(solve(arr));
    return 0;
}
