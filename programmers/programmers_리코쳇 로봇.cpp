#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
int ret= 987654321;
vector<string> v;
struct m{
    int y,x,cnt;
};
int a,b;
int gy,gx;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int visited[101][101];
int solution(vector<string> board) {
    v=board;
    queue<m> q;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if(board[i][j]=='R'){
                a=i, b=j;
            }
            if(board[i][j]=='G'){
                gy=i;
                gx=j;
            }
        }
    }
    m temp;
    temp.y=a; temp.x=b; temp.cnt=0;
    q.push(temp);
    visited[a][b]=1;
    
    while(q.size()){
        m start = q.front();
        q.pop();
        if(start.y==gy&&start.x==gx) {
            ret= min(ret,start.cnt);
            break;
        }
        for(int i=0; i<4; i++){
            int ny=start.y;
            int nx=start.x;
            while(true){
                ny+=dy[i];
                nx+=dx[i];
                if (ny < 0 || ny >= v.size() || nx < 0 || nx >= v[0].size() || board[ny][nx] == 'D') {
                    ny -= dy[i];
                    nx -= dx[i];
                    break;
                }
            }
            if(!visited[ny][nx]){
                visited[ny][nx]=1;
                m temp2;
                temp2.y=ny; temp2.x=nx; temp2.cnt=start.cnt+1;
                q.push(temp2);
            }
            }
        
    }
    int answer = ret;
    if(answer==987654321) answer=-1;
    return answer;
}
