#include<bits/stdc++.h>
using namespace std;
int n;
double m;
int dp[100001];
vector<pair<int,double>> v;

int go(int price){
	int& ret = dp[price];
	if(ret) return ret;
	for(auto i: v){
		if((price+i.second)<=m)
		ret = max(ret, i.first+go(price+i.second));
	}	
	return ret;
}



int main(){
	while(true){
	memset(dp,0,sizeof(dp));
	v.clear();
	cin>>n>>m;
	m*=100;
	for(int i=0; i<n; i++){
		int temp1;
		double temp2;
		cin>>temp1>>temp2;
		v.push_back({temp1,temp2*100});
	}
	if(n==0&&m==0) break;
	int hi= go(0);
	cout<<hi<<"\n";
	}
	
	return 0;
}
