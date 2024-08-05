#include<bits/stdc++.h>
using namespace std;
int n,r,q;
vector<int> e[100001];
int child[100001];
int visited[100001];


int go(int c){
	if(e[c].size()){
		for(int i=0; i<e[c].size(); i++){
			if(!visited[e[c][i]]){
				visited[e[c][i]]=1;
				child[c] += go(e[c][i]);
			}
		}
	}
	return child[c];
}

int main(){
	std::ios_base::sync_with_stdio( false );
	std::cin.tie( NULL );
	std::cout.tie( NULL );
	cin>>n>>r>>q;
	fill(child,child+100001,1);
	
	for(int i=0; i<n-1; i++){
		int temp1,temp2;
		cin>>temp1>>temp2;
		e[temp1].push_back(temp2);
		e[temp2].push_back(temp1);
	}
	visited[r]=1;
	go(r);
	for(int i=0; i< q; i++){
	int temp1;
	cin>>temp1;
	cout<<child[temp1]<<"\n";	
	}
	
	return 0;
}
