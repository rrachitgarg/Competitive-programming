/*
Author : RachitG
Question: Truck Tour
Question link: https://www.hackerrank.com/challenges/truck-tour/problem
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

int truckTour(vector<vector<int>> petrolpumps)
{
    int n = petrolpumps.size();
    int start = 0, end = 1;
    int petrol = petrolpumps[start][0] - petrolpumps[start][1];

    while (petrol < 0 || start != end)
    {
        while (petrol < 0 && start != end)
        {
            petrol -= petrolpumps[start][0] - petrolpumps[start][1];
            start = (start + 1);
            if (start == n)
                return -1;
        }
        petrol += petrolpumps[end][0] - petrolpumps[end][1];
        end = (end + 1) % n;
    }
    return start;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> input(n);
    fo(i, 0, n)
    {
        int x, y;
        cin >> x >> y;
        input[i].pb(x);
        input[i].pb(y);
    }
    debug(truckTour(input));
    return 0;
}
