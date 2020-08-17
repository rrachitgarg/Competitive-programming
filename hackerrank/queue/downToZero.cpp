/*
Author : RachitG
Question: Down to 0
Question link: https://www.hackerrank.com/challenges/down-to-zero-ii/problem
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

const int mx = 1000005;
int dp[mx];

void preCompute()
{
    fill(dp, dp + mx, -1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    fo(i, 2, mx)
    {
        if (dp[i] == -1 || dp[i - 1] + 1 < dp[i])
            dp[i] = dp[i - 1] + 1;

        for (int j = 2; j <= i && j * i < mx; j++)
        {
            // cout << i * j << " " << dp[i * j] << endl;
            if (dp[i * j] == -1 || dp[i] + 1 < dp[i * j])
                dp[i * j] = dp[i] + 1;
        }
        cout << i << " " << dp[i] << endl;
    }
}

int downToZero(int n)
{
    return dp[n];
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    preCompute();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        debug(downToZero(n));
    }
    return 0;
}
