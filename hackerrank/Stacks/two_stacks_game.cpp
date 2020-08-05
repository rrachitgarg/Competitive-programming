/*
Author : RachitG
Question: Game of two stacks
Question link: https://www.hackerrank.com/challenges/game-of-two-stacks/problem
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
#define debug_arr(arr) for(int i=0;arr.size();i++) cout<<arr[i]<<" ";
#define debug_2darr(arr) for(int i=0;arr.size();i++) { for(int j=0;j<arr[i].size();j++) cout<<arr[i][j]<<" ";   cout<<endl;  }
#define newline cout<<endl;

int twoStacks(int x, vector<int> a, vector<int> b) {
int ans=0;
int s1=a.size(),s2=b.size();

vl arr1(s1+1),arr2(s2+1);
arr1[0]=arr2[0]=0;
for(int i=1;i<=s1;i++)
{
    arr1[i] = arr1[i-1]+a[i-1];
}
for(int i=1;i<=s2;i++)
{
    arr2[i] = arr2[i-1]+b[i-1];
}

int j=s2;
for(int i=0;i<=s1;i++)
{
    ll k=arr1[i];
    if(k>x)
        break;
    while(j>=0 && arr2[j]+k>x)
        j--;
    ans=max(ans,i+j);
}

return ans;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){

        int n,m,x;
        cin>>n>>m>>x;
        vi a(n),b(m);
        fo(i,0,n)
            cin>>a[i];
        fo(i,0,m)
            cin>>b[i];
        debug(twoStacks(x,a,b));
    }

    return 0;
}

