/*
Author : RachitG
Question: Swap nodes
Question link: https://www.hackerrank.com/challenges/swap-nodes-algo/problem
*/

#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vl vector<ll>
#define vi vector<int>
#define fo(x, n) for (int i = x; i < n; i++)
#define pb push_back
#define debug_arr(arr) for(int i=0;arr.size();i++) cout<<arr[i]<<" ";
#define debug_2darr(arr) for(int i=0;arr.size();i++) { for(int j=0;j<arr[i].size();j++) cout<<arr[i][j]<<" ";   cout<<endl;  }
#define newline cout<<endl;


class Node
{
public:
    int val;
    Node *left, *right;
    Node(int x)
    {
        val = x;
        left = right = NULL;
    }
};

void doswap(Node *node, int l, int k)
{
    if (!node)
        return;
    if (l % k == 0)
    {
        Node *temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
    doswap(node->left, l + 1, k);
    doswap(node->right, l + 1, k);
}

vector<int> inorder(Node *root)
{
    Node *node = root;
    vector<int> ans;
    stack<Node *> st;

    while (1)
    {
        while (node)
        {
            st.push(node);
            node = node->left;
        }
        if (st.empty())
            return ans;
        node = st.top();
        st.pop();
        ans.push_back(node->val);
        node = node->right;
    }
}

vector<vector<int>> swapNodes(vector<vector<int> > indexes, vector<int> queries)
{

    queue<Node *> q;
    Node *root = new Node(1);
    q.push(root);
    vector<vector<int> > ans;
    for (auto i : indexes)
    {
        Node *temp = q.front();
        q.pop();
        if (i[0] != -1)
        {
            temp->left = new Node(i[0]);
            q.push(temp->left);
        }
        if (i[1] != -1)
        {
            temp->right = new Node(i[1]);
            q.push(temp->right);
        }
    }

    for (auto i : queries)
    {
        doswap(root, 1, i);
        ans.push_back(inorder(root));
    }
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> arr;
    fo(0, n)
    {
        vi vv(2);
        cin>>vv[0]>>vv[1];
        arr.push_back(vv);
    }
    int q;
    cin>>q;
    vi query(q);

    fo(0,q)
    cin>>query[i];
    debug_2darr(swapNodes(arr,query));
    return 0;
}
