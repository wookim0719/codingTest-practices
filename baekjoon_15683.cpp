#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[9][9];
int visited[9][9];
int ret = 987654321;
int cnt; 
int cnt2;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
// cctv가 저장된 장소를 저장  
vector<pair<int,int>> v;
// 나올 수 있는 모든 string값들 저장  
vector<string> vv;

// 여기서는 방향과 위치그리고 cctv종류를 받아서 실행  
//그런데 위치를 알면 종류를 알수 잇으므로 위치만 받는다.    
void explore(int p, int dir){
	int y= v[p].first;
	int x= v[p].second;
if(a[y][x] == 1){
        while(true){
            int ny = y + dy[dir]; 
            int nx = x + dx[dir]; 
            if(ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6){
                if(a[ny][nx] == 0){
                    visited[ny][nx] ++; 
                }
                y = ny; 
                x = nx; 
            }else break;
        }
    }else if(a[y][x] == 2){
        for(int i = 0; i <= 2; i +=2){
            int _y = y;
            int _x = x;
            while(true){
                int ny = _y + dy[(dir + i) % 4];
                int nx = _x + dx[(dir + i) % 4]; 
                if(ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6){
                    if(a[ny][nx] == 0){visited[ny][nx]++;}
                    _y = ny;
                    _x = nx;
                }else break;
            }
        }
    }else if(a[y][x] == 3){
        for(int i = 0; i < 2; i++){
            int _y = y;
            int _x = x;
            while(true){
                int ny = _y + dy[(dir + i) % 4];
                int nx = _x + dx[(dir + i) % 4];
                if(ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6){
                    if(a[ny][nx] == 0){visited[ny][nx]++;}
                    _y = ny;
                    _x = nx;
                }else break;
            }
        }
    }else if(a[y][x] == 4){
        for(int i = 0; i < 3; i++){
            int _y = y;
            int _x = x;
            while(true){
                int ny = _y + dy[(dir + i) % 4];
                int nx = _x + dx[(dir + i) % 4];
                if(ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6){
                    if(a[ny][nx] == 0){visited[ny][nx]++;}
                    _y = ny;
                    _x = nx;
                }else break;
            }
        }
    }else if(a[y][x] == 5){
        for(int i = 0; i < 4; i++){
            int _y = y;
            int _x = x;
            while(true){
                int ny = _y + dy[(dir + i) % 4];
                int nx = _x + dx[(dir + i) % 4]; 
                if(ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6){
                    if(a[ny][nx] == 0){visited[ny][nx]++;}
                    _y = ny;
                    _x = nx;
                }else break;
            }
        }
    }
//		for(int j=0; j<m; j++){
//			cout<<visited[i][j];
//		}
//		cout<<"\n";
//	}
//	cout<<"\n";
    return ; 	
	
}
void dfs(string z){
	int aaa;
	 memset(visited, 0, sizeof(visited));
	// string값을 받아서 계산한다. string의 한 문자가 의미하는건 방향이다.  
	for(int i=0; i<z.size(); i++){
		 explore(i, z[i]-'0');
	} 
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(visited[i][j]==0&&a[i][j]==0) aaa++;
		}
	}
	ret = min(aaa,ret);
	return;
}

void cal(){
	for(auto k: vv){
		// vv에 있는 string을 넘겨주고 몇 번째  
		for(int i=0; i<k.size(); i++){
			dfs(k);
		}
	}
	return;
}

void go(string s){
	if(s.size() == cnt) {
		vv.push_back(s);
		return ;
	}
		string t = s;
		go(t+'0');
		go(t+'1');
		go(t+'2');
		go(t+'3');
	return; 
}

int main(){
	cin>>n>>m;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
		cin>>a[i][j];
		if(a[i][j]==0) cnt2++;
		if(a[i][j]!=0 && a[i][j] != 6){
			v.push_back({i,j});
			cnt++;
		}
	}
	}
	
	go("");
	cal();
	if(cnt==0) cout<<cnt2;
	else if(cnt2==0) cout<<0;
	else
	cout<<ret;
	
	return 0;
}
