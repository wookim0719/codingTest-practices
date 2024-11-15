#include<bits/stdc++.h>
using namespace std;
typedef pair<pair<int,int>,int> pp;
int a[101][101];
int visited[101][101];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
void drawLine(int fx,int fy, int sx,int sy){
    for(int i=fx; i<=sx; i++){
        if(a[i][fy]!=-1){
            a[i][fy]=1;
        }
        if(a[i][sy]!=-1){
            a[i][sy]=1;
        }
    }
    for(int i=fy; i<=sy; i++){
        if(a[fx][i]!=-1){
            a[fx][i]=1;
        }
        if(a[sx][i]!=-1){
            a[sx][i]=1;
        }
    }
     for(int i=fx+1; i<sx; i++){
         for(int j=fy+1; j<sy; j++){
             a[i][j]=-1;
         }
     }     
    return;
}

int solution(vector<vector<int>> rect, int cx, int cy, int ix, int iy) {
    int answer = 0;
    
    for(int i=0; i<rect.size(); i++){
        drawLine(rect[i][0]*2,rect[i][1]*2,rect[i][2]*2,rect[i][3]*2);
    }
    visited[cx*2][cy*2]=1;
    queue<pp> q;
    q.push({{cx*2,cy*2},0});
    while(q.size()){
        auto fv= q.front();
        int nowy= fv.first.second;
        int nowx= fv.first.first;
        int cnt = fv.second;
        cout<<nowx<<" "<<nowy<<" "<<cnt<<"\n";
        if(nowy==iy*2&&nowx==ix*2) {
            answer= cnt;
            break;
        }
        q.pop();
        for(int i=0; i<4; i++){
            int ny= nowy+dy[i];
            int nx= nowx+dx[i];
            if(ny<0||nx<0||ny>100||nx>100||visited[nx][ny]||a[nx][ny]!=1) continue;
            visited[nx][ny] = 1;
            q.push({{nx,ny},cnt+1});}
        }
    
    return answer/2;
}
