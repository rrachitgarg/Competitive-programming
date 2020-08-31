/*
Author : RachitG
Question: Min increment to make array unique
Question link: https://leetcode.com/problems/minimum-increment-to-make-array-unique/
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

int minIncrementForUnique(vector<int> &A)
{
    sort(A.begin(), A.end());
    int n = A.size(), cnt = 0;
    fo(i, 1, n)
    {
        if (A[i] <= A[i - 1])
        {
            int temp = A[i - 1] + 1;
            cnt += (temp - A[i]);
            A[i] = temp;
        }
    }

    return cnt;
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
    debug(minIncrementForUnique(input_arr));
    return 0;
}
