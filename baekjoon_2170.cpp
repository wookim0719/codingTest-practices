#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> v;
int ret;
const int INF = 1000000001;
const int DINF = -1000000001;
int startv = INF;
int endv = DINF;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	
	for(int i=0; i<n; i++){
		int a,b;
		cin>>a>>b;
		v.push_back({a,b});
	}
	
	sort(v.begin(), v.end());

	
	for(int i=0; i<n; i++){
		if(v[i].first<=endv){
			if(v[i].second>endv){
				ret+= v[i].second - endv;		
				endv= v[i].second;
			}
		}
		else{
			ret += v[i].second- v[i].first;
			startv = v[i].first;
			endv  = v[i].second;
		}
	}
	
	cout<<ret;
	return 0;
}
