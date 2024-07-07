#include<bits/stdc++.h>
using namespace std;
int n;
map<int,int> mp;
int answer[101];
int visited[101];
int cnt;

void go(int num, int goal){
	visited[num]=1;
	int temp= mp[num];
	if(temp==goal){
		for(int i=1; i<=n; i++){
			if(visited[i]){
			answer[i]=1;
			cnt++;
			}
		}
	visited[num]=0;
	return;
	}
	else if(answer[temp]!=1&&visited[temp]==0){
		go(temp,goal);
	}
	visited[num]=0;
	return;
}

int main(){
	cin>>n;
	
	for(int i=1; i<=n; i++){
		int temp;
		cin>>temp;
		if(i==temp) {
		answer[i]=1;
		mp[i]=i;	
		cnt++;
		}
		else
		mp[i] = temp;
	}
	for(int i=1; i<=n;i++){
	if(answer[i]!=1){
	 visited[i]=1;
		go(mp[i],i);
	visited[i]=0;
	}
	}
	
	
	cout<<cnt<<"\n";
	for(int i=1; i<=n; i++){
	if(answer[i]==1)cout<<i<<"\n";
	}
	
	return 0;
}
