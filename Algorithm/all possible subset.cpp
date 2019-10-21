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
#define f first
#define s second
#define MOD 1000000007
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//#include<bits/stdc++.h>
using namespace std;

void possibleSubsets(char A[], int N)
{
    for(int i = 0;i < (1 << N); ++i)
    {
        for(int j = 0;j < N;++j)
            if(i & (1 << j))
                cout << A[j] << ' ';
        cout << endl;
    }
}

int main()
{
    int n;
    cin>>n;
    char a[100];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    possibleSubsets(a,n);
}
