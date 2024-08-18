#include<bits/stdc++.h>
using namespace std;
// 격자의 수, 파이어볼의 수, 명령의 수 
int n,m,k;
int a[51][51]; 
int dy[8]={-1,-1,0,1,1,1,0,-1};
int dx[8]={0,1,1,1,0,-1,-1,-1};
//질량은 m, 방향은 d, 속력은 s
struct fire{
	int m,d,s;
};
vector<fire> v[51][51];
vector<fire> v2[51][51];
int ret;

 void move(int y, int x){
 	for(int i=0; i<v[y][x].size(); i++){
 		fire temp= v[y][x][i];
 		int ny= (y+dy[temp.d]*temp.s);
 		int nx= (x+dx[temp.d]*temp.s);
 		if(ny<0){
 			while(true){
 				ny+=n;
 				if(ny>=0) break;
			 }
		 }
		 if(nx<0){
 			while(true){
 				nx+=n;
 				if(nx>=0) break;
			 }
		 }
		 if(ny>=n)ny %=n;
		 if(nx>=n)nx%=n;
	//	cout<<ny<<" "<<nx<<"\n";
 		v2[ny][nx].push_back(temp);
	 }
//	 cout<<"\n";
	 return;
 }
 
 void divide(int y, int x){
 	// 방향 설정 
 //	cout<<"divide"<<y<<" "<<x<<"\n";
 	int cnt_e=0; int cnt_o=0;
 	int init_speed=0;
 	int sum=0;  
 	int speed=0; 
 	int cnt= v2[y][x].size();
 	for(int i=0 ;i<v2[y][x].size(); i++){
 		fire temp= v2[y][x][i];
		if(temp.d%2) cnt_e++; else cnt_o++;	
		sum+=temp.m;
		speed+=temp.s; 
	 }
//	 cout<<cnt_e<<" "<<cnt_o<<"\n";
	 if(cnt_e==0||cnt_o==0){
	 	init_speed=0;
	 }
	 else{
	 	init_speed=1;
	 }
	// cout<<init_speed<<"\n";
	 v2[y][x].clear();
	 sum /=5;
	 speed /= cnt;
	// cout<<"ss"<<sum<<" "<<speed<<"\n";
	 if(sum==0) return;
	 else{
	 	for(int i=0; i<4; i++){
	 		fire temp2;
	 		temp2.m=sum; temp2.s=speed; temp2.d=init_speed+(i*2);
	 		v2[y][x].push_back(temp2);
		 }
	 }
 	return;
 }
 
int main(){
	cin>>n>>m>>k;
	for(int i=0; i<m; i++){
		int t1,t2,t3,t4,t5;
		cin>>t1>>t2>>t3>>t4>>t5;
		fire temp;
		t1--; t2--;
		temp.m= t3; temp.d=t5; temp.s=t4;
		v[t1][t2].push_back(temp);
	}
	
	while(true){
		if(k==0) break;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++)
			v2[i][j].clear();
		}	
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(v[i][j].size()){
					move(i,j);
				}
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(v2[i][j].size()>1){
					divide(i,j);
				}
			}
		}
		swap(v,v2);
		k--;
	}
	
	for(int i=0 ;i<n; i++){
		for(int j=0; j<n; j++){
			for(auto k: v[i][j]){
				ret+= k.m;
			}
		}
	}
	
	cout<<ret;
	return 0;
}
