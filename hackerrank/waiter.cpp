/*
Author : RachitG
Question: Waiter problem
Question link: https://www.hackerrank.com/challenges/waiter/problem
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

vector<int> find_prime()
{
    int n = 10005;
    vi ans;
    bool prime[n];
    fill(prime, prime + n, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i * i < n; i++)
    {
        if (!prime[i])
            continue;
        for (int j = i * i; j < n; j += i)
            prime[j] = false;
    }
    fo(i, 2, n)
    {
        if (prime[i])
            ans.pb(i);
    }
    return ans;
}

vector<int> waiter(vector<int> number, int q)
{
    vi ans;
    int n = number.size(), k = 0;
    vi prime = find_prime();
    stack<int> c;
    for (auto i : number)
        c.push(i);

    while (q--)
    {
        stack<int> a, b;
        int p = prime[k];
        k++;
        while (!c.empty())
        {
            int i = c.top();
            c.pop();
            if (i % p == 0)
                b.push(i);
            else
                a.push(i);
        }
        while (!b.empty())
        {
            ans.pb(b.top());
            b.pop();
        }
        c = a;
    }
    while (!c.empty())
    {
        ans.pb(c.top());
        c.pop();
    }
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vi arr(n);
    fo(i, 0, n)
    {
        cin >> arr[i];
    }
    vi ans = waiter(arr, q);
    debug_arr(ans);
    return 0;
}
