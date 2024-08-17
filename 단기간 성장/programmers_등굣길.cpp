#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;
typedef pair<pair<int,int>,int> T;
int n1,n2;
int a[101][101];
int dp[101][101];
int dy[2]={1,0};
int dx[2]={0,1};
int sh=987654321;
int cnt;

int solution(int m, int n, vector<vector<int>> puddles) {
    for(int i=0; i<puddles.size(); i++){
        a[puddles[i][1]-1][puddles[i][0]-1]=1;
    }
    // queue<T> q;
     int answer = 0;
     n1=n; n2=m;
     // for(int i=0; i<n1; i++){
     //     fill(dp[i], dp[i]+101, 987654321);
     // }
    // q.push({{0,0},0});
    // while(q.size()){
    //     T f= q.front();
    //     if(f.first.first==n1-1&&f.first.second==n2-1) {
    //         if(sh>f.second){
    //         sh=f.second;
    //         cnt=1;}
    //          else if(sh==f.second){
    //         cnt++;
    //      }
    //     }
    //     q.pop();
    //     for(int i=0; i<2; i++){
    //         int ny= f.first.first+dy[i];
    //         int nx= f.first.second+dx[i];
    //         if(ny<0||nx<0||ny>=n1||nx>=n2||a[ny][nx]) continue;
    //         if(f.second<sh)
    //         q.push({{ny,nx},f.second+1});
    //     }
    // }
    dp[0][0]=1;
    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            if(a[i][j]==1) continue;
            else{
               if(i>0&&a[i-1][j]!=1){
                   dp[i][j] +=dp[i-1][j];
                   dp[i][j]%=1000000007;
               } 
                if(j>0&&a[i][j-1]!=1){
                   dp[i][j] += dp[i][j-1];
                  dp[i][j]%=1000000007;
               } 
            }
        }
    }
    answer= dp[n1-1][n2-1]%1000000007;
    return answer;
}
