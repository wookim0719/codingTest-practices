#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;
int n,m,r;
int a[101];
const int INF = 10000;
vector<pair<int,int>> v[101];
int disjk[101];
int visited[101];
int ret;

void go(int num){
	int sum = 0;
	memset(visited,0,sizeof(visited));
	memset(disjk,INF,sizeof(disjk));
	disjk[num]=0;
	//visited[num]=1;
	priority_queue<pp,vector<pp>, greater<pp>> pq;
	pq.push({0,num});
	while(pq.size()){
		auto f = pq.top();
		int now = f.second;
		int cost = f.first;
		pq.pop();
		for(auto next: v[now]){
			int nextCost = next.second+cost;
			if(!visited[next.first]&&nextCost<disjk[next.first]){
			//	visited[next.first]=1;
				disjk[next.first] = nextCost;
				pq.push({nextCost,next.first});
			}
		}
	}
	//cout<<num<<"\n";
	for(int i=0; i<n; i++){
	//	cout<<disjk[i]<<" ";
		if(disjk[i]<=m){
			sum+=a[i];
		}
	}
	//cout<<sum<<"\n";	
	ret= max(ret,sum);
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>r;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	
	for(int i=0; i<r; i++){
		int t1,t2,t3;
		cin>>t1>>t2>>t3;
		t1--; t2--;
		v[t1].push_back({t2,t3});
		v[t2].push_back({t1,t3});
	}
	
	for(int i=0; i<n; i++){
		go(i);
	//	cout<<"\n";
	}	
	
	cout<<ret;
	return 0;
}
