#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v;
int visited[9];

void go(){
	if(v.size()==m){
		for(int i:v){
			cout<<i<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i=0; i<n; i++){
		if(!visited[i]){
			visited[i]=1;
			v.push_back(i+1);
			go();
			v.pop_back();
			visited[i]=0;
		}	
	}
	return;
}


int main(){
cin>>n>>m;
	
	go();	
	
	return 0;
}
