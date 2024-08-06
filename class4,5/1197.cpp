#include<bits/stdc++.h>
using namespace std;
int v,e;
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
int parent[10001];
int ret;
int cnt;

int check(int v1){
	if(parent[v1]==v1){
		return v1;
	}
	
	return parent[v1]=check(parent[v1]);
}

void join(int v1,int v2){
	v1= check(v1);
	v2= check(v2);
	parent[v2]=v1;
	return;
}


int main(){
	    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>v>>e;
	
	for(int i=1; i<=v;i++){
		parent[i]=i;
	}
	for(int i=0; i<e; i++){
		int a,b,c;
		cin>>a>>b>>c;
		pq.push({c,{a,b}});
	}
	
	while(pq.size()){
	auto ffirst= pq.top();
	pq.pop();
	int b= ffirst.second.second;
	int a= ffirst.second.first;	
	if(check(a)!= check(b)){
	join(a,b);
	cnt++;
	ret+=ffirst.first;
	if(cnt==v-1)break;	
	}
	}
	cout<<ret;
	
	return 0;
}
