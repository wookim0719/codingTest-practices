#include<bits/stdc++.h>
using namespace std;
int n;
priority_queue<int,vector<int>, greater<int>> pq;
vector<pair<int,int>> v;
int ret;
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		int t1,t2,t3;
		cin>>t1>>t2>>t3;
		v.push_back({t2,t3});
	}	
	sort(v.begin(),v.end());
	
	for(int i=0; i<v.size(); i++){
		if(pq.size()){
			if(pq.top()<=v[i].first){
				pq.pop();
				pq.push(v[i].second);
			}
			else 
				pq.push(v[i].second);
		}
		else 
			pq.push(v[i].second);
	}
	
	while(pq.size()){
		pq.pop();
		ret++;
	}
	cout<<ret;
}
