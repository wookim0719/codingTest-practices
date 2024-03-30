#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> v;

int main(){
	cin>>n;
	for(int i=0;i<n; i++){
		int a,b;
		cin>>a>>b;
		v.push_back({a,b});
	}
	
	for(int i=0; i<n; i++){
		int ret = 0;
		for(int j=0; j<n; j++){
			if(v[i].first<v[j].first){
				if(v[i].second<v[j].second)
				ret++;
				}
		}
		cout<<ret+1<<" ";
	}

	return 0;
}
