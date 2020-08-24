/*
Author : RachitG
Question: Majority Element 2
Question link: https://leetcode.com/problems/majority-element-ii/
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

vi majorityElement(vi arr)
{
    int n = arr.size();
    int lim = n / 3;
    int f, s, cntf = 0, cnts = 0;

    for (auto i : arr)
    {
        if (cntf == 0)
        {
            cntf++;
            f = i;
        }
        else if (cnts == 0)
        {
            cnts++;
            s = i;
        }
        else
        {
            cntf--;
            cnts--;
        }
    }
    cntf = 0;
    cnts = 0;
    for (auto i : arr)
    {
        if (i == f)
        {
            cntf++;
        }
        else
        {
            cnts++;
        }
    }
    vi ans;
    if (cntf > lim)
    {
        ans.pb(f);
    }
    if (cnts > lim)
    {
        ans.pb(s);
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
    vi ans = majorityElement(input);
    debug_arr(ans);
    return 0;
}
