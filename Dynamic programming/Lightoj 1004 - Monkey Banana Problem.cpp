/*
 Abu Jafor Mohammad Saleh
 ios_base :: sync_with_stdio(false);
 cin.tie(NULL);
 */

#include<cstdio>
#include<iomanip>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include<limits>
#include <algorithm>
#include <unordered_map>
#define f first
#define s second
#define MOD 1000000007
#define ll long long
#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define BOUNDARY(i, j) ((i >= 0 && i < rows) && (j >= 0 && j < columns))
#define mx 6e5 + 100;
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//#include<bits/stdc++.h>
const int maxn = 20005;
using namespace std;
int X[] = {0, 1, 0, -1};
int Y[] = {-1, 0, 1, 0};
int rows,coloums;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int dp[301][301];
int a[301][301];
int n,k;

int solve(int i,int j)
{
    if(a[i][j] == 0)
        return 0;
    
    if(i==k-1)
        return a[i][j];
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int x =0 , x1 = 0;
    
    x = a[i][j]+solve(i+1, j);
    x1 = a[i][j]+solve(i+1, j+1);
    
    dp[i][j] = max(x1,x);
    return dp[i][j];
}
int main()
{
    fast;
    int t;
    cin>>t;
    int c = 1;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        memset(a, 0, sizeof(a));
        
        cin>>n;
        k = 2*n - 1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                cin>>a[i][j];
            }
        }
        
        int p = 1;
        for(int i=n;i<k;i++)
        {
            for(int j = p; j<n; j++)
            {
                cin>>a[i][j];
            }
            p++;
        }
        
        cout<<"Case "<<c<<": "<<solve(0,0)<<endl;
        c++;
    }
}
