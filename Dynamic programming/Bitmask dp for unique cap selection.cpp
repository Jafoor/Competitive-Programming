/// bit mask dp
/*
There are 100 different types of caps each having a unique id from 1 to 100. Also, there are ‘n’ persons each having a collection of a variable number of caps. One day all of these persons decide to go in a party wearing a cap but to look unique they decided that none of them will wear the same type of cap. So, count the total number of arrangements or ways such that none of them is wearing the same type of cap.

Constraints: 1 <= n <= 10 Example:
*/

/*
 
 ios_base :: sync_with_stdio(false);
 cin.tie(NULL);
 
 */

#include<stdio.h>
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
#define ll long long
#define f first
#define s second
#define MOD 1000000007
//#include<bits/stdc++.h>
using namespace std;

vector<long long > capList [101];
long long  dp [1025][101];
long long  allmask;

long long int countWaysUtil(int mask, int i)
{
    if(mask == allmask)
        return 1;
    
    if(i>100)
        return 0;
    
    if(dp[mask][i] != -1)
        return dp[mask][i];
    
    long long int ways = countWaysUtil(mask, i+1);
    
    long long  size = capList[i].size();
    
    for(int j=0; j<size;j++){
        
        if( mask & (1 << capList[i][j]))
            continue;
        
        else
            ways += countWaysUtil(mask | (1 << capList[i][j]), i+1);

        ways %= MOD;
    }
    return dp[mask][i] = ways;
}

void countways(int n)
{
    string temp,str;
    int x;
    getline(cin , str);
    for(int i=0;i<n;i++)
    {
        getline(cin,str);
        stringstream ss(str);
        
        while (ss>> temp) {
            stringstream s;
            s << temp;
            s >> x;
            capList[x].push_back(i);
        }
    }
    
    allmask = (1<<n)-1;
    cout<<allmask<<endl;
    memset(dp, -1, sizeof(dp));
    
    cout<<countWaysUtil(0,1)<<endl;
}

int main()
{
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    countways(n);
    return 0;
}
