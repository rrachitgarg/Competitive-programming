/*
Author : RachitG
Question: Max chunks to make sorted
Question link: https://leetcode.com/problems/max-chunks-to-make-sorted/
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

// When the element is from 1-n

int maxChunksToSortedI(vector<int> arr)
{
    int n = arr.size();
    int mx = -1, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, arr[i]);

        if (mx == i + 1)
            cnt++;
    }
    return cnt;
}

// This solution also handles the case if duplicate exists.

int maxChunksToSortedII(vector<int> &arr)
{

    int n = arr.size();
    stack<pair<int, int>> st;

    for (auto i : arr)
    {
        int mn = i;
        int mx = i;

        while (!st.empty())
        {
            if (i < st.top().second)
            {
                mn = min(mn, st.top().first);
                mx = max(mx, st.top().second);
                st.pop();
            }
            else
                break;
        }

        st.push(make_pair(mn, mx));
    }
    return st.size();
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
    debug(maxChunksToSortedII(input_arr));
    return 0;
}
