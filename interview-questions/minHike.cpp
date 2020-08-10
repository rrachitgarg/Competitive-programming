/*
Author : RachitG
Question: Minimum salary hike for each employee such that no employee feels unfair
Question link: https://www.geeksforgeeks.org/minimum-salary-hike-for-each-employee-such-that-no-employee-feels-unfair/?ref=leftbar-rightbar
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

// This is solved using greedy.
// We have 4 type of queries here.
// T1: arr[i-1]>arr[i]<arr[i+1] -> ans[i] = 1
// T2: arr[i-1]<arr[i]<arr[i+1] -> ans[i] = ans[i-1]+1
// T3: arr[i-1]>arr[i]>arr[i+1] -> ans[i] = ans[i+1]+1
// T4: arr[i-1]<arr[i]>arr[i+1] -> ans[i] = max(ans[i-1],ans[i+1])+1

vi minHike(vi arr)
{
    int n = arr.size();
    arr.insert(arr.begin(), INT_MAX);
    arr.pb(INT_MAX);

    vi ans(n + 2, 0);

    fo(i, 1, n + 1)
    {
        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])
            ans[i] = 1;
    }
    fo(i, 1, n + 1)
    {
        if (arr[i] > arr[i - 1] && arr[i] < arr[i + 1])
            ans[i] = ans[i - 1] + 1;
    }
    fo(i, 1, n + 1)
    {
        if (arr[i] < arr[i - 1] && arr[i] > arr[i + 1])
            ans[i] = ans[i + 1] + 1;
    }
    fo(i, 1, n + 1)
    {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            ans[i] = max(ans[i - 1], ans[i + 1]) + 1;
    }
    ans.pop_back();
    ans.erase(ans.begin());
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vi input_arr(n);
    fo(i, 0, n)
    {
        cin >> input_arr[i];
    }
    vi ans = minHike(input_arr);
    debug_arr(ans);
    return 0;
}
