#include<vector>
#include<bits/stdc++.h>
using namespace std;
int a[101][101];
queue<pair<int,int>> q;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int visited[101][101];

int solution(vector<vector<int> > maps)
{
    for(int i=0; i<maps.size(); i++){
        for(int j=0; j<maps[i].size(); j++){
            a[i][j]= maps[i][j];
        }
    }
    int n=maps.size();
    int m=maps[0].size();
    q.push({0,0});
    visited[0][0]=1;
    while(q.size()){
        int y= q.front().first;
        int x= q.front().second;
        q.pop();
        if(y==n-1&&x==m-1)break;
        for(int i=0; i<4; i++){
            int ny= y+dy[i];
            int nx= x+dx[i];
            if(ny<0||nx<0||ny>=n||nx>=m||visited[ny][nx]||a[ny][nx]==0) continue;
            visited[ny][nx]=visited[y][x]+1;
            q.push({ny,nx});
        }
    }
    int answer = visited[n-1][m-1];
    if(answer == 0)answer=-1;
    return answer;
}
