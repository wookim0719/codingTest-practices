#include <bits/stdc++.h>
using namespace std;
int n,m;
string goal;
int ret=0;
char a[101][101];
int dy[8]={-1,0,1,0,1,1,-1,-1};
int dx[8]={0,1,0,-1,1,-1,1,-1};
void go(int y,int x, int num, int d){
    if(num== goal.size()) {
        ret=1;
        return;
    }
    int ny= y+dy[d];
    int nx= x+dx[d];
    if(ny<0||nx<0||ny>=n||nx>=m||a[ny][nx]!= goal[num]) return;
    go(ny,nx,num+1,d);
}


int main() {
    cin>>goal;   
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char temp;
            cin>>temp;
            a[i][j]=temp;
        }
    }

    for(int i=0; i<n;i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == goal[0]){
                for(int k=0; k<8; k++){
                    go(i,j,1,k);
                }
            }
        }
    }
    cout<<ret;
    return 0;
}