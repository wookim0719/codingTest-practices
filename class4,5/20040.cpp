#include<bits/stdc++.h>
using namespace std;
int parent[1000001];
int n,m;
bool flag= false;

int find(int node){
	if(parent[node]==node) return node;
	else
	return parent[node] = find(parent[node]);
}

void merge(int node1,int node2){	
	int pnode1= find(node1);
	int pnode2= find(node2);
	if(pnode1<pnode2){
		parent[pnode2] = pnode1;
	}
	else if(pnode1>pnode2){
		parent[pnode1] = pnode2;
	}
	return;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=0; i<n; i++){
		parent[i] = i;
	}
	
	for(int i=0; i<m; i++){
		int t1,t2;
		cin>>t1>>t2;
		if(find(t1)!=find(t2)){
			merge(t1,t2);
		}
		else{
			flag= true;
			cout<<i+1;
			break;
		}

	}
	if(flag==false) cout<<0;
	
	return 0;
}
