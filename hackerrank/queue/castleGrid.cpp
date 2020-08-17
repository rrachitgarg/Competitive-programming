/*
Author : RachitG
Question: Castle on the grid
Question link: https://www.hackerrank.com/challenges/castle-on-the-grid/problem
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pr;
#define ll long long
#define ull unsigned long long
#define vl vector<ll>
#define vi vector<int>
#define fo(i, x, n) for (int i = x; i < n; i++)
#define fod(i, x) for (int i = x; i >= 0; i--)
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

const int mx = 100005;

vector<int> G[mx];

void createGraph(vector<string> grid)
{
    int n = grid.size();
    fo(i, 0, n)
    {
        fo(j, 0, n)
        {
            if (grid[i][j] == '.')
            {
                int curr = n * i + j;
                fo(k, i + 1, n)
                {
                    if (grid[k][j] == '.')
                    {
                        int pos = n * k + j;
                        G[curr].pb(pos);
                    }
                    else
                    {
                        break;
                    }
                }
                fod(k, i - 1)
                {
                    if (grid[k][j] == '.')
                    {
                        int pos = n * k + j;
                        G[curr].pb(pos);
                    }
                    else
                    {
                        break;
                    }
                }
                fo(k, j + 1, n)
                {
                    if (grid[i][k] == '.')
                    {
                        int pos = n * i + k;
                        G[curr].pb(pos);
                    }
                    else
                    {
                        break;
                    }
                }
                fod(k, j - 1)
                {
                    if (grid[i][k] == '.')
                    {
                        int pos = n * i + k;
                        G[curr].pb(pos);
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
}

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY)
{
    int n = grid.size();
    createGraph(grid);

    int startp = n * startX + startY;
    int endp = n * goalX + goalY;
    queue<pr> que;
    bool vis[mx] = {false};
    que.push(make_pair(startp, 0));
    vis[startp] = true;
    while (!que.empty())
    {
        int node = que.front().first;
        int dist = que.front().second;
        que.pop();
        if (node == endp)
            return dist;
        for (auto i : G[node])
        {
            if (!vis[i])
            {
                que.push(make_pair(i, dist + 1));
                vis[i] = true;
            }
        }
    }
    return -1;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> input(n);
    fo(i, 0, n)
    {
        cin >> input[i];
    }
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    debug(minimumMoves(input, sx, sy, ex, ey));
    return 0;
}
