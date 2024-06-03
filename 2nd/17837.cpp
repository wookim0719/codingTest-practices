#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[12][12];
vector<int> v[12][12];
int dy[4]= {0,0,-1,1};
int dx[4]= {1,-1,0,0};
struct h{
	int yy,xx,dd;
};
h horse[10];
int ret;

void move_horse(int y, int x, int ny, int nx, vector<int>& temp2){
	for(int i: temp2){
		horse[i].xx=nx;
		horse[i].yy=ny;
		} 
	return;
}

int redirect(int dir){
	if(dir==0) dir=1;
	else if(dir==1) dir=0;
	else if(dir==2) dir=3;
	else dir=2;
	
	return dir;
}

bool go(int num){
	h& now= horse[num];
	int dir= now.dd;
	int y= now.yy;
	int x= now.xx;
	int ny= y+dy[dir];
	int nx= x+dx[dir];
	if(ny<0||nx<0||ny>=n||nx>=n) {
	dir= redirect(dir);
	horse[num].dd = dir;
	ny= y+dy[dir];
	nx= x+dx[dir];
	}
	int type = a[ny][nx];
	//흰색일 경우  
	if(type==0){
	//말의 구조체의 위치를 이동시켜주기  
	auto it= find(v[y][x].begin(),v[y][x].end(), num);
	vector<int> temp2(it, v[y][x].end());
	v[y][x].erase(it, v[y][x].end());
	move_horse(y,x,ny,nx,temp2);
	//말의 순서가 들어간 벡터를 업데이트해주기
	for(int i: temp2){
		v[ny][nx].push_back(i);
	} 
	}
	// 빨간색일 경우  
	else if(type==1){
	auto it= find(v[y][x].begin(),v[y][x].end(), num);
	vector<int> temp2(it, v[y][x].end());
	v[y][x].erase(it, v[y][x].end());
	reverse(temp2.begin(),temp2.end());
	move_horse(y,x,ny,nx,temp2);
	for(int i: temp2){
		v[ny][nx].push_back(i);
	 }
	}
	//파란색일 경우  
	else{
		dir = redirect(dir);
		ny= y+dy[dir];
		nx= x+dx[dir];
		horse[num].dd= dir;	
	 if(a[ny][nx]==2||ny<0||nx<0||ny>=n||nx>=n){
		ny=y;
		nx=x;
	}
	else if(a[ny][nx]==0){
	auto it= find(v[y][x].begin(),v[y][x].end(), num);
	vector<int> temp2(it, v[y][x].end());
	v[y][x].erase(it, v[y][x].end());
	move_horse(y,x,ny,nx,temp2);
	//말의 순서가 들어간 벡터를 업데이트해주기
	for(int i: temp2){
		v[ny][nx].push_back(i);
	} 
	}
	else if(a[ny][nx]==1){
	auto it= find(v[y][x].begin(),v[y][x].end(), num);
	vector<int> temp2(it, v[y][x].end());
	v[y][x].erase(it, v[y][x].end());
	reverse(temp2.begin(),temp2.end());
	move_horse(y,x,ny,nx,temp2);
	for(int i: temp2){
		v[ny][nx].push_back(i);
	}
		}
	}
	if(v[ny][nx].size()>=4) return true;
	else
	return false;
}


int main(){
	cin>>n>>k;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=0; i<k; i++){
		int x,y,d;
		cin>>y>>x>>d;
		h temp;
		temp.dd=--d;
		temp.xx=--x;
		temp.yy=--y;
		//말의 인덱스를 넣어서 현재 들어있는 말과 순서를 나타냄 
		v[y][x].push_back(i);
		horse[i]= temp;
	}
	
	while(true){
		ret++;
		bool flag=false;
		if(ret>1000) break;
		for(int i=0; i<k; i++){
		flag= go(i);
		if(flag) break;
		}
		if(flag) break;	
	} 
	
	if(ret>1000) cout<<-1;
	else cout<<ret;
	
	return 0;
}
