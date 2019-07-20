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
int ncr[1000][1000];
int main(){
    ncr[0][0]=1;
    
    for(int i=0 ; i<=10;i++){
        for(int j = 0;j<=10;j++){
            if(j>i)
                ncr[i][j]=0;
            else if (j==i || j==0)
                ncr[i][j]=1;
            else
                ncr[i][j] = ncr[i-1][j-1]+ncr[i-1][j];
        }
    }
    
    cout<<ncr[5][2]<<endl;
}
