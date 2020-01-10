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
vector<int> g[maxn];
int colour[maxn];
int vampire;
int lyk;
int black = 2;
int red = 1;
int white = 0;

void clear()
{
    for(int i=0; i<maxn;i++)
    {
        g[i].clear();
    }
}

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    colour[s] = black;
    vampire++;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++)
        {
            int v = g[u][i];
            
            if(colour[v]==white)
            {
                q.push(v);
                if(colour[u]==black)
                {
                    lyk++;
                    colour[v] = red;
                }
                else{
                    vampire++;
                    colour[v] = black;
                }
            }
        }
    }
}

int main()
{
    fast;
    int t;
    cin>>t;
    for(int k=1; k<=t;k++)
    {
        int n;
        cin>>n;
        
        for(int x=0; x<n; x++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        memset(colour,0,sizeof(colour));
        
        int ans = 0;
        for(int i=0;i<maxn;i++)
        {
            if(!g[i].empty() && colour[i]==white)
            {
                vampire = 0;
                lyk = 0;
                bfs(i);
                 ans += max(vampire,lyk);
            }
           
        }
        cout<<"Case "<<k<<": "<<ans<<endl;
        clear();
    }
}
