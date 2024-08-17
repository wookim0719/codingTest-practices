#include<bits/stdc++.h>
using namespace std;
int n;
int ret;
vector<pair<int,int>> v[100];

void go(int c, int temp){
//	cout<<c<<temp<<"\n";
	if(c>n) {
		ret= max(ret,temp);
		return;
	}
	for(int i=0; i<v[c].size(); i++){
	if(c+v[c][i].first<=n+1)
		go(c+v[c][i].first,temp+v[c][i].second);
	}
	go(c+1,temp);
	return;
}


int main(){
	
	cin>>n;
	for(int i=1; i<=n; i++){
		int a,b;
		cin>>a>>b;
		v[i].push_back({a,b});
	}
	
	go(1,0);
	cout<<ret;
	return 0;
}
