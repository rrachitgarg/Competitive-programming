/*
Author : RachitG
Question: And Xor Or
Question link: https://www.hackerrank.com/challenges/and-xor-or/problem
*/

// Thing to notice is the arithmetic operation.
// It can be simplified.
// A XOR B = (A AND B) XOR (A OR B)
// A AND A = A
// (((M1 AND M2) XOR (M1 OR M2)) AND (M1 XOR M2)) = (M1 XOR M2)

// Using stack to find the smallest and next smallest in all subarrays.

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

int andXorOr(vector<int> a)
{
    int mx = INT_MIN;
    int n = a.size();
    stack<int> st;

    for (auto i : a)
    {
        if (st.empty())
            st.push(i);
        else
        {
            while (!st.empty())
            {
                int x = st.top();
                mx = max(mx, x ^ i);
                if (i < x)
                    st.pop();
                else
                {
                    break;
                }
            }
            st.push(i);
        }
    }
    return mx;
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
    debug(andXorOr(arr));
    return 0;
}
