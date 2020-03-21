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

//#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
const int maxn = 100001;
using namespace std;
int X[] = {0, 1, 0, -1};
int Y[] = {-1, 0, 1, 0};
int rows,coloums;
long long  gcd(long long  a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll bigMod(ll x, ll n)
{
    if (x==0)
        return 1;
    if(n==0)
        return 1;
    
    if(n%2==0)
        return bigMod((x%MOD * x%MOD)%MOD, n/2);
    else
        return (x * bigMod((x%MOD * x%MOD)%MOD, n/2));
    
}

int main()
{
    fast;
    
    cout<<"Enter the value of x and n : ";
    
    ll x, n;
    cin>>x>>n;
    
    cout<<bigMod(x, n)<<endl;
    
}
