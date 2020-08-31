/*
Author : RachitG
Question: Min cost climbing stairs
Question link: https://leetcode.com/problems/min-cost-climbing-stairs/
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

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    if (n < 2)
        return 0;
    fo(i, 2, n)
    {
        cost[i] += min(cost[i - 1], cost[i - 2]);
    }
    return min(cost[n - 1], cost[n - 2]);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi input_arr(n);
    fo(i, 0, n)
    {
        cin >> input_arr[i];
    }
    debug(minCostClimbingStairs(input_arr));

    return 0;
}
