#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v;
vector<int> a;
int visited[9];

void go(int cnt){
	if(v.size()==m){
		for(int i=0; i<m; i++){
			cout<<v[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i=0; i<n; i++){
		if(!visited[i]){
			visited[i]=1;
			v.push_back(a[i]);
			go(cnt+1);
			v.pop_back();
			visited[i]=0;	
		}
	}
	return;
}


int main(){
	
	cin>>n>>m;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		a.push_back(temp);
	}
	sort(a.begin(),a.end());
	
	go(0);
	
	return 0;
}
