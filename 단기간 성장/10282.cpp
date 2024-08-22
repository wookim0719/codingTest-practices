#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;
int t;	
int n,d,c;
vector<pair<int,int>> a[10001];
int visited[10001];
int cnt;

//int dfs(int z){
//	cnt++;
//	int ret=0;
//	for(int i=0; i<a[z].size(); i++){
//	if(!visited[a[z][i].second]){
//		visited[a[z][i].second]=1;
//		ret += (a[z][i].first+dfs(a[z][i].second));
//	}
//	}
//	return ret;
//}

int main(){
	cin>>t;
	while(t--){
		cnt=0;
		int ret=0;
		cin>>n>>d>>c;
		c--;
		for(int i=0; i<10001; i++){
			a[i].clear();
		}
		memset(visited,0,sizeof(visited));
		for(int i=0; i<d; i++){
			int t1,t2,t3;
			cin>>t1>>t2>>t3;
			t1--; t2--;
			a[t2].push_back({t1,t3});	
		}
		priority_queue<p,vector<p>,greater<p>> pq;
		pq.push({0,c});
		while(pq.size()){
			p f= pq.top();
			pq.pop();
			if(!visited[f.second]){
			visited[f.second]=1;
			ret= max(ret,f.first);
			//cout<<f.second<<" "<<f.first<<"\n";
			cnt++;
			pq.top();
			for(auto next: a[f.second]){
			//	cout<<next.first<<" "<<next.second<<"\n";
				if(!visited[next.first]){
			//		cout<<next.first<<" "<<next.second<<" "<<ret<<"\n";
					pq.push({f.first+next.second,next.first});
				}
			}	
			}
		}
		cout<<cnt<<" "<<ret<<"\n";
	}
	
	return 0;
}
