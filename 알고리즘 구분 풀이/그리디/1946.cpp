#include<bits/stdc++.h>
using namespace std;
int t,n;
vector<pair<int,int>> p;

int main(){
	cin>>t;
	
	while(t--){
		cin>>n;
		int ret=1;
		p.clear();
		for(int i=0; i<n; i++){
			int t1,t2;
			cin>>t1>>t2;
			p.push_back({t1,t2});
		}
		sort(p.begin(),p.end());
		int tmp=0;
		for(int i=1; i<n; i++){
			if(p[tmp].second > p[i].second){
				ret++;
				tmp = i;
			}
		}
		cout<<ret<<"\n";
	}	
	
	return 0;
}
