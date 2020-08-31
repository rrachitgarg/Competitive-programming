/*
Author : RachitG
Question: Rain water trapping I
Question link: https://leetcode.com/problems/trapping-rain-water/
*/

/*
Method 1: Brute force
    Space: O(1)
    Time: O(n^2)

Method 2: Dp approach (3 iterations over the array)
    Space: O(n)
    Time: O(n)

Method 3: Using stacks (single traversal)
    Space: O(n)
    Time:  O(n)

Method 4: Using two pointer
    Space: O(1)
    Time: O(n)
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

int trap_dp(vector<int> &height) // DP approach
{
    int n = height.size();
    // Calculate max height to the left & right of the element
    vi mx_left(n), mx_right(n);

    mx_left[0] = height[0];
    fo(i, 1, n)
    {
        mx_left[i] = max(height[i], mx_left[i - 1]);
    }

    mx_right[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        mx_right[i] = max(height[i], mx_right[i + 1]);
    }

    int water = 0;
    fo(i, 0, n)
    {
        water += max(min(mx_left[i], mx_right[i]) - height[i], 0); // To avoid negative values
    }
    return water;
}

int trap_stack(vector<int> &height)
{
    int n = height.size();
    stack<int> st;
    int water = 0;
    fo(i, 0, n)
    {
        while (!st.empty() && height[i] > height[st.top()])
        {
            int x = st.top();
            st.pop();
            if (st.empty())
                break;
            int dist = i - st.top() - 1;
            water += dist * (min(height[i], height[st.top()]) - height[x]);
        }
        st.push(i);
    }
    return water;
}

int trap_twoPointer(vector<int> &height)
{
    int water = 0;
    int n = height.size();
    int l = 0, h = n - 1;
    int left_max = INT_MIN, right_max = INT_MIN;
    while (l < h)
    {
        if (height[l] < height[h])
        {
            if (height[l] > left_max)
                left_max = height[l];
            else
                water += left_max - height[l];
            l++;
        }
        else
        {
            if (height[h] > right_max)
                right_max = height[h];
            else
                water += right_max - height[h];
            h--;
        }
    }
    return water;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vi arr(n);
    fo(i, 0, n)
    {
        cin >> arr[i];
    }
    debug(trap_dp(arr));
    debug(trap_stack(arr));
    debug(trap_twoPointer(arr));
    return 0;
}
