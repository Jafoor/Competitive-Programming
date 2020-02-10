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



ll b[100];
int main()
{
    fast;
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        for(int j=0;j<32;j++){
            if(arr[i] & (1ll<<j))
                b[j]++;
        }
    }
    
    ll mx = 0;
    ll ind  = 0;
    
    for(int i=1; i<=n; i++){
        ll creat = 0;
        for(int j=0;j<32;j++){
            if(arr[i]&(1ll<<j) && b[j]==1)
                creat |= (1ll<<j);
        }
        if(creat>=mx)
        {
            mx = creat;
            ind = i;
        }
    }
    
    cout<<arr[ind];
    for(int i=1;i<=n;i++)
    {
        if(i != ind)
            cout<<' '<<arr[i];
    }
    return 0;
    
}
