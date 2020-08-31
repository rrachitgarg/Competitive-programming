/*
Author : RachitG
Question: Max distance
Question link: https://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/
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

// T - O(n)     S - O(n)
int findMaxDistance(vi arr)
{
    int n = arr.size();
    vi left(n);
    vi right(n);

    left[0] = arr[0];
    fo(i, 1, n)
    {
        left[i] = min(left[i - 1], arr[i]);
    }
    right[n - 1] = arr[n - 1];
    for (int j = n - 2; j >= 0; j--)
    {
        right[j] = max(right[j + 1], arr[j]);
    }
    int i = 0, j = 0, ans = -1;
    while (i < n && j < n)
    {
        if (left[i] < right[j])
        {
            ans = max(ans, j - i);
            j++;
        }
        else
        {
            i++;
        }
    }
    return ans;
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
    debug(findMaxDistance(input));
    return 0;
}
