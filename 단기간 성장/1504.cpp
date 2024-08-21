#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<pair<int,int>> v[801];
int v1[801];
int v2[801];
int v3[801];
const int INF=987654321;
int n1,n2;

int main(){
	cin>>n>>m;
	fill(v1,v1+801,INF);
	fill(v2,v2+801,INF);
	fill(v3,v3+801,INF);
	v1[0]=0;
	for(int i=0; i<m; i++){
		int a,b,c;
		cin>>a>>b>>c;
		a--; b--;
		v[a].push_back({b,c});
		v[b].push_back({a,c});		
	}
	cin>>n1>>n2;
	n1--; n2--;
	v2[n1]=0;
	v3[n2]=0;	
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,0});
	
	while(pq.size()){
		auto f= pq.top();
		pq.pop();
		for(int i=0; i<v[f.second].size(); i++){
			if(v1[v[f.second][i].first]>f.first+v[f.second][i].second){
				v1[v[f.second][i].first]= f.first+v[f.second][i].second;
				pq.push({v1[v[f.second][i].first],v[f.second][i].first});
			}
		}
	}
	pq.push({0,n1});
	while(pq.size()){
		auto f= pq.top();
		pq.pop();
		for(int i=0; i<v[f.second].size(); i++){
			if(v2[v[f.second][i].first]>f.first+v[f.second][i].second){
				v2[v[f.second][i].first]= f.first+v[f.second][i].second;
				pq.push({v2[v[f.second][i].first],v[f.second][i].first});
			}
		}	
	}
	pq.push({0,n2});
	while(pq.size()){
		auto f= pq.top();
		pq.pop();
		for(int i=0; i<v[f.second].size(); i++){
			if(v3[v[f.second][i].first]>f.first+v[f.second][i].second){
				v3[v[f.second][i].first]= f.first+v[f.second][i].second;
				pq.push({v3[v[f.second][i].first],v[f.second][i].first});
			}
		}	
	}
//	cout<<v1[n1]<<" "<<v2[n2]<<" "<<v3[n-1]<<"\n";
	int value1= INF;
	int value2= INF;
	if(v1[n1]!=INF&&v2[n2]!=INF&&v3[n-1]!=INF)
	value1= v1[n1]+ v2[n2]+ v3[n-1];
	if(v1[n2]!=INF&&v2[n-1]!=INF&&v3[n1]!=INF)
	value2= v1[n2]+ v3[n1]+ v2[n-1];
	
	int ret= min(value1, value2);
	if(ret==INF) ret=-1;
	cout<<ret;
	
	return 0;
}
