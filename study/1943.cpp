#include<bits/stdc++.h>
using namespace std;
int temp1,temp2;
int m,c,vv;
int dp[50001];
//[2, 2, 3, 4, 5] ¹Ý 
vector<pair<int,int>> v;
int main(){
	    cin.tie(0); ios_base::sync_with_stdio(0);
	int n=3;
	while(n){
		int sum=0;
		cin>>m;
		v.clear();
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int i=0; i<m; i++){
			cin>>vv>>c;
			v.push_back({vv,c});
			sum+= vv*c;
		}
	if(sum%2!=0){
		cout<<0<<"\n";
	}
	else{
		for(int i=0; i<v.size(); i++){
			for(int k=sum/2; k>=v[i].first; k--){
			if(dp[k-v[i].first]){
				for(int j=0; j<v[i].second; ++j){
					if(k+j*v[i].first>sum/2) break;
					dp[k+j*v[i].first] =true;
				}
				}
		}
	}
		if(dp[sum/2]==0) cout<<0<<"\n";
		else cout<<1<<"\n";
	
	}
		n=n-1;
	}
	
	
	return 0;
}
