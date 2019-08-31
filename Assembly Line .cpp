/* আবু জাফর মোহাম্মদ সালেহ
   Assebly line Scheduling
 
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
// #include<bits/stdc++.h>
using namespace std;

  int total_station;
  int station[3][100000];
int transfer[3][100000];
int start[3];
int End[3];
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int min(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}
int AssemblyCar( )
{
    int first_line[100000];
    int second_line[100000];
    
    first_line[0] = start[0]+station[0][0];
    second_line[0] = start[1]+station[1][0];
    
    for(int i=1;i<total_station;i++)
    {
        first_line[i] = min((first_line[i-1]+station[0][i]), (second_line[i-1]+transfer[1][i]+station[0][i]));
        second_line[i] = min(second_line[i-1]+station[1][i], first_line[i-1]+transfer[0][i]+station[1][i]);
    }
    return min(first_line[total_station-1]+End[0], second_line[total_station-1]+End[1]);
    
}

int main()
{
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout<<"Enter the number of total station : ";
    cin>>total_station;
    /// input the manufacturing cost of each station
    
    for(int i=0;i<2;i++)
    {
        cout<<"Enter the costs of station number "<<i+1<<endl;
        for(int j=0;j<total_station;j++)
        {
            cin>>station[i][j];
        }
    }
    
    /// Input the cost of transfering Raw Material from one station to another crossing way
    /// For calculation easy
    transfer[0][0] = 0;
    transfer[1][0] = 0;
    for(int i=0;i<2;i++)
    {
         cout<<"Enter the costs of transfering for station "<<i+1<<endl;
        for(int j=1;j<total_station;j++)
        {
            cin>>transfer[i][j];
        }
    }
    
    
    /// input starting cost
    cout<<"Enter starting costs : ";
    for(int i=0;i<2;i++)
    {
        cin>>start[i];
    }
    
    
    /// Input Ending cost
    cout<<"Enetr Ending costs : ";
    for(int i=0;i<2;i++)
    {
        cin>>End[i];
    }
    
    int ans = AssemblyCar();
    cout<<ans<<endl;
}
