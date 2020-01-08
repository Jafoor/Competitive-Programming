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
#define BOUNDARY(i, j) ((i >= 0 && i < m) && (j >= 0 && j < n))
#define mx 6e5 + 100;
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//#include<bits/stdc++.h>
const int maxn = 6e5 + 100;
using namespace std;
int X[] = {0, 1, 0, -1};
int Y[] = {-1, 0, 1, 0};

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
    
}
int n,m;
char ch[100][100];
int a[100][100];
int c = 1;
int dfs(int i,int j)
{
    for(int k=0;k<4;k++)
    {
        if(BOUNDARY(i+X[k],j+Y[k]) && ch[i+X[k]][j+Y[k]]=='.' && !a[i+X[k]][j+Y[k]] )
        {
            c++;
            a[i+X[k]][j+Y[k]] = 1;
            dfs(i+X[k], j+Y[k]);
        }
    }
    return c;
}


int main()
{
    fast;
    int t;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        cin>>n>>m;
        int p,q;
        c = 1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>ch[i][j];
                if(ch[i][j]=='@')
                {
                    p=i;
                    q=j;
                }
            }
        }
        
        
        memset(a,0,sizeof(a));
        
        a[p][q] = 1;
        
       int ans =  dfs(p, q);
        cout<<"Case "<<k<<": "<<ans<<endl;
        
    }
}
