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
int a[100];

int ternarySearchRecursion(int key,int l, int r)
{
    if(r>=l)
    {
        
        int midFirst = l+(r-l)/3;
        int midSecond = r-(r-l)/3;
        
        if(a[midFirst] == key)
        {
            return midFirst;
        }
        if(a[midSecond] == key)
        {
            return midSecond;
        }
        
        if(key < a[midFirst])
        {
            return ternarySearchRecursion(key, l, midFirst-1);
        }
        
        else if (key>a[midSecond])
    
            return ternarySearchRecursion(key, midFirst, r);
        
        else
        {
            return ternarySearchRecursion(key,midFirst+1,midSecond-1 );
        }
        
    }
    return -1;
}
int ternarySearchIterative(int key,int l, int r)
{
    while(r>=l)
    {
        
        int midFirst = l+(r-l)/3;
        int midSecond = r-(r-l)/3;
        
        if(a[midFirst] == key)
        {
            return midFirst;
        }
        if(a[midSecond] == key)
        {
            return midSecond;
        }
        
        if(key < a[midFirst])
        {
            r = midFirst - 1;
        }
        
        else if (key>a[midSecond])
        {
            l = midSecond+1;
        }
        else
        {
            l = midFirst+1;
            r = midSecond-1;
        }
        
    }
    return -1;
}
int main()
{
    fast;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    sort(a,a+n);
    
    int key ;
    cin>>key;
    int l = 0;
    int r = n;
    if(ternarySearchIterative(key, l, r) == -1)
    {
        cout<<"Index file not found"<<endl;
    }
    
    else
    {
        cout<<"Index of "<<key<<" is "<<ternarySearchIterative(key, l, r)<<endl;
    }
    
    //cout<<ternarySearchRecursion(key, l, r)<<endl;
}
