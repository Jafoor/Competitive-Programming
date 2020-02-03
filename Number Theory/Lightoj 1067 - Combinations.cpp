/*
 Abu Jafor Mohammad Saleh
 ios_base :: sync_with_stdio(false);
 cin.tie(NULL);
 
 For More Details :
 https://discuss.codechef.com/t/best-known-algos-for-calculating-ncr-m/896/2
 
 nCr = n-1Cr + n-1Cr-1
 
 Since there are no divisions involved (no multiplications too) the answer is easy and precise to calculate even if the actual binomials would be very large.
 
 So, back to calculating
 
 [ n! / ( r! (n-r)! ) ] % M, you can convert it to
 
 n * (n-1) … * (n-r+1) * r-1 * (r-1)-1 … * 1
 
 Of course, each product is maintained modulo M.
 
 This may be fast enough for problems where M is large and r is small.
 
 But sometimes, n and r can be very large. Fortunately, such problems always have a small enough M :smiley:
 
 The trick is, you pre-calculate factorials, modulo M and pre-calculate inverse factorials, modulo M.
 
 fact[n] = n * fact[n-1] % M
 ifact[n] = modular_inverse(n) * ifact[n-1] % M
 
 Modular Multiplicative Inverse for a prime M is in fact very simple. From Fermat’s Little Theorem 62
 
 AM-1 % M = 1
 
 Hence, A * AM-2 % M = 1
 Or in other words,
 
 A-1 % M = AM-2 % M, which is easy (and fast) to find using repeated squaring 33.
 
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
#define mx 6e5 + 100;
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
ll BigMod (ll a, ll b)
{
    if(b==0)
        return 1;
    ll x = BigMod(a,b/2);
    
    x = (x*x)% MOD;
    
    if(b%2)
        x = (x*a)%MOD;
    
    return x;
}

ll ModInverse(ll a)
{
    return BigMod(a, MOD-2);
}

ll fecto[maxn];

void preCalculate()
{
    fecto[1] = 1;
    
    for(ll i=2; i <maxn; i++)
    {
        fecto[i] = (fecto[i-1] * i) % MOD;
    }
}


int main()
{
    int T;
    cin>>T;
    preCalculate();
    for(int t=1; t<=T; t++)
    {
        ll num, choose;
        cin>> num >> choose;
        cout<<"Case "<<t<<": ";
        
        if(num<choose)
        {
            cout<<0<<endl;
            continue;
        }
        
        if(num == choose  || choose == 0)
        {
            cout<<1<<endl;
            continue;
        }
        
        ll upfect = fecto[num];
        
        ll downfect = ((fecto[num-choose] % MOD) * (fecto[choose]%MOD)) % MOD;
        
        ll ans = ((upfect % MOD) * ModInverse(downfect)) % MOD;
        
        cout<<ans<<endl;
    }
    
}

