
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
vector<int> adj[1002];
bool Visited[1002];

int main()
{
    /// Enter the total nodes in graph
    int nodes;
    cin >> nodes;
    
    int a[1000][1000];
    /// enter as matrix
    for(int i=0;i<nodes;i++)
    {
        for(int j=0;j<nodes;j++)
        {
            cin>>a[i][j];
            if(a[i][j]==1)
            adj[i].push_back(j);
        }
    }
    // make all visit false
    for(int i = 0; i < nodes; i++)
    {
        Visited[i ] = false;
    }

   
    /// enter source
    int scr;
    cin >> scr;
    stack<int> st;
    st.push(scr);
    
    /// until source is not empty
    while(!st.empty())
    {
        int pop = st.top();
        
        st.pop();
        
        if(!Visited[pop]){
            
            cout<<pop<<' ';
            Visited[pop] = true;
        }
        
        for(auto n = adj[pop].begin(); n != adj[pop].end();n++)
        {
            if(!Visited[*n])
                st.push(*n);
        }
    }
    return 0;
}
