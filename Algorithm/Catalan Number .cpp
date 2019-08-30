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
#define ll long long
#define f first
#define s second
using namespace std;

///In normal Process..

long long catalan (long long n)
{
    if(n<=1)
        return 1;
    
    long long res = 0;
    for(int i=0;i<n;i++){
        res+= catalan(i)*catalan(n-i-1);
    }
    return res;
}


///In DP process..
long long CATALAN(long long n){
    
    long long CATALAN[n+1];
    
    CATALAN[0]  = CATALAN[1] = 1;
    
    for(int i =2;i<=n;i++){
        CATALAN[i]=0;
        
        for(int j=0;j<i;j++){
            CATALAN[i] += CATALAN[j]+CATALAN[i-j-1];
        }
    }
    
    return CATALAN[n];
}


///In Bionominal Coefficient Process...

long long CATALANBIO(long long n,long long k){
    
    long long res =1;
    
    //since C(n,k) = C(n, n-k)
    
    if(k> n-k)
        k = n-k;
    
    for(int i=0; i<k; i++){
        res *= (n-i);
        res /= (i+1);
    }
    return res;
    
}

int main(){
    ios::sync_with_stdio(0);
    /* Catalan Number
     Cn =  1/   (2n
          n+1     n)
     */
    
    for(int i=0; i<10; i++){
        cout<< catalan(i) << " ";
    }
}
