/*
 Abu Jafor Mohammad Saleh
 github: Jafoor
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

#include <math.h>
#define f first
#define s second
#define MOD 1000000007

#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define BOUNDARY(i, j) ((i >= 0 && i < rows) && (j >= 0 && j < coloums))

//#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long

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


void print1to10(int n){
    
    cout<<n<<endl;
    if(n==0)
        return;
    else
        print1to10(n-1);
    
}
    
    


int main(){
    
    cout<<"Enter an integer input : "<<endl;
    int n;
    cin>>n;
    print1to10(n);

}
