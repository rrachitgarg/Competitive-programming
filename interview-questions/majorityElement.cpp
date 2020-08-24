/*
Author : RachitG
Question: Majority Element
Question link: https://leetcode.com/problems/majority-element/
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

int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int element = nums[0], cnt = 1;

    fo(i, 1, n)
    {
        if (nums[i] == element)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
        if (cnt == 0)
        {
            cnt = 1;
            element = nums[i];
        }
    }
    return element;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi input(n);
    fo(i, 0, n)
    {
        cin >> input[i];
    }
    debug(majorityElement(input));
    return 0;
}
