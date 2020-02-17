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
        long long n;
        cin>>n;
        long long x = ceil(sqrt(n*1.0));
 
        long long y = x-1;
 
       // cout<<x<<' '<<y<<endl;
        ll l_range = y*y + 1;
 
        ll h_range = x*x;
 
        ll mid = h_range-x+1;
 
        cout<<"Case "<<i<<": ";
        if(l_range%2==0)
        {
            //cout<<"l_range"<<endl;
            if(n>=mid)
            {
                cout<<x<<' '<<(x-(n-mid))<<endl;
            }
            else
            {
                cout<<(x-(mid-n))<<' '<<x<<endl;
            }
        }
 
        else{
            if(n>=mid)
            {
                cout<<(x-(n-mid))<<' '<<x<<endl;
            }
            else
            {
                cout<<x<<' '<<(x-(mid-n))<<endl;
            }
        }
 
 
    }
}