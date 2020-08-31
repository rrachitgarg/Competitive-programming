/*
Author : RachitG
Question: Two Sum
Question link: https://leetcode.com/problems/two-sum/
*/

/*
Sol 1: Sorting + two pointer
    Space - O(1)
    Time - O(nlogn)

Sol 2: Hashmap
    Space - O(n)
    Time - O(n)
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

vector<int> twoSum(vector<int> &nums, int target)
{
    map<int, int> mp;
    int x, n = nums.size();
    vi ans;
    fo(i, 0, n)
    {
        x = target - nums[i];
        if (mp.count(x))
        {
            ans.pb(mp[x]);
            ans.pb(i);
            return ans;
        }
        mp[nums[i]] = i;
    }
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vi arr(n);
    fo(i, 0, n)
    {
        cin >> arr[i];
    }
    vi ans = twoSum(arr, k);
    debug_arr(ans);
    return 0;
}
