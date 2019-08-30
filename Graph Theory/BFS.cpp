

/// আবু জাফর মোহাম্মদ সালেহ
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define maxn 100000

vector<int> nodes[maxn];
vector<int> edges[maxn];
int level[maxn];
queue<int> q;
void bfs(int n){
    
    level[n] = 1;
    q.push(n);
    
    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(int i=0;i<nodes[p].size();i++){
            int x = nodes[p][i];
            
            if(level[x]==0){
                level[x] = level[p]+1;
                q.push(x);
            }
        }
    }
}

int main()
{
    int numberofnodes,numberofedges,source;
    cin>>numberofnodes>>numberofedges>>source;
    
    
    /// ভেক্টরের মাধ্যমে ইনপুট নেওয়া
    for(int i=1;i<=numberofedges;i++)
    {
        int x,y;
        cin>>x>>y;
        nodes[x].push_back(y);
        nodes[y].push_back(x);
        
        edges[x].push_back(1);
        edges[y].push_back(1);
    }
    bfs(source);
    
    for(int i=1;i<=numberofnodes;i++){
        cout<<i<<"----->"<<level[i]<<endl;
    }
    
    
}
