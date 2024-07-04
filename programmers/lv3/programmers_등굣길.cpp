#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int a[100][100];
// int dy[2]={1,0};
// int dx[2]={0,1};
int dp[101][101];
int cnt;

// ll dfs(int y,int x){
//     if(y==nn-1&&x==mm-1) return 1;
//     ll &res= dp[y][x];
//     if(res) return res;
//     for(int i=0; i<2; i++){
//         int ny=y+dy[i];
//         int nx=x+dx[i];
//         if(ny>=nn||nx>=mm||a[ny][nx]==-1) continue;
//         res = res+ dfs(ny,nx);
//     }
//     return res;
// }

int solution(int m, int n, vector<vector<int>> puddles) {
    for(int i=0; i<puddles.size(); i++){
          a[puddles[i][1]-1][puddles[i][0]-1]= -1;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(j==0&&i==0) dp[i][j]=1;
            else if(j==0){
                if(a[i-1][j]!=-1){
                   dp[i][j]= dp[i-1][j];
                }
            }
            else if(i==0){
                if(a[i][j-1]!=-1)
                dp[i][j] = dp[i][j-1];
            }
            else{
                if(a[i-1][j]!=-1)
                dp[i][j]+= dp[i-1][j];
                 if(a[i][j-1]!=-1)
                dp[i][j]+=dp[i][j-1]; 
                dp[i][j]%=1000000007;
            }
        }
    }
    int ret= dp[n-1][m-1];
    return ret;
}
