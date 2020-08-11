/*
Author : RachitG
Question: Ugly number
Question link: https://leetcode.com/problems/ugly-number/
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

int divNumber(int a, int b)
{
    while (a % b == 0)
        a = a / b;
    return a;
}

bool isUgly(int num)
{

    num = divNumber(num, 2);
    num = divNumber(num, 3);
    num = divNumber(num, 5);
    return (num == 1 ? true : false);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    debug(isUgly(n));
    return 0;
}