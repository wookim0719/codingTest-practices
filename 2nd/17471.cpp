#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n;
int a[11];
int population[11];
vector<int> near[11];
int b;
vector<int> j;
int ret= INF; 
vector<int> v1;
vector<int> v2;




int calculate(vector<int> temp3){
	int value =0;
	for(int i: temp3){
		value += population[i];
	}
	return value;
}


// 가능한 조합인지 확인해주는 함수  
bool possible(vector<int> temp){
	if(temp.size()==0) return false;
	bool flag= true;
	memset(a,0,sizeof(a));
	for(int i: temp) a[i]=1;
	queue<int> q;
	q.push(temp[0]);
	while(q.size()){
		int now = q.front();
		a[now] = 0;
		q.pop();
		for(int i:near[now]){
			if(a[i]==1){
				q.push(i);
			}
		}	
	}
	for(int i=0; i<n; i++){
		if(a[i]==1) flag = false;
	}
	return flag;
}
// 조합을 만들어주는 함수  
void search(){
	for(int i=1; i<(1<<n); i++){
		for(int j=0; j<n; j++){
			if(i & (1<<j)){
				v1.push_back(j);
			}
			else v2.push_back(j);
		}

			if(possible(v1)&&possible(v2)){
				int tt= calculate(v1)-calculate(v2);
				ret = min(ret,abs(tt));
			}
			v1.clear();
			v2.clear();
	}
	return ;
}

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>population[i];
	}
	for(int i=0; i<n; i++){
		cin>>b;
		for(int j=0; j<b; j++){
			int temp2;
			cin>>temp2;
			near[i].push_back(temp2-1);
		}
	}
	search();
	if(ret!=INF)
	cout<<ret;
	else cout<<-1;
	return 0;
}
