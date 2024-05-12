#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> v;
priority_queue<int,vector<int>,greater<int>> pq;
int ret;

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		int temp1,temp2;
		cin>>temp1>>temp2;
		v.push_back({temp2,temp1});
	}
	sort(v.begin(),v.end());
	for(auto i: v){
		pq.push(i.second);
		if(pq.size()>i.first)
			pq.pop();
	}
	
	while(pq.size()){
		ret+= pq.top();
		pq.pop();
	}
	cout<<ret;
	return 0;
}
