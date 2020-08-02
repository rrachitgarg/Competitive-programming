/*
Author : RachitG
Question: Find the largest rectangle in an array of buildings
Question link: https://www.hackerrank.com/challenges/largest-rectangle/problem
*/

#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define ull unsigned long long
#define vl vector<ll>
#define vi vector<int>
#define fo(i,x,n) for(int i=x;i<n;i++)
#define pb push_back
#define debug(n)   cout<<n<<endl;
#define debug_arr(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" ";
#define debug_2darr(arr,n) for(int i=0;i<n;i++) { for(int j=0;j<arr[i].size();j++) cout<<arr[i][j]<<" ";   cout<<endl;  }
#define newline cout<<endl;

long largestRectangle(vector<ll> h) {

    stack<int>st;
    ll ans = -1;
    int n = h.size();
    fo(i,0,n)
    {
        if(st.empty() || h[i]>h[st.top()])
            st.push(i);
        else
        {
            while(!st.empty() && h[st.top()]>h[i])
            {
                int x = st.top();   st.pop();
                if(st.empty())
                    ans = max(ans,i*h[x]);
                else
                ans = max(ans,h[x]*(i-st.top()-1));
            }
            st.push(i);
        }
    }
    while(!st.empty())
    {
        int x = st.top();   st.pop();
        if(st.empty())
            ans = max(ans,n*h[x]);
        else
            ans = max(ans,h[x]*(n-st.top()-1));
    }
    return ans;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vl arr(n);
    fo(i,0,n){
        cin>>arr[i];
    }
    debug(largestRectangle(arr));

    return 0;
}


