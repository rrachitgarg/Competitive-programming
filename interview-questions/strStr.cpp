/*
Author : RachitG
Question:
Question link:
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

// We have to find the index of substring inside a string.
// We will be using KMP for these type of problem.
// KMP requires computation of lps array( longest proper prefix which is also a suffix).
// Time complexity: O(m+n)
// Space: O(m)

vi computeLps(string s, int n)
{
    vi lps_arr(n);
    lps_arr[0] = 0;
    int len = 0, i = 1;
    while (i < n)
    {
        if (s[len] == s[i])
        {
            len++;
            lps_arr[i++] = len;
        }
        else
        {
            if (len == 0)
            {
                lps_arr[i++] = 0;
            }
            else
            {
                len = lps_arr[len - 1];
            }
        }
    }
    return lps_arr;
}

int strStr(string haystack, string needle)
{
    int n = haystack.length(), m = needle.length();
    if (m == 0)
        return 0;
    if (n == 0)
        return -1;
    vi lps_arr = computeLps(needle, m);
    int i = 0, j = 0;
    while (i < n)
    {
        if (haystack[i] == needle[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
                j = lps_arr[j - 1];
            else
                i++;
        }
        if (j == m)
            return i - j;
    }
    return -1;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string haystack, needle;
    cin >> haystack >> needle;
    debug(strStr(haystack, needle));
    return 0;
}
