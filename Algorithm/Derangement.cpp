//
//  main.cpp
//  Programming
//
//  Created by Abu Jafor Mohammad Saleh on 11/7/19.
//  Copyright © 2019 Abu Jafor Mohammad Saleh. All rights reserved.
//
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
//#define ll long long
#define f first
#define s second

//#define ll long long

using namespace std;
long long  ncr[1000][1000];
long long derangement[10000];

long long  dp(long long  n){
    if(n==1)
        return 0;
    else if(n==1 || n==2)
        return 1;
    
    else{
        return (n-1)*dp(n-1)+ (n-1)*dp(n-2);
    }
}

long long DP(long long n){
    derangement[0]=1;
    derangement[1]=0;
    derangement[2]=1;
    for(int i=3;i<=n;i++)
    {
        derangement[i] = (i-1)*derangement[i-1]+(n-1)*derangement[i-2];
    }
    return derangement[n];
}
int main(){
    int n;
    cin>>n;
    long long  ans = DP(n);
    cout<<ans<<endl;
}
