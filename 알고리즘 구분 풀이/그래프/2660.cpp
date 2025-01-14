#include<bits/stdc++.h>
using namespace std;
vector<int> v[51];
int dp[51];
int n;
int ret=987654321;
int visited[51];
int res[51];
vector<int> ans;
int cnt;

void go(int num){
	memset(visited,0,sizeof(visited));
	int total=0;
	int s= num;
	queue<pair<int,int>> pq;
	pq.push({0,s});
	visited[s]=1;
	while(pq.size()){
		auto f= pq.front();
		int node = f.second;
		int cost = f.first;
		pq.pop();
		for(int i: v[node]){
			if(!visited[i]){
				visited[i]=1;
				pq.push({cost+1,i});
				total = max(total,cost+1);
			}	
		}
	}
	res[s] = total;
	ret= min(ret,total);
		
	return;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	
	while(true){
		int t1,t2;
		cin>>t1>>t2;
		if(t1==-1&&t2==-1) break;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
	
	for(int i=1; i<=n; i++){
		go(i);
	}
	
	for(int i=1;i<=n; i++){
		if(ret==res[i]){
			cnt++;
			ans.push_back(i);
		}
	}
	cout<<ret<<" "<<cnt<<"\n";
	for(int i: ans){
		cout<<i<<" ";
	}
	return 0;
}
