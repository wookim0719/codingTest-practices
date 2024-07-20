#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
vector<int> up[101];
vector<int> down[101];
int visited[101][101];
queue<int> q;
queue<int> q2;
int ret;

int solution(int n, vector<vector<int>> results) {
    for(int i=0; i<results.size(); i++){
        up[results[i][0]].push_back(results[i][1]);
        down[results[i][1]].push_back(results[i][0]);
    }
   for(int idx=1; idx<=n; idx++){
       int cnt=0;
        visited[idx][idx]=1;
         q.push(idx);
         q2.push(idx);
    while(q.size()){
      int v=q.front();
      q.pop();
      for(int i=0; i<up[v].size(); i++){
          if(!visited[idx][up[v][i]]){
              visited[idx][up[v][i]]=1;
              q.push(up[v][i]);
          }
      }
    }
    while(q2.size()){
    int v=q2.front();
      q2.pop();
             for(int i=0; i<down[v].size(); i++){
          if(!visited[idx][down[v][i]]){
              visited[idx][down[v][i]]=1;
              q2.push(down[v][i]);
          }
      }
    }
    
    for(int i=1;i<=n; i++)
        if(visited[idx][i]==1) cnt++;
       
       if(cnt==n) {
           ret++;
       }
   }
    
    int answer = ret;
    return answer;
}
