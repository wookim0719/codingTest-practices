#include <bits/stdc++.h>
using namespace std;

int r,c,t;
int a[51][51];
int temp[51][51];
vector<pair<int,int>> cond;
vector<pair<int,int>> bad, v1,v2;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1}; 
int dy1[] = {0, -1, 0, 1};
int dx1[] = {1, 0, -1, 0};
int dy2[] = {0, 1, 0, -1};
int dx2[] = {1, 0, -1, 0}; 
int ret;

void go(vector<pair<int, int>> &v){  
    for(int i = v.size() - 1; i > 0; i--){
        a[v[i].first][v[i].second] = a[v[i - 1].first][v[i - 1].second];
    } 
    a[v[0].first][v[0].second] = 0; 
    return;
} 

vector<pair<int, int>> chung(int sy, int sx, int dy[], int dx[]){   
    vector<pair<int, int>> v; 
    int cnt = 0; 
    int y = sy; 
    int x = sx;
    while(true){ 
        int ny = y + dy[cnt];
        int nx = x + dx[cnt];  
        if(ny == sy && nx == sx)break;
        if(ny < 0 || ny >= r || nx < 0 || nx >= c){
            cnt++; 
            ny = y + dy[cnt];
            nx = x + dx[cnt];
        } 
        if(ny == sy && nx == sx)break;
        y = ny; x = nx; 
        v.push_back({ny, nx});
    }
    return v;
} 
int main(){
	    bool flag = 1; 
	cin>>r>>c>>t;
	for(int i=0; i<r;i++){
		for(int j=0; j<c; j++){
		cin>>a[i][j];
		if(a[i][j]==-1){ 
					cond.push_back({i,j});
		if(flag){
            v1 = chung(i, j, dy1, dx1);
            flag = false; 
                }
		else v2 = chung(i, j, dy2, dx2); 
            }
		if(a[i][j]>0)
		 bad.push_back({i,j});
	}
	}
	pair<int,int> up=cond[0];
	pair<int,int> down = cond[1];
	
	
	while(t--){
	fill(&temp[0][0], &temp[0][0] + 51 *51,0);
	for(int i=0; i<r; i++){		
		for(int j=0; j<c; j++){
		if(a[i][j] != -1 && a[i][j]){
		int val = a[i][j]/5;
		for(int k=0; k<4; k++){
			int ny= i+ dy[k];
			int nx= j+ dx[k];
			if(ny>=r||ny<0||nx<0||nx>=c||a[ny][nx]==-1)continue;
			temp[ny][nx] += val;
			a[i][j] -= val;
		}
		}
	}
}
	
	for(int i=0; i<r;i++){
		for(int j=0; j<c; j++){
		a[i][j] += temp[i][j];
	}
	}
 

go(v1);
go(v2);
}

for(int i=0; i<r;i++){
		for(int j=0; j<c; j++){
            if(a[i][j] != -1)ret += a[i][j];
	}	
	}
	
		cout<<ret;

	return 0;
}
