#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v;

void dfs(int num)
{	
	if(v.size()==m){
		
		for(int i:v){
			cout<<i<<" ";
		}
		cout<<"\n";
		return;
	}

	for(int i=num; i<=n; i++){
		v.push_back(i);
		dfs(i);
		v.pop_back();
	}

	return;
}


int main(){
	cin>>n>>m;
	
	dfs(1);
	
	return 0;
}
