#include<bits/stdc++.h>
using namespace std;
int n,m;
int visited[9];

void go(int num,int cnt){
	if(cnt==m){
		for(int i=0; i<=n; i++){
			if(visited[i]) cout<<i<<" ";
		}
		cout<<"\n";
		return;	
	}
	for(int i=num+1; i<=n; i++){
		if(!visited[i]){
			visited[i]=1;
			go(i,cnt+1);
			visited[i]=0;
		}		
	}
	return;
}


int main(){
	cin>>n>>m;
	
	go(0,0);
	
	return 0;
}
