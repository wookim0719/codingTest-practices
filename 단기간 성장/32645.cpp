#include<bits/stdc++.h>
using namespace std;
int dp[100001];
vector<int> child[100001];
vector<int> v[100001];
int visited[100001];
int n;

void makeTree(int num){
	visited[num]=1;
	for(int i: v[num]){
		if(!visited[i]){
			child[num].push_back(i);
			makeTree(i);	
		}
	}
	return;
}

void go(int num){
	if(child[num].size()==0) {
		dp[num]= 2;
	}
	map<int,int> mp;
	for(int i:child[num]){
		go(i);
		if(dp[i]==2){
			mp[2]=1;
		}
		if(dp[i]==1){
			mp[1]==1;
		}
		if(dp[i]==3){
			mp[3]==1;
		}
	}
	if(mp[3]==1){
		dp[num] = 1;
	}
	else if(mp[2]==1){
		dp[num] = 1;
	}
	else dp[num] = 2;
	return;
}


int main(){
	cin>>n;
	for(int i=0; i<n-1; i++){
		int t1,t2;
		cin>>t1>>t2;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
	makeTree(1);
	go(1);
	
	for(int i=1; i<=n; i++){
		if(dp[i]==1) cout<<"donggggas"<<"\n";
		else cout<<"uppercut"<<"\n";
	}
	
	return 0;
}


