#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100001];
int visited[100001];
int answer[100001];
int start;
int cnt;

void dfs(int num){
	visited[num]=1;
	int target= a[num];
	
	if(!visited[target]){
		dfs(target);
	}
	else if(!answer[target]){
		for(int i =target; i!=num; i=a[i]){
			answer[i]=1;
			cnt++;
		}
		cnt++;
	}
	answer[num]=1;
	return;
}
int main(){
	cin>>t;
	while(t--){
		cnt=0;
		int ret=0;
		memset(visited,0,sizeof(visited));
		memset(a,0,sizeof(a));
		memset(answer,0,sizeof(answer));
		cin>>n;
		for(int i=1; i<=n; i++){
			cin>>a[i];
		}
		for(int i=1; i<=n; i++){
			if(!visited[i]){
				dfs(i);
			}
		}
		cout<<n-cnt<<"\n";	
	}
	
	return 0;
}
