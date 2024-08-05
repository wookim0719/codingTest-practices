#include<bits/stdc++.h>
using namespace std;
int n;
int dp[1000001];
vector<int> v;
int mp[1000001];
int small;
int big;

int main(){
	std::ios_base::sync_with_stdio( false );
	std::cin.tie( NULL );
	std::cout.tie( NULL );
	cin>>n;
	for(int i=0; i<n; i++){
		int tmp;
		cin>>tmp;
		v.push_back(tmp);
		mp[tmp]=1;
		if(tmp<small) small=tmp;
		if(tmp>big) big=tmp; 
	}
	for(int i=0; i<n; i++){
		for(int j=2; j<=(big/v[i]); j++){
			if(mp[j*v[i]]){
				dp[j*v[i]]-=1;
				dp[v[i]]++;
			}	
		}
	}
	
	for(int i=0; i<v.size(); i++){
		cout<<dp[v[i]]<<" ";	
	}
	return 0;
}
