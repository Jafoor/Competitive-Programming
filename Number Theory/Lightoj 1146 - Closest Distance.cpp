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
const double error = 1e-9;
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
int a[100];
double ax,ay,bx,by,cx,cy,dx,dy;
double dx1,dy1,dx2,dy2;


int cmp(double x, double y)
{
    return (x <= y+error) ? (x+error < y) ? -1 : 0 : 1;
}
double f(double x)
{
    double x1 = ax + dx1*x;
    double y1 = ay + dy1*x;
    double x2 = cx + dx2*x;
    double y2 = cy + dy2*x;
    
    double dx = x2-x1;
    double dy = y2-y1;
    
    return sqrt(dx*dx + dy*dy);
}
double ternarySearch()
{
    double l = 0.0;
    double h = 1.0;
    
    while(cmp(h,l)==1)
    {
        double l1 = (l*2.0+h)/3.0;
        double l2 = (l+2.0*h)/3.0;
        
        if(cmp(f(l1), f(l2))==-1)
            h = l2;
        else
            l = l1;
    }
    return f(l);
}

int main()
{
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;
        dx1 = bx-ax;
        dy1 = by-ay;
        dx2 = dx-cx;
        dy2 = dy-cy;
        printf("Case %d: %.10lf\n",t,ternarySearch());
    }
}
