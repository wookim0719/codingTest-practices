#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int temp[11][11];
int n;
int t,y,x;
int score;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int ret;

void show(){
		for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
}

void remove_green(int nn){
	for(int i=nn; i>=4; i--){
		for(int j=0; j<4; j++){
			a[i][j] = a[i-1][j];
		}
	}
	score++;
	return;
}
void remove_blue(int nn){
	for(int i=nn; i>=4; i--){
		for(int j=0; j<4; j++){
			a[j][i]= a[j][i-1];
		}
	}
	score++;
	return;
}


void check_green(){
	for(int i=6; i<10; i++){
		int flag =true;
		for(int j=0; j<4; j++){
			if(a[i][j]!=1){
				flag=false;
				break;
			}
		}
		if(flag) {
			remove_green(i);
		}
	}
}

void check_blue(){
	for(int i=6; i<10; i++){
		int flag =true;
		for(int j=0; j<4; j++){
			if(a[j][i]!=1){
				flag=false;
				break;
			}
		}
		if(flag) {
			remove_blue(i);
		}
	}
}

int down_cnt(int yy,int xx){
	int cnt=0;
	while(true){
	//	cout<<yy<<"\n";
		int ny= yy+dy[2];
		int nx= xx+dx[2];
		if(ny<0||nx<0||ny>=10||nx>=10||a[ny][nx]) break;
		else{
			yy=ny;
			cnt++;
		//	cout<<ny<<" "<<nx<<"\n";
		}
	}
	return cnt;  
}
int left_cnt(int yy,int xx){
	int cnt=0;
	while(true){
	//	cout<<yy<<"\n";
		int ny= yy+dy[1];
		int nx= xx+dx[1];
		if(ny<0||nx<0||ny>=10||nx>=10||a[ny][nx]) break;
		else{
			xx=nx;
			cnt++;
		//	cout<<ny<<" "<<nx<<"\n";
		}
	}
	return cnt;  
}

void go_green(){
	if(t==1){
	int cnt1 =down_cnt(y,x);
		a[y][x]=0;
		a[y+cnt1][x]=1;
	}
	else if(t==2){
		int cnt1= down_cnt(y,x+1);
		int cnt2= down_cnt(y,x);
		int ccnt= min(cnt1,cnt2);
		a[y][x]=0;
		a[y][x+1]=0;
		a[y+ccnt][x]=1;
		a[y+ccnt][x+1]=1;
	}
	else{
		int cnt1= down_cnt(y+1,x);
	//	cout<<cnt1<<"\n";
	//	cout<<y<<" "<<x<<"\n";
		a[y][x]=0;
		a[y+1][x]=0;
		a[y+cnt1][x]=1;
		a[y+1+cnt1][x]=1;
	}
	
	return;
}

void go_blue(){
	if(t==1){
	int cnt1 =left_cnt(y,x);
		a[y][x]=0;
		a[y][x+cnt1]=1;
	}
	else if(t==2){
		int cnt1= left_cnt(y,x+1);
	//	int cnt2= left_cnt(y,x);
		int ccnt= cnt1;
		a[y][x]=0;
		a[y][x+1]=0;
		a[y][x+ccnt]=1;
		a[y][x+ccnt+1]=1;
	}
	else{
		int cnt1= left_cnt(y+1,x);
		int cnt2= left_cnt(y,x);
		int ccnt= min(cnt1,cnt2);
		a[y][x]=0;
		a[y+1][x]=0;
		a[y][x+ccnt]=1;
		a[y+1][x+ccnt]=1;
	}
	
	return;
}
void special_clear(){
	bool flag1=false;
	bool flag2=false;
	bool flag3=false;
	bool flag4=false;
		for(int j=0; j<4; j++){
			if(a[4][j]){
				flag1=true;
			}
			if(a[5][j]){
				flag3= true;
			}
			if(a[j][4]){
				flag2=true;
			}
			if(a[j][5]){
				flag4=true;
			}
		}
		if(flag1&&flag3){
			for(int i=9; i>=4; i--){
				for(int j=0; j<4; j++){
					a[i][j]= a[i-2][j];
				}
			}	
		}
		if(!flag1&&flag3){
			for(int i=9; i>=4; i--){
				for(int j=0; j<4; j++){
					a[i][j]= a[i-1][j];
				}
			}	
		}
		if(flag2&&flag4){
			for(int i=9; i>=4; i--){
				for(int j=0; j<4; j++){
					a[j][i]= a[j][i-2];
				}
			}
		}
		if(!flag2&&flag4){
			for(int i=9; i>=4; i--){
				for(int j=0; j<4; j++){
					a[j][i]= a[j][i-1];
				}
			}	
		}

}

 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	
	while(n--){
		cin>>t>>y>>x;
		if(t==1){
			a[y][x]=1;
		}
		else if(t==2){
			a[y][x]=1;
			a[y][x+1]=1;
		}
		else{
			a[y][x]=1;
			a[y+1][x]=1;
		}
	//	show();
	//	cout<<"\n";
		go_green();
		go_blue();
	// 행에 대하여 확인하고 삭제하기
		check_green();
		check_blue();
	// 특별한 칸에 존재시 삭제하기 
		special_clear();
	//	show();
	//	cout<<"\n";
	}
	
	for(int i=6; i<10; i++){
		for(int j=0; j<4; j++){
			if(a[i][j])ret++;
			if(a[j][i])ret++;
		}
	}

	cout<<score<<"\n";
	cout<<ret;
	
	return 0;
}
