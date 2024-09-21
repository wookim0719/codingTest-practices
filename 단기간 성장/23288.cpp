#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int y,x; 
int a[21][21];
// Ž���� �̿��� �湮 �迭
int visited[21][21];
vector<int> temp;
// �������� ������ �Ͽ� 90�� ȸ�� �����ϰ� ����  
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
	//�ʱ� ��ġ�� 0,0���� �����Ѵ�  
	y=0; x=0;
	//�� �� �̵��� �ߴ��� �����ϴ� ����  
	int cnt=0;
	//ó�� �̵� ������ �������� ���� 
	int dir=0;
	//�ֻ����� ���� ���� �ִ� ���� 
	int upper_num= 1;
	//�ֻ����� ���� �Ʒ��� �ִ� ����  
	int lower_num= 6;
	while(true){
		if(cnt==k) break;
		int ny= y+dy[dir];
		int nx= x+dx[dir];
		//�̵��� �Ұ����� ��� ������ �ݴ�� �����ϰ� �̵��Ѵ�. 
		if(ny<0||nx<0||ny>=n||nx>=m){
			dir= (dir+2)%4;
		}
		y= y+dy[dir];
		x= x+dx[dir];
		//�̵��ϸ鼭 �ٲ� �ֻ����� ���� ���ڸ� ��������ش�.
		rotate(dir); 
		//��,��, ��, ��, ��, �� ����   
		upper_num= dice[0]; 
		lower_num= 7-upper_num;
		int score = go(y,x); 
	//	cout<<y+1<<" "<<x+1<<" "<<lower_num<<"\n";
		ret+=a[y][x]*score;	
		//���� �̵��� ���� ����
		//���� ���� �״�� �̹Ƿ� ���д�. 	
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
		//k���ϱ� ���ؼ� cnt�� ������Ų��. 
		cnt++;	
	}
	
	cout<<ret;
	return 0;
}
