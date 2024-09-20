#include<bits/stdc++.h>
using namespace std;
typedef pair<pair<int,int>,int> t1;
int n;
int y,x,dir,total;
int ret;
int a[500][500];
vector<t1> lleft;
vector<t1> uup;
vector<t1> ddown;
vector<t1> rright;
t1 d[10]={{{1,0},1},{{-1,0},1},{{-2,-1},2},{{2,-1},2},
{{-1,-1},7},{{1,-1},7},{{-1,-2},10},{{1,-2},10},{{0,-3},5},{{0,-2},55}};
t1 d2[10]={{{0,-1},1},{{0,1},1},{{1,2},2},{{1,-2},2},
{{1,1},7},{{1,-1},7},{{2,1},10},{{2,-1},10},{{3,0},5},{{2,0},55}};
int dy[4]={0,1,0,-1};
int dx[4]= {-1,0,1,0};
vector<vector<t1>> plus2;

void move(){
	int ty= y+dy[dir];
	int tx= x+dx[dir];
	int sand= a[ty][tx];
	int left=sand;
	for(auto i: plus2[dir]){
		int dy= y+i.first.first;
		int dx= x+i.first.second;
		int value=0;
		if(i.second!=55){
		value= (sand*i.second)/100;
		left-=value;	
		}
		else{
			value=left;
		//	cout<<value<<"\n";
		}
		if(dy<0||dx<0||dy>=n||dx>=n) continue;
		else{
			a[dy][dx]+=value;
		}
	}
	a[ty][tx]=0;
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
			total+=a[i][j];
		}
	}
	for(int i=0; i<10; i++){
		lleft.push_back(d[i]);
	}
	for(int i=0; i<10; i++){
		ddown.push_back(d2[i]);
	}
	for(int i=0; i<10; i++){
		rright.push_back({{d[i].first.first,d[i].first.second*-1},d[i].second});
	}
	for(int i=0; i<10; i++){
		uup.push_back({{d2[i].first.first*-1,d2[i].first.second},d2[i].second});
	}
	plus2.push_back(lleft);
	plus2.push_back(ddown);
	plus2.push_back(rright);
	plus2.push_back(uup);

	y=(n)/2;
	x=(n)/2;
	
	int dv=1;
	int dcnt=0;
	while(true){
	//cout<<y<<" "<<x<<"\n";
	if(dv==n-1&&dcnt==3)break;
	int cnt=0;
	//cnt가 dv만큼 갔을 때 이동을 종료하고 방향을 전환 
	while(true){
		if(cnt==dv) break;
		move();
		y+=dy[dir];
		x+=dx[dir];
		cnt++;
//		for(int i=0; i<n; i++){
//			for(int j=0; j<n; j++){
//				cout<<a[i][j]<<" ";
//			}
//			cout<<"\n";
//		}
//		cout<<"\n";
	}
	dir = (dir+1)%4;
	//n-1이 아닌 경우 2번을 채우게 되면 태웊의 크기를 1증가 
	//n인 경우에는 계속 증가하여 위에서 3인 경우에 while문 종료  
	if(dv==n-1){
		dcnt++;
	}	
	else{
		if(dcnt+1==2){
			dv++;
			dcnt=0;
		}
		else dcnt++;
	}			
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			ret+=a[i][j];
		}
	}
	cout<<total-ret;
	
	return 0;
}
