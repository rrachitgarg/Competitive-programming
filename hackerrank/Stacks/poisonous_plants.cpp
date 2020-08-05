/*
Author : RachitG
Question: Poisonous plants
Question link: https://www.hackerrank.com/challenges/poisonous-plants/problem
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

int poisonousPlants(vector<int> p)
{
    int mx_days = 0, n = p.size();
    stack<pair<int, int>> st;
    // We need to keep track of the no of days each plant is taking to expire to calculate for the next days.

    fo(i, 0, n)
    {
        int days = 1;
        while (!st.empty() && p[st.top().first] >= p[i])
        {
            days = max(days, st.top().second + 1);
            st.pop();
        }
        if (st.empty())
            days = 0;
        mx_days = max(mx_days, days);
        st.push(make_pair(i, days));
    }

    return mx_days;
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
    debug(poisonousPlants(arr));
    return 0;
}
