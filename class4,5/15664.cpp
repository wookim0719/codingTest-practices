#include<bits/stdc++.h>
using namespace std;
int n,m;
set<int> k;
vector<int> v;
map<int,int> mp;
vector<int> a;

void dfs(int cnt, int index){
	if(cnt==m){
		for(int i=0; i<m; i++){
			cout<<a[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i=index ;i<v.size(); i++){
		if(mp[v[i]]>0){
			mp[v[i]]--;
			a.push_back(v[i]);
			dfs(cnt+1,i);
			a.pop_back();
			mp[v[i]]++;
		}
	}
	
	return;
}

int main(){
	cin>>n>>m;
	
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		k.insert(temp);
		mp[temp]++;
	}
	for(int t:k){
		v.push_back(t);
	}
	
	dfs(0,0);
	
	
	return 0;
}
