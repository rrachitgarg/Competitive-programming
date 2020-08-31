/*
Author : RachitG
Question: Stock span problem
Question link:  https://www.geeksforgeeks.org/the-stock-span-problem/
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

vi findStockSpan(vi arr, int n)
{
    stack<int> st;
    vi ans(n);
    ans[0] = 1;
    fo(i, 0, n)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            st.pop();
        }
        ans[i] = (st.empty()) ? i + 1 : (i - st.top());
        st.push(i);
    }
    return ans;
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

    vi ans = findStockSpan(arr, n);
    debug_arr(ans);

    return 0;
}
