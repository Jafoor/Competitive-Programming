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
#define MOD 1000003

#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define BOUNDARY(i, j) ((i >= 0 && i < rows) && (j >= 0 && j < coloums))
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//#include<bits/stdc++.h>
#define ll long long
const int maxn = 1000001;
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


int main()
{
    fast;
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        double x,y,c;
        
        cin>>x>>y>>c;
        
        double mx = max(x,y);
        double mn = 0.0;
        double mid = (mx+mn)/2;
        
        for(int j = 0;j<=40;j++)
        {
            double xx = sqrt(x*x-mid*mid);
            double yy = sqrt(y*y-mid*mid);
            
            double t_ans = 1.0/xx + 1.0/yy;
            t_ans = 1.0/t_ans;
           // cout<<mx<<' '<<mn<<' '<<t_ans<<endl;
            if(t_ans>=c)
                mn = mid;
            else
                mx = mid;
            
            mid = (mx+mn)/2;
        }
        
        
        printf("Case %d: %.10lf\n",i,mn);
    }
}
