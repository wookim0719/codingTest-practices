#include<bits/stdc++.h>
using namespace std;
int n,m,h;
int x,y;
vector<int> ver[31];
int v[31][31];
int ret= 4; 

bool check(){
	bool flag= true;
	for(int b=1; b<=n; b++){
		int pos =b;
		for(int i=1; i<=h; i++){
		for(int j=0; j<ver[i].size(); j++){
			if(ver[i][j]==pos){
				pos= pos+1;
			}
			else if(ver[i][j]==pos-1){
				pos= pos-1;
			} 
		}
			}
			if(pos != b) flag = false;
		}
	if(flag) return true;
	else return false;
}

void add_ladder(int here, int cnt){
	if(cnt>3 || cnt>=ret) return ;
	bool flag = false;
	for(int i=here; i<=h; i++){
		for(int j=1; j<=n-1; j++){
			if(v[i][j]!=1&& v[i][j-1]!=1&& v[i][j+1]!=1){
				v[i][j]=1;
				ver[i].push_back(j);
					flag = check();
					if(flag){
					ret= min(ret,cnt);		
					} 
					else{
						add_ladder(i,cnt+1);
					}
				ver[i].pop_back();
				v[i][j]=0;
			}
		}
	}
}




int main(){
	cin>>n>>m>>h;
	
	for(int i=1; i<=m; i++){
		cin>>x>>y;
		v[x][y]=1;
		ver[x].push_back(y);
	}
	if(check()){
		cout<<0;
			return 0;
	}
	add_ladder(1,1);
	if(ret!=4)
	cout<<ret;
	else cout<<-1;	
	return 0;
}
