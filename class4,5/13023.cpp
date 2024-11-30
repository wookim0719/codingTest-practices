#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v[2001];
int visited[2001];
int ret =0;

void check(int num,int cnt){
	if(cnt==5){
		ret=1;
		return;
		}
	for(int i: v[num]){
		if(!visited[i]){
			visited[i]=1;
			check(i,cnt+1);
			visited[i]=0;
		}
	}
	return;
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int t1,t2;
		cin>>t1>>t2;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}	
	for(int i=0; i<n; i++){
		if(ret) continue;
		visited[i]=1;
		check(i,1);
		visited[i]=0;	
	}
	cout<<ret;

	return 0;
}
