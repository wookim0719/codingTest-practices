#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v;
int sum[100001];
int main(){
//	ios::sync_with_stdio(false);
//	cin.out(NULL);
//	cout.(NULL);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		int tmp;
		cin>>tmp;
		v.push_back(tmp);
	}
	sum[0]=v[0];
	for(int i=1; i<n; i++){
		sum[i]=sum[i-1]+v[i];
	}

	
	while(m--){
		int t1,t2;
		cin>>t1>>t2;
		cout<<sum[t2-1]-sum[t1-2]<<"\n";
	}
	
	return 0;
}
