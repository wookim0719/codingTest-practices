#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
int ret;
int dp[501][501];
int solution(vector<vector<int>> t) {
    
    dp[0][0]=t[0][0];
    
    for(int i=0; i<t.size()-1; i++){
        for(int j=0; j<t[i].size(); j++){
            if(j<=i){
                if(dp[i+1][j+1]<t[i+1][j+1]+dp[i][j]){
                    dp[i+1][j+1]= t[i+1][j+1]+dp[i][j];
                }
            }
            if(dp[i+1][j]<t[i+1][j]+dp[i][j]){
                dp[i+1][j]= t[i+1][j]+dp[i][j];
            }
        }
    }
    for(int i=0; i<t.size(); i++){
        ret=max(ret,dp[t.size()-1][i]);
    }
    
    int answer = ret;
    return answer;
}
