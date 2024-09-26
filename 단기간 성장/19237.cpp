#include<bits/stdc++.h>
using namespace std;
int n,m,k;
//상어의 냄새들을 위치마다 저장 
int smell[21][21][401];
//위치의 냄새의 갯수를 저장
int smell_cnt[21][21]; 
//우선순위 정하는 배열 앞이 상어 번호, 뒤가 특정 보는 방향  
vector<int> d[401][4];
struct shark{
	int y;
	int x;
	int dir;
	int life;
};
//우선순위 정하는 map  
map<int,int> prior;
//상어의 상태를 저장  
shark sh[401]; 
//각 상어의 위치를 한 번에 저장 진짜 인덱스로 저장  
int pos[21][21]; 
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

void show(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<pos[i][j]<<" ";
		}
		cout<<"\n";
	}
	return;
}

int count(){
	int cnt=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cnt+=pos[i][j];
			if(cnt>1) break;
		}
		if(cnt>1) break;
	}
	
	return cnt;
}
void spread_smell(){
	for(int i=1; i<=m; i++){
		if(sh[i].life){
			int yy= sh[i].y;
			int xx= sh[i].x;
			if(!smell[yy][xx][i])
			smell_cnt[yy][xx]++;
			smell[yy][xx][i]=k;	
		}
	}
	return;
}

int find_dir(int k){
	int now_d= sh[k].dir;
//	cout<<k<<"번 상어"<<" "<<"방향"<<" "<<now_d+1<<"\n"; 
	for(int i=0; i<4; i++){
		prior[d[k][now_d][i]] = i+1;	
	}
	int yy= sh[k].y;
	int xx= sh[k].x;
	int temp_prior = 100;
	int cnt1=0;
	int next_d=-1;
	//주변에 없는 경우에 우선순위 고려해서 작성  
	for(int i=0; i<4; i++){
		int ny= yy+dy[i];
		int nx= xx+dx[i];
		if(ny<0||nx<0||ny>=n||nx>=n||smell_cnt[ny][nx]) continue;
		else{
			cnt1++;
			if(prior[i]<temp_prior){
				temp_prior=prior[i]; 
				next_d = i;
			}		
		}
	}
	// 주변에 없는 경우가 없는 경우
	int cnt2=0;
	int temp_prior2 = 100;
	if(cnt1==0){
		for(int i=0; i<4; i++){
			int ny= yy+dy[i];
			int nx= xx+dx[i];
		if(ny<0||nx<0||ny>=n||nx>=n||!smell[ny][nx][k]) continue;
		else{
			cnt2++;
			if(prior[i]<temp_prior2){
				//if(k==2) cout<<"바뀐 방향"<<" "<<next_d+1<<" "<<i+1<<" "<<prior[i]<<" "<<temp_prior<<"\n"; 		
				temp_prior2=prior[i];
				next_d = i;
			}
		}	
		}	
	}
	return next_d;
}

void kill(){
	vector<int> t[21][21];
	
	for(int i=1; i<=m; i++){
		int yy= sh[i].y;
		int xx= sh[i].x;
		if(sh[i].life){
		///	cout<<i<<" "<<yy<<" "<<xx;
			t[yy][xx].push_back(i);
		}
	}
//	cout<<"t 배열 출력"<<"\n";
//	for(int i=0; i<n; i++){
//		for(int j=0; j<n; j++){
//			cout<<t[i][j].size()<<" ";
//		}
//		cout<<"\n";
//	}
//	cout<<"\n";
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			sort(t[i][j].begin(),t[i][j].end());
			for(int k=0; k<t[i][j].size(); k++){
				if(k==0) continue;
				else{
					int num= t[i][j][k];
					sh[num].life=0;
					pos[i][j]--;
				}
			}
		}
	}
	
	return; 
}

void move_shark(){
	for(int c=1; c<=m; c++){
		if(sh[c].life){
			int dir=find_dir(c);
			//cout<<c<<" "<<dir<<"\n";
			int y=sh[c].y;
			int x=sh[c].x;
			int ny=y+dy[dir];
			int nx=x+dx[dir]; 
			//상어 이동시켜주기  
			sh[c].y=ny;
			sh[c].x=nx;	
			sh[c].dir=dir;
			pos[y][x]--;
			pos[ny][nx]++;
		}
	}
	return;
}
void smell_reduce(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			for(int k=1; k<=m; k++){
				if(smell[i][j][k]>0){
					smell[i][j][k]--;
					if(smell[i][j][k]==0)
					smell_cnt[i][j]--;
				}	
			}
		}
	}
	return;
}

int main(){
	cin>>n>>m>>k;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int temp;
			cin>>temp;	
			if(temp){
				pos[i][j]++;
				int name=temp;
				shark sht;
				sht.y=i;
				sht.x=j;
				sht.life=1;
				sh[name] = sht;
			}
		}
	}
	
	for(int i=1; i<=m; i++){
		int temp2;
		cin>>temp2;
		sh[i].dir=temp2-1;
	}
	
	//방향에 맞는 우선순위 넣어주기
	for(int i=1; i<=m; i++){
		for(int j=0; j<4; j++){
			for(int k=0; k<4; k++){
				int temp;
				cin>>temp;
				d[i][j].push_back(temp-1);
			}
		}
	}
	int sec=0;
//	show();
//	cout<<"\n";
//	for(int i=1; i<=m; i++) cout<<i<<" "<<sh[i].dir<<"\n";
//	cout<<"\n";

	while(true){
		if(sec>1000) break;
		int cnt= count();
		if(cnt==1) break;
		//냄새 뿌리기
		spread_smell(); 
	//	cout<<"냄새 출력"<<"\n";
//		for(int i=0; i<n; i++){
//			for(int j=0; j<n; j++){
//				cout<<smell_cnt[i][j]<<" ";
//			}
//			cout<<"\n";
//		} 
	//	cout<<"\n";
		//상어를 이동
	//	cout<<sec<<"이동후"<<"\n"; 
		move_shark();
		//이동 후 상어 제거
	//	show();
		kill();
		smell_reduce();
	//	cout<<"\n"; 
		sec++;
	}
	
	if(sec>1000) cout<<-1;
	else cout<<sec; 
	return 0;
}
