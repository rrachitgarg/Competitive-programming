/*
Author : RachitG
Question: House robber II
Question link: https://leetcode.com/problems/house-robber-ii/
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

// This is a variant of house robber I.
// Here instead of a linear array, we have a circular array.
// So the point to notice here is if we include 1st house, we can't loot last house & vice-versa.

int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];
    int prev = 0, curr = 0;
    fo(i, 0, n - 1)
    {
        int temp = max(prev + nums[i], curr);
        prev = curr;
        curr = temp;
    }
    int temp_ans = curr;
    prev = curr = 0;
    fo(i, 1, n)
    {
        int temp = max(prev + nums[i], curr);
        prev = curr;
        curr = temp;
    }
    return max(temp_ans, curr);
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
    debug(rob(input_arr));

    return 0;
}
