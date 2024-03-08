#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> v;
priority_queue<int, vector<int>, greater<int>> q;
int a,b;
int ret;

int main(){
	cin>>n;
	
	for(int i=0; i<n; i++){
		cin>> a>>b;
		v.push_back({a,b});
	}
	
	sort(v.begin(), v.end());
	
	for(int i=0; i<n; i++){
		q.push(v[i].second);
		if(q.size()> v[i].first){
			q.pop();
		}
		else{
		q.push(v[i].second);
		}
}
	while(q.size()){
	ret += q.top();
	q.pop();
}
	cout<<ret;
	return 0;
}
