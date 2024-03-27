#include <bits/stdc++.h>
using namespace std;
int n;
int ret =1;
int cnt[101];
vector<pair<int,int>> v;

	int main(){
	cin>>n;

	for(int i=0;i<n;i++){
		int a, b;
		cin>> a>>b;
		v.push_back({a,b});
		}

	sort(v.begin(),v.end());
	
	for(int i=0; i<n; i++){
		int max_value=0;
		for(int j=0; j<i; j++){
			if(v[j].second<v[i].second && cnt[j]>max_value)
			max_value = cnt[j];
		}
		cnt[i]= max_value+1;
		ret = max(ret,cnt[i]);
	}
	
	cout<<n-ret;
	
	return 0;
}
