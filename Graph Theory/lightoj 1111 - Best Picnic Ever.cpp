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
#include<fstream>
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

vector<int> g[10001];

void clear()
{
    for(int i=0;i<10001;i++)
    {
        g[i].clear();
    }
}

bool visited[10001];
int cnt[10001];
int ans,k;
void dfs(int s)
{
    memset(visited, false, sizeof(visited));
    visited[s] = true;
    queue<int> q;
    q.push(s);
    cnt[s]++;
    if(cnt[s] == k)
        ans++;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for(int i=0;i<g[u].size();i++)
        {
            int v = g[u][i];
            
            if(!visited[v])
            {
                visited[v] = true;
                cnt[v]++;
                q.push(v);
                if(cnt[v] == k)
                    ans++;
            }
        }
    }
    
}

int main()
{
    fast;
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        int n,m;
        cin>>k>>n>>m;
        int a[k+1];
        for(int i=0;i<k;i++)
        {
            cin>>a[i];
        }
        
        memset(cnt, 0, sizeof(cnt));
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            //g[v].push_back(u);
        }
        
        ans  = 0;
        for(int i=0;i<k;i++)
        {
            dfs(a[i]);
        }
        
        cout<<"Case "<<t<<": "<<ans<<endl;
        clear();
        
    }
}
