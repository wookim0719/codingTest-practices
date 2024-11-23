#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a;
vector<int> b;
set<int,greater<int>> st;
vector<pair<int,int>> v[101];
vector<int> ret;

void findE(){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(a[i]==b[j]){
				v[a[i]].push_back({i,j});	
				st.insert(a[i]);
			}
		}
	}
	return;
}

void goE(){
	int fidx = -1;
	int sidx = -1;
	while(true){
		bool flag=false;
		if(fidx==n-1||sidx==m-1) break;
		for(int i: st){
			for(int j=0; j<v[i].size(); j++){
				int tidx1= v[i][j].first;
				int tidx2= v[i][j].second;
				if(tidx1>fidx&&tidx2>sidx){
					ret.push_back(i);
					fidx= tidx1;
					sidx= tidx2;
					flag= true;
					break;
				}
			}
			if(flag) break;
		}
		if(!flag) break;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n; i++){
		int temp;
		cin>>temp;
		a.push_back(temp);
	}
	cin>>m;
	for(int j=0; j<m; j++){
		int temp;
		cin>>temp;
		b.push_back(temp);
	}
	findE();
	goE();
//	for(int i=0; i<10; i++){
//		for(int j=0; j<v[i].size(); j++){
//			cout<<v[i][j].first<<" "<<v[i][j].second<<"\n";
//		}
//	}
	cout<<ret.size()<<"\n";
	
	for(int i: ret){
		cout<<i<<" ";
	}	
	return 0;
}
	
