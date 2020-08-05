/*
Author : RachitG
Question: Simple text editor
Question link: https://www.hackerrank.com/challenges/simple-text-editor/problem
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
#define debug_arr(arr)               \
    for (int i = 0; arr.size(); i++) \
        cout << arr[i] << " ";
#define debug_2darr(arr)                        \
    for (int i = 0; arr.size(); i++)            \
    {                                           \
        for (int j = 0; j < arr[i].size(); j++) \
            cout << arr[i][j] << " ";           \
        cout << endl;                           \
    }
#define newline cout << endl;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    string s = "", si;
    int len = 0, q, x;
    stack<string> st;
    while (t--)
    {

        cin >> q;
        if (q == 1)
        {
            st.push(s);
            cin >> si;
            int l = si.length();
            s += si;
            len += l;
        }
        else if (q == 2)
        {
            st.push(s);
            cin >> x;
            s = s.substr(0, len - x);
            len = len - x;
        }
        else if (q == 3)
        {
            cin >> x;
            cout << s[x - 1] << endl;
        }
        else
        {
            s = st.top();
            st.pop();
            len = s.length();
        }
    }

    return 0;
}
