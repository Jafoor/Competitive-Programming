/// Assembly line sheduleing
/* Helped By Alamin Hossian
   JUST,CSE
 */

#include<iostream>

using namespace std;
const int maxn = 2e3;
int n , m;
int cost[maxn][3];
int entryCost[maxn];
int exitCost[maxn];
int chamberCost[maxn][maxn];
int dp[maxn][maxn];

int solve(int line , int chamber){
    if(chamber > m)return 0;
    int &ret = dp[line][chamber];
    if(ret != -1)return ret;
    ret = 0;
    if(line == 1){
        ret = chamberCost[line][chamber] + min(cost[line][0] + solve(line , chamber+1) , cost[line][2] + solve(line+1,chamber+1));
    }
    else if(line == n){
        ret = chamberCost[line][chamber] + min(cost[line][0] + solve(line , chamber+1) , cost[line][1] + solve(line-1,chamber+1));
    }
    else{
        ret = chamberCost[line][chamber] + min( cost[line][0] + solve(line , chamber+1) , min( cost[line][2] + solve(line+1,chamber+1) , cost[line][1] + solve(line-1,chamber+1) ) );
    }
    return ret;
}

void Print(int line , int chamber){
    if(chamber > m)return;
    int ret = dp[line][chamber];
    cout << line << " " << chamber << endl;
    if(line == 1){
        int cost1 = chamberCost[line][chamber] + cost[line][0] + solve(line , chamber+1);
        int cost2 = chamberCost[line][chamber] + cost[line][2] + solve(line+1 , chamber+1);
        if(ret == cost1){
            Print(line,chamber+1);
        }
        else Print(line+1,chamber+1);
        
    }
    else if(line == n){
        int cost1 = chamberCost[line][chamber] + cost[line][0] + solve(line , chamber+1);
        int cost2 = chamberCost[line][chamber] + cost[line][1] + solve(line-1 , chamber+1);
        if(ret == cost1){
            Print(line,chamber+1);
        }
        else{
            Print(line-1,chamber+1);
        }
    }
    else{
        int cost1 = chamberCost[line][chamber] + cost[line][0] + solve(line , chamber+1);
        int cost2 = chamberCost[line][chamber] + cost[line][1] + solve(line-1 , chamber+1);
        int cost3 = chamberCost[line][chamber] + cost[line][2] + solve(line+1 , chamber+1);
        if(cost1 == ret){
            Print(line,chamber+1);
        }
        else if(cost2 == ret){
            Print(line-1,chamber+1);
        }
        else{
            Print(line+1,chamber+1);
        }
    }
    return;
}


int main()
{
    cin >> n >> m;
    cout << "Enter Entry and Exit Cost : \n";
    for(int i = 1; i<=n; i++){
        cin >> entryCost[i] >> exitCost[i];
    }
    cout << "Enter station Cost : \n";
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cin >> chamberCost[i][j];
            if(j == m)chamberCost[i][j] += exitCost[i];
            if(j == 1)chamberCost[i][j] += entryCost[i];
        }
    }
    cout << "Enter Transfer Cost : \n";
    for(int i = 1; i<m; i++){
        if(i == 1){
            for(int j = 0; j<3; j++){
                cost[i][0] = 0;
                cost[i][1] = 0;
                cin >> cost[i][2];
            }
        }
        else if(i == n){
            for(int j = 0; j<3; j++){
                cost[i][0] = 0;
                cost[i][2] = 0;
                cin >> cost[i][1];
            }
        }
        else{
            for(int j = 0; j<3; j++){
                cost[i][0] = 0;
                cin >> cost[i][1] >> cost[i][2];
            }
        }
    }
    memset(dp,-1,sizeof dp);
    
    for(int i = 1; i<=n; i++){
        cout << "Line " << i << " : " << solve(i,1) << endl;
        Print(i,1);
        cout << endl;
    }
    
    
    
}
/*
 3 4
 10 15
 6 6
 7 1
 5 7 3 10
 6 3 2 4
 8 3 2 4
 1 3 1
 4 5 2
 5 4 2
 6 3 1
 
 Line 1 : 28
 Line 2 : 24
 Line 3 : 25
 
 */
