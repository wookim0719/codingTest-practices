#include<bits/stdc++.h>
using namespace std;
int t;
int n,m;
vector<int> node[1002];
int visited[1002];


void check_linked(int start,int previous){
	 visited[start]++;
	 if(visited[start]>1) return;
		for(int j: node[start]){
			if(j!=previous)
			check_linked(j,start);
		}
	return;
}


int main(){
	cin>>t;
	while(t--){
	bool flag= true;
	for(int i=0; i<1002; i++){
		node[i].clear();
	}
	memset(visited,0,sizeof(visited));
	cin>>n>>m;
	for(int i=0; i<m;i++){
		int temp1,temp2;
		cin>>temp1>>temp2;
		if(find(node[temp1].begin(),node[temp1].end(),temp2)!=node[temp1].end()) flag= false;
		else{
		node[temp1].push_back(temp2);
		node[temp2].push_back(temp1);
	}
	}	
		check_linked(1,0);
		for(int i=1; i<=n; i++)	{
			//cout<<visited[i]<<" ";
			if(visited[i]!=1) flag = false;
		}
		
		if(flag) cout<<"tree"<<"\n";
		else cout<<"graph"<<"\n";
	}
	
	return 0;
}
