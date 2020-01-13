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

char ch[22][22];

int hmx,hmy;
int n,m;
bool visited[22][22];
int dis[22][22];

void clear()
{
    for(int i=0;i<=21;i++)
    {
        for(int j=0;j<=21;j++)
        {
            dis[i][j] = 1000000;
            visited[i][j] = false;
        }
    }
}


void bfs(int x, int y)
{
    clear();
    
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    
    dis[x][y] = 0;
    visited[x][y] = true;
    
    while(!q.empty())
    {
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xx = u+X[i];
            int yy = v+Y[i];
            
            if(xx>=0 && xx<n && yy>=0 && yy<m && ch[xx][yy] != '#' && ch[xx][yy] != 'm' && !visited[xx][yy] )
            {
                visited[xx][yy] = true;
                dis[xx][yy] = min(dis[u][v]+1, dis[xx][yy]);
                q.push(make_pair(xx, yy));
            }
        }
    }
    
}

int main()
{
    fast;
    int t;
    cin>>t;
    for(int p = 1; p <= t; p++)
    {
        cin>>n>>m;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>ch[i][j];
                if(ch[i][j]=='h')
                {
                    hmx = i;
                    hmy = j;
                }
            }
        }
        int mxa,mxb,mxc;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ch[i][j] == 'a')
                {
                    bfs(i, j);
                    mxa = dis[hmx][hmy];
                }
                if(ch[i][j] == 'b')
                {
                    bfs(i, j);
                    mxb = dis[hmx][hmy];
                }
                
                if(ch[i][j] == 'c')
                {
                    bfs(i, j);
                    mxc = dis[hmx][hmy];
                }
            }
        }
        int ans = max(mxa,max(mxb,mxc));
        cout<<"Case "<<p<<": "<<ans<<endl;
        
    }
    return  0 ;
}
