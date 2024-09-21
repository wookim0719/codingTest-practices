#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int y,x; 
int a[21][21];
// 탐색시 이용할 방문 배열
int visited[21][21];
vector<int> temp;
// 동남서북 순으로 하여 90도 회전 가능하게 설정  
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
vector<vector<int>> rot={{5,4,2,3,0,1},{3,2,0,1,4,5},{4,5,2,3,1,0},{2,3,1,0,4,5}};  
vector<int> dice={1,6,5,2,3,4};
int ret;

void rotate(int dir){
	temp.clear();
	for(int i=0; i<dice.size(); i++){
		temp.push_back(dice[i]);
	}
	for(int i=0; i<6; i++){
		dice[i]= temp[rot[dir][i]];
//		cout<<dice[i]<<" ";
	}
//	cout<<"\n";
	return;
}

int go(int yy, int xx){
	memset(visited,0,sizeof(visited));
	int value= a[yy][xx];
	int sum=1;
	queue<pair<int,int>> q;
	q.push({yy,xx});
	visited[yy][xx]=1;
	while(q.size()){
		auto now= q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int ny= now.first+dy[i];
			int nx= now.second+dx[i];
			if(ny<0||nx<0||ny>=n||nx>=m||visited[ny][nx]||a[ny][nx]!=value) continue;
			visited[ny][nx]=1;
			q.push({ny,nx});
			sum++;
		}
	} 
	return sum;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>k;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];
		}
	}
	//초기 위치를 0,0으로 설정한다  
	y=0; x=0;
	//몇 번 이동을 했는지 저장하는 변수  
	int cnt=0;
	//처음 이동 방향을 동쪽으로 설정 
	int dir=0;
	//주사위의 현재 위에 있는 숫자 
	int upper_num= 1;
	//주사위의 현재 아래에 있는 숫자  
	int lower_num= 6;
	while(true){
		if(cnt==k) break;
		int ny= y+dy[dir];
		int nx= x+dx[dir];
		//이동이 불가능한 경우 방향을 반대로 설정하고 이동한다. 
		if(ny<0||nx<0||ny>=n||nx>=m){
			dir= (dir+2)%4;
		}
		y= y+dy[dir];
		x= x+dx[dir];
		//이동하면서 바뀐 주사위의 위의 숫자를 변경시켜준다.
		rotate(dir); 
		//위,밑, 앞, 뒤, 오, 왼 순서   
		upper_num= dice[0]; 
		lower_num= 7-upper_num;
		int score = go(y,x); 
	//	cout<<y+1<<" "<<x+1<<" "<<lower_num<<"\n";
		ret+=a[y][x]*score;	
		//다음 이동할 방향 설정
		//같은 경우는 그대로 이므로 나둔다. 	
		if(a[y][x]<lower_num){
			dir = (dir+1)%4;
		} 
		else if(a[y][x]>lower_num){
			dir = dir-1;
			if(dir<0){
				dir+=4;
			} 
		}
	//	cout<<dir<<"\n";
		//k번하기 위해서 cnt를 증가시킨다. 
		cnt++;	
	}
	
	cout<<ret;
	return 0;
}
