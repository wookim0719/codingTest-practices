#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> v[10001];
vector<int> res;
int dp[10001];
int rett;

int go(pair<int,int> vertex){
	int temp = vertex.first;
	if(v[temp].size()==0){
		return vertex.second;
	}
	int ret=0;
	int &ret = dp[temp];
	if(ret) return ret;
	for(int i=0; i<v[temp].size(); i++){
		ret = max(ret,vertex.second+go(v[temp][i]));
	}
	return ret;
}


int main(){
	cin>>n;
	for(int i=0; i<n-1; i++){
		int temp1,temp2,temp3;
		cin>>temp1>>temp2>>temp3;
		v[temp1].push_back({temp2,temp3});
	}
	for(int j=1; j<=n; j++){
		res.clear();
		for(int i=0; i<v[j].size(); i++){
			res.push_back(go(v[j][i]));
		}
		if(res.size()) rett= max(rett,res[0]);
		if(res.size()>1){
			sort(res.begin(),res.end());
		//	cout<<res[res.size()-1]<<res[res.size()-2]<<"\n";
			rett = max(rett, res[res.size()-1]+res[res.size()-2]);	
		}
	}
	cout<<rett;
	return 0;
}
