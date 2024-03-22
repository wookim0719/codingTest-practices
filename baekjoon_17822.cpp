#include <bits/stdc++.h>
using namespace std;
int n,m,t,ret;
int a[51][51];
int visited[51][51];
struct b{
	int xi,di,ki;
};
vector<b> c;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

void rotate(int xi, int di, int ki){
	for(int i=0; i<n; i++){
		// xi의 배수인 경우에만 회전을 시킨다.  
		if((i+1)%xi!=0) continue;
		if(di==1)
		rotate(a[i], a[i]+ki,a[i]+m);
		else
		rotate(a[i], a[i]+m-ki,a[i]+m);
	}
	return;
	//잘 돌아갔는지 확인하는 구문 
//	for(int i=0; i<n; i++){
//		for(int j=0; j<m; j++){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
//	
}

void check(){
	int cnt=0;
	//여기서 visited를 초기화해주어야함
		 memset(visited, 0, sizeof(visited));  
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			for(int h=0; h<4; h++){
				int ny = i+ dy[h];
				int nx = j+ dx[h];
				if(ny<0||ny>=n) continue;
				if(nx<0) nx = m-1;
				if(nx>=m) nx  =0;
				if(a[ny][nx]== a[i][j] &&a[ny][nx] !=0) {
				visited[ny][nx]=1;
				visited[i][j]=1;	
				}
			}
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(visited[i][j]!=0){
				a[i][j]=0;
				cnt++;
			}
		}
	}
	if(cnt==0){
		int sum=0;
		int cnt2=0;
		for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(a[i][j]!=0){
				sum += a[i][j];
				cnt2++;	
			}
		}
	}
	double value = (float)sum/(float)cnt2;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(a[i][j]!=0){
				if(a[i][j]>value) a[i][j] -=1;
				else if (a[i][j]<value)a[i][j]++;
			}
		}
	}
	
	}
//	cout<<cnt<<"\n";
//	for(int i=0; i<n; i++){
//		for(int j=0; j<m; j++){
//			cout<<visited[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
//		for(int i=0; i<n; i++){
//		for(int j=0; j<m; j++){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
//			cout<<"\n";

	return ; 
}

int main(){
	cin>>n>>m>>t;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=0; i<t; i++){
		b temp;
		cin>>temp.xi>>temp.di>>temp.ki;
		c.push_back(temp);
	}
	
	for(auto i: c){
		rotate(i.xi,i.di,i.ki);
		check(); 
	}
		
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			ret += a[i][j];
		}
	}		
		
		cout<<ret;
	
	return 0;
}
