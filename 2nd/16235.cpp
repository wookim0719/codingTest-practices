#include<bits/stdc++.h>
using namespace std;
int n,m,k;
// 양분의 상태를 저장하는 배열  
int a[11][11];
int p[11][11];
int dy[8]= {-1,-1,-1,0,0,1,1,1};
int dx[8]= {-1,0,1,-1,1,-1,0,1};
struct tree{
	int age;
	bool isalive;
};
int ret;
// 나무의 상태를 저장하는 배열  
vector<tree> v[11][11];

bool operator<(const tree& a, tree& b){
	return a.age < b.age;
}

void spring(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(v[i][j].size()){
				sort(v[i][j].begin(), v[i][j].end());
				for(tree& t: v[i][j]){
					if(a[i][j]>=t.age&&t.isalive){
						a[i][j] -= t.age;
						t.age +=1;
					}
					else{
						t.isalive = false;
					}
				}
			}
		}
	}	
	return;
}

void summer(){
	vector<int> list;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(v[i][j].size()){
				list.clear();
				for(int h=0;h<v[i][j].size(); h++){
					if(v[i][j][h].isalive==0){
						a[i][j]+= (v[i][j][h].age/2);
						v[i][j].erase(v[i][j].begin()+h);
						h--;
					}
				}
//				 v[i][j].erase(
//                    remove_if(v[i][j].begin(), v[i][j].end(), [](const tree& t) {
//                        return !t.isalive;
//                    }),
//                    v[i][j].end()
//                );
			}
		}
	}	
	return;
}

void fall(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(v[i][j].size()){
				for(tree& t: v[i][j]){
					if(t.age%5==0){
						for(int l=0; l<8; l++){
						int ny=i+dy[l];
						int nx=j+dx[l];
						if(nx<0||ny<0||nx>=n||ny>=n)
						continue;
						tree temp;
						temp.age=1; temp.isalive= true;
						v[ny][nx].push_back(temp);	
					}		
				}
			}
		}
	}
}
	return;
}

void winter(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			a[i][j]+=p[i][j];
		}
	}
	return;
}

int main(){
	cin>>n>>m>>k;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>p[i][j];
			a[i][j]=5;
		}
	}
	
	
	for(int i=0; i<m; i++){
		int y,x, age;
		cin>>y>>x>>age;
		y--; x--;
		tree temp;
		temp.age= age;
		temp.isalive= true;
		v[y][x].push_back(temp);
	}
	
	while(k--){
		spring();
		summer();
		fall();
		winter();
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n;j++){
			ret+= v[i][j].size();
		}
	}
	
	cout<<ret;
	
	return 0;
}
