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
#define fassst ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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

int arr[maxn+1];
int tree[maxn*3];
int mark[10000007];
void sieve(){
    int lim = sqrt(10000007);
    for(int i=3; i<=lim; i+=2)
        if(mark[i] == 0)
            for(int j=i*i, k=i+i; j<10000007; j+=k)
                mark[j] = 1;
}

int prime(int x){
    if(x < 2) return 0;
    if(x < 4) return 1;
    if(x%2 == 0) return 0;
    return !mark[x];
}



void init(int node, int b, int e)
{
    if (b==e){
        tree[node] = arr[b];
        return;
    }
    
    int left = node * 2;
    int right = node * 2 + 1;
    
    int mid = (b+e)/2;
    init(left, b, mid);
    init(right, mid+1, e);
    tree[node] = tree[left] + tree[right];
    
}

int query(int node, int b, int e, int i, int j)
{
    if(i>e || j< b)
        return 0;
    if(b>=i && e<=j)
        return tree[node];
    
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid+1, e, i, j);
    return p1+p2;
}

void update(int node, int b, int e, int i, int newvalue)
{
    if(i>e || i<b)
        return;
    if(b>=i && e<=i)
    {
        tree[node] = newvalue;
        return;
    }
    
    int left = node*2;
    int right = node*2 + 1;
    int mid = (b+e)/2;
    update(left, b, mid, i, newvalue);
    update(right, mid+1, e, i, newvalue);
    tree[node] = tree[left] + tree[right];
}
int main()
{
    sieve();
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(prime(arr[i])){
            arr[i] = 1;
            //cout<<arr[i]<<' ';
        }
        else{
            arr[i] = 0;
            //cout<<arr[i]<<' ';
        }
    }
    
    init(1,1,n);
    
    int m;
    cin>>m;
    while(m--)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            int x,y;
            cin>>x>>y;
            int p = query(1, 1, n, x, y);
            cout<<p<<endl;
        }
        else
        {
            int y,z;
            cin>>y>>z;
            if(prime(z))
            {
                update(1, 1, n, y, 1);
            }
            else{
               update(1, 1, n, y, 0);
            }
        }
    }
}
