/*
Author : RachitG
Question: Queue using two stacks
Question link: https://www.hackerrank.com/challenges/queue-using-two-stacks/problem
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

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<int> s1, s2;
    int q, t, x;
    cin >> q;
    while (q--)
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cin >> t;
        if (t == 1)
        {
            cin >> x;
            s1.push(x);
        }
        else if (t == 2)
        {
            s2.pop();
        }
        else
        {
            cout << s2.top() << endl;
        }
    }
    return 0;
}
