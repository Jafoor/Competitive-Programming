
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


int solve(int l1,int l2, string s1, string s2)
{
    
    int ans[l1+5][l2+5];
    for(int i=0;i<=l1;i++)
    {
        ans[i][0]=0;
    }
    
    for(int i=0;i<=l2;i++)
    {
        ans[0][i] = 0;
    }
    
    for(int i=1;i<=l1;i++)
    {
        for(int j=1;j<=l2;j++)
        {
            if(s1[i-1]==s2[j-1])
                ans[i][j] = 1+ ans[i-1][j-1];
            
            else
                ans[i][j] = max(ans[i-1][j],ans[i][j-1]);
        }
    }
    
    return ans[l1][l2];
}




int main()
{
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int l1,l2;
    string s1,s2;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>l1>>l2;
        cin>>s1>>s2;
        int ans =  solve(l1, l2, s1, s2);
        
        cout<<ans<<endl;
    }
    

}
