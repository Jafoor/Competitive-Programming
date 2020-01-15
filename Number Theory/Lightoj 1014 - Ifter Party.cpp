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

int main()
{
    fast;
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        int n,m;
        cin>>n>>m;
        vector<int> v;
        cout<<"Case "<<t<<": ";
        if(m*2>=n)
        {
            cout<<"impossible"<<endl;
            continue;
        }
        
        int x = n-m;
        for(int i=1;i<=sqrt(x);i++)
        {
            if(x%i==0 && i != (x/i))
            {
                v.push_back(i);
                v.push_back(x/i);
            }
            else if(x%i==0 && i == (x/i))
            {
                v.push_back(i);
            }
        }
        
        sort(v.begin(),v.end());
        
        vector<int> ans;
        for(int i=0;i<v.size();i++)
        {
            if(n%v[i]==m)
            {
                ans.push_back(v[i]);
            }
        }
        
        if(ans.size()==0)
        {
            cout<<"impossible"<<endl;
        }
        else{
            for(int i=0;i<ans.size();i++)
            {
                if(i!= ans.size()-1)
                cout<<ans[i]<<' ';
                else
                    cout<<ans[i];
            }
            cout<<endl;
        }
    }
}
