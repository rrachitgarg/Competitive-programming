/*
Author : RachitG
Question: Queries with fixed length
Question link: https://www.hackerrank.com/challenges/queries-with-fixed-length/problem
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

vector<int> solve(vector<int> arr, vector<int> queries)
{

    int n = arr.size();
    vi ans;
    int q = 0;
    while (q < queries.size())
    {
        int w = queries[q];
        q++;
        deque<int> que;
        fo(i, 0, w)
        {
            while (!que.empty() && arr[que.back()] < arr[i])
            {
                que.pop_back();
            }
            que.push_back(i);
        }
        int mn = arr[que.front()];
        int r = w;
        while (r < n)
        {
            while (!que.empty() && que.front() < r - w + 1)
            {
                que.pop_front();
            }
            while (!que.empty() && arr[que.back()] < arr[r])
            {
                que.pop_back();
            }
            que.push_back(r++);
            mn = min(mn, arr[que.front()]);
        }
        ans.pb(mn);
    }
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vi input(n), queries(q);
    fo(i, 0, n)
    {
        cin >> input[i];
    }
    fo(i, 0, q)
    {
        cin >> queries[i];
    }
    vi ans = solve(input, queries);
    debug_arr(ans);
    return 0;
}
