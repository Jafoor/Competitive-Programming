

/// আবু জাফর মোহাম্মদ সালেহ
#include<iostream>
#include<vector>
using namespace std;
#define maxn 100000

vector<int> nodes[maxn];
vector<int> edges[maxn];

void print(int n)
{
    for(int i=1;i<=n;i++)
    {
        cout<<i<<"->";
        for(int j=0;j<nodes[i].size();j++)
        {
            cout<<nodes[i][j]<<' ';
        }
        cout<<endl;
    }
}

int main()
{
    int numberofnodes,numberofedges;
    cin>>numberofnodes>>numberofedges;
    
    
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
    
    print(numberofedges);
    
}
