/*
Author : RachitG
Question: Max Product Subarray
Question link: https://www.geeksforgeeks.org/maximum-product-subarray/
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

int maxProduct(vi arr)
{
    int n = arr.size();
    int mx_product = INT_MIN;
    int mx_pos = 1, mx_neg = 1;

    fo(i, 0, n)
    {
        if (arr[i] > 0)
        {
            mx_pos *= arr[i];
            mx_neg = min(1, mx_neg * arr[i]);
        }
        else if (arr[i] == 0)
        {
            mx_pos = 0;
            mx_neg = 1;
        }
        else
        {
            int temp = mx_pos;
            mx_pos = mx_neg * arr[i];
            mx_neg = temp * arr[i];
        }

        mx_product = max(mx_product, mx_pos);
        if (mx_pos == 0)
            mx_pos = 1;
    }
    return mx_product;
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
    debug(maxProduct(input));
    return 0;
}
