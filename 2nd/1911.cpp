#include<bits/stdc++.h>
using namespace std;
int n,l;
vector<pair<int,int>> v;
int ret;
int index,b;

int main(){
	cin>>n>>l;
	for(int i=0; i<n; i++){
		int temp1,temp2;
		cin>>temp1>>temp2;
		v.push_back({temp1,temp2});
	}
	sort(v.begin(),v.end());
	for(int i=0; i<n; i++){
		if(v[i].second<index) continue;
		if(v[i].first>index){
		b=(v[i].second-v[i].first) / l +((v[i].second-v[i].first)%l?1:0);
		index= v[i].first+b*l;
		}
		else {
		b=(v[i].second-index) / l +((v[i].second-index)%l?1:0);
		index = index+b*l;
		}
		ret+=b;
}
	
	cout<<ret;
	return 0;
}
