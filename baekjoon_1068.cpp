#include <bits/stdc++.h>
using namespace std;
int n;
int root;
vector<int> adj[54];
int r;

int dfs(int k){
	int cnt = 0;
	int child = 0;
	for(auto i : adj[k]){
		if(i == r) continue;
		cnt += dfs(i);
		child ++;	
	}
	
	if(child == 0 )return 1;
	return cnt;
	
}

 int main(){
 	cin>> n;
 	
 	for(int i=0; i<n; i++){
 		int temp;
 		cin>> temp;
 		if(temp == -1)
 			root = i;
 		else
 		adj[temp].push_back(i);
	 }
	 
	 cin>> r;
	 if(r == root){
	 	cout<< 0;
	 }
	 else{
		int j = dfs(root);
		cout<< j;
	 }
	 return 0;
 }
