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
const int maxn = 6e5 + 100;
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
int maxi;
bool vis[30005];
int start;
int end;
int dis[30005];
vector< vector <pair<int,int> > >g;

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    
    vis[s] = 1;
    dis[s] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        //cout<<u<<endl;
        for(int i=0;i<g[u].size();i++)
        {
            int v = g[u][i].first;
            if(vis[v] == 0)
            {
                vis[v] = 1;
                dis[v] = dis[u] + g[u][i].second;
                q.push(v);
            }
        }
    }
}
int main()
{
    fast;
    int t;
    cin>>t;
    int c= 1;
    while(t--)
    {
        int n;
        cin>>n;
        vector< vector<pair<int, int>>> temp(n+2);
        swap(temp,g);
        for(int i=0;i<n-1;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            g[u].push_back(make_pair(v, w));
            g[v].push_back(make_pair(u, w));
        }
        
        for(int i =0;i<n;i++)
        {
            dis[i] = 1000000;
        }
        memset(vis,0,sizeof(vis));
        maxi = 0;
        bfs(0);
        for(int i=0;i<n;i++)
        {
           if(dis[i]>maxi)
           {
               maxi = dis[i];
               start = i;
           }
        }
        
        maxi = 0;
        memset(vis, 0, sizeof(vis));
        for(int i= 0;i<n;i++)
        {
            dis[i] = 10000000;
        }
        bfs(start);
       
        for(int i=0;i<n;i++)
        {
           // cout<<dis[i]<<' ';
            if(dis[i]>maxi)
            {
                maxi = dis[i];
            }
        }
        
        
        cout<<"Case "<<c<<": "<<maxi<<endl;
        c++;
    }
}
