#include<bits/stdc++.h>
using namespace std;
int n,m;
int degree[1001];
vector<int> child[1001];
vector<int> temp;
int visited[1001];
bool flag= true;
vector<int> ret;
void go(){
	queue<int> q;
	for(int i=1; i<=n; i++){
		if(degree[i]==0){
			visited[i]=1;
			q.push(i);
		}
	}
	while(q.size()){
		int f = q.front();
		ret.push_back(f);
		q.pop();
		for(int i: child[f]){
			degree[i]--;
			if(degree[i]==0){
				visited[i]=1;
				q.push(i);
			}
		}
	}
	if(ret.size()!=n){
		flag= false;
	}
	return;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int num;
		cin>>num;
		temp.clear();
		for(int j=0 ;j<num; j++){
			int t;
			cin>>t;
			temp.push_back(t);
		}
		for(int h=0; h<num-1; h++){
			int p= temp[h];
			int c= temp[h+1];
			child[p].push_back(c);
			degree[c]++;
		}
	}
	go();
	if(!flag){
		cout<<0<<"\n";
	}
	else{
		for(int i: ret){
			cout<<i<<"\n";
		}
	}
	
	return 0;
}
