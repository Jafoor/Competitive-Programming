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

#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define BOUNDARY(i, j) ((i >= 0 && i < rows) && (j >= 0 && j < coloums))
#define mx 6e5 + 100;
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//#include<bits/stdc++.h>
#define ll long long
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
char ch[502][502];
int visited[502][502];
int c;
int solve(int r , int cc)
{
    for(int i=0;i<4;i++)
    {
        //cout<<r+X[i]<<' '<<cc+Y[i]<<endl;
        if(BOUNDARY(r+X[i], cc+Y[i]) && (ch[r+X[i]][cc+Y[i]] =='.' || ch[r+X[i]][cc+Y[i]]=='C') && !visited[r+X[i]][cc+Y[i]]  )
        {
            //cout<<ch[r+X[i]][cc+Y[i]]<<endl;
            if(ch[r+X[i]][cc+Y[i]]=='C'){
                c++;
               // cout<<c<<endl;
            }
        
            visited[r+X[i]][cc+Y[i]] = true;
            solve(r+X[i], cc+Y[i]);
        }
    }
    
    return c;
}

int main()
{
    int t;
    cin>>t;
    int T=1;
    while(t--)
    {
        ll x;
        cin>>rows>>coloums>>x;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<coloums;j++)
            {
                cin>>ch[i][j];
            }
        }
        int a[502][502];
        memset(a, -1, sizeof(a));
        cout<<"Case "<<T<<":"<<endl;
        while(x--)
        {
            memset(visited,false,sizeof(visited));
            
            c = 0;
             int p1,p2;
            cin>>p1>>p2;
            p1 = p1-1;
            p2 = p2-1;
            if(a[p1][p2] != -1){
                cout<<a[p1][p2]<<endl;
                continue;
            }
            if(ch[p1][p2]=='#')
            {
                cout<<0<<endl;
                continue;
            }
            if(ch[p1][p2] == 'C')
                c++;
            visited[p1][p2] = true;
            int ans = solve(p1,p2);
            cout<<ans<<endl;
            for(int i=0;i<rows;i++)
            {
                for(int j=0;j<coloums;j++)
                {
                    if(visited[i][j])
                        a[i][j]  = ans;
                }
        }
        }
        T++;
    }
}
