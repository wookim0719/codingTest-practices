#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[13][13];
vector<int> b[13][13];
int dy[4] = {0,0,-1,1};
int dx[4] = {1,-1,0,0};
struct horse{
 int y,x,dir;	
};
vector<horse> v;

void move(int y,int x, int dir,int i){
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if(ny < 0 || ny >= n || nx < 0 || nx >= n || a[ny][nx] == 2){
        v[i].dir ^= 1;  
        ny = y + dy[v[i].dir]; 
        nx = x + dx[v[i].dir];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || a[ny][nx] == 2) return; 
    }
	// 한칸이동 로직
    vector<int> &here_v = b[y][x];
    vector<int> &next_v = b[ny][nx];
    auto pos = find(here_v.begin(), here_v.end(), i); 
	// 뒤집어서 보내기
    if(a[ny][nx] == 1) reverse(pos, here_v.end()); 
	for(auto it = pos; it != here_v.end(); it++){
        next_v.push_back(*it); 
        v[*it].y = ny; 
        v[*it].x = nx;  
    }
    here_v.erase(pos, here_v.end()); 
    return;  
}



int main(){
	cin>>n>>k;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=0; i<k; i++){
		int temp1,temp2,temp3;
		cin>>temp1>>temp2>>temp3;
		temp1--; temp2--; temp3--;
		v.push_back({temp1,temp2,temp3});
		// 몇 번 말이 존재하는지 넣어주기 위해서 사용  
		b[temp1][temp2].push_back(i);
	}
	int cnt=0;
	int flag=0;
	while(cnt<=1000){
		cnt++;
		for(int i=0; i<v.size(); i++){
			 int y = v[i].y;
       		 int x = v[i].x;
        	 int dir = v[i].dir;
			move(y,x, dir,i);
				for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(b[i][j].size()>=4)
					flag =1;
			}
		}
		}
	
		
		if(flag ==1) break;
	}
		
if(flag) cout << cnt << "\n";
    else cout << -1 << "\n";	
	return 0;
}
