#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int a[5][5];
int visiteda[5][5];
int visitedb[5][5];
int n,h;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
pair<int,int> rs;
 pair<int,int> bs;
 pair<int,int> rd;
 pair<int,int> bd;
int ret=987654321;

void go(pair<int,int> r,pair<int,int> b, int cnt){
    //cout<<r.first<<r.second<<b.first<<b.second<<cnt<<"\n";
    if(r==rd&&b==bd) {
        ret= min(ret,cnt);
        return;
    }
    if(r!=rd&&b!=bd){
    for(int i=0; i<4; i++){
        int rny= r.first+dy[i];
        int rnx= r.second+dx[i];
        if(rny<0||rnx<0||rny>=n||rnx>=h||visiteda[rny][rnx]||a[rny][rnx]==5) continue;
        visiteda[rny][rnx]=1;
        for(int j=0; j<4; j++){
           int bny= b.first+dy[j];
           int bnx= b.second+dx[j];
        if(bny<0||bnx<0||bny>=n||bnx>=h||(bny==rny&&bnx==rnx)||(bny==r.first&&bnx==r.second)||visitedb[bny][bnx]||a[bny][bnx]==5)continue;
            visitedb[bny][bnx]=1;
            go({rny,rnx},{bny,bnx},cnt+1);
            visitedb[bny][bnx]=0;
        }
        visiteda[rny][rnx]=0;
    }
    }
    else if(r!=rd&&b==bd){
        for(int i=0; i<4; i++){
            int rny= r.first+dy[i];
            int rnx= r.second+dx[i];
        if(rny<0||rnx<0||rny>=n||rnx>=h||(rny==b.first&&rnx==b.second)||visiteda[rny][rnx]||a[rny][rnx]==5) continue;
            visiteda[rny][rnx]=1;
            go({rny,rnx},b,cnt+1);
            visiteda[rny][rnx]=0;
        }
    }
    else if(r==rd&&b!=bd){
        for(int i=0; i<4; i++){
            int bny= b.first+dy[i];
            int bnx= b.second+dx[i];
        if(bny<0||bnx<0||bny>=n||bnx>=h||(bny==r.first&&bnx==r.second)||visitedb[bny][bnx]||a[bny][bnx]==5) continue;
            visitedb[bny][bnx]=1;
            go(r,{bny,bnx},cnt+1);
            visitedb[bny][bnx]=0;
        }
    }
    return;
}

using namespace std;

int solution(vector<vector<int>> m) {
    for(int i=0; i<m.size(); i++){
        for(int j=0; j<m[i].size(); j++){
            a[i][j]= m[i][j];
            if(m[i][j]==1){
               rs= {i,j}; 
            }
            if(m[i][j]==2){
                bs={i,j};
            }
            if(m[i][j]==3){
                rd={i,j};
            }
            if(m[i][j]==4){
                bd={i,j};
            }
        }
    }
    n= m.size();
    h= m[0].size();
    go(rs,bs,0);
    if(ret==987654321) ret=0;
    int answer = ret;
    return answer;
}
