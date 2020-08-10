/*
Author : RachitG
Question:
Question link:
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

// Sieve of eratosthenes is used for calculating primes.
// This is the general algorithm for finding primes.
// Time complexity: O(n*log(log(n)))

void sieve()
{
    int n = 1e5 + 5;

    vector<bool> prime(n, true);

    for (int i = 2; i * i < n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j < n; j += i)
                prime[j] = false;
        }
    }
    fo(i, 2, n)
    {
        if (prime[i])
        {
            cout << i << endl;
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    return 0;
}
