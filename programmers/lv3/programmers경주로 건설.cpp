#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;
int a[26][26];
int visited[26][26][4];
int dy[4]= {-1,1,0,0};
int dx[4]= {0,0,1,-1};
map<int,int> mp;
int ret=987654321;
int n;
struct z{ 
    int y, x,cost,d;
};
queue<z> q;

int solution(vector<vector<int>> board) {
    mp[0]=1;
    mp[1]=0;
    mp[3]=2;
    mp[2]=3;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            a[i][j]= board[i][j];
        }
    }
    n= board.size();
    z temp; temp.y=0; temp.x=0; temp.cost=0; temp.d=-1;
    q.push(temp);
    memset(visited,-1,sizeof(visited));
     visited[0][0][0]=0;
    while(q.size()){
     z now = q.front();
    if(now.y==n-1&&now.x==n-1){
        ret=min(ret,now.cost);
    }
        q.pop();
        for(int i=0; i<4; i++){
            int ny= now.y+dy[i];
            int nx= now.x+dx[i];
            if(ny<0||nx<0||ny>=n||nx>=n||a[ny][nx]==1)continue;
            z next;
            next.cost=now.cost+100;
            if(i!=now.d&&i!=mp[now.d]&&now.d!=-1) {
                next.cost+=500;
            }
            if(visited[ny][nx][i]==-1){
            next.y= ny; next.x=nx; next.d=i;
            visited[ny][nx][i]=next.cost;
            q.push(next); 
            }
            if(visited[ny][nx][i]!=-1&&visited[ny][nx][i]>next.cost){
            next.y= ny; next.x=nx; next.d=i;
            visited[ny][nx][i]=next.cost;
            q.push(next); 
            }
        }
    }
    int answer = ret;
    return answer;
}
