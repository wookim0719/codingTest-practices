#include <bits/stdc++.h>
using namespace std;
map<int,int> mp,mp_first;
	int n,c;
	int a[1004];
	vector<pair<int,int>> v;
bool cmp(pair<int,int> a, pair<int, int> b){
	if(a.first == b.first){
		return mp_first[a.second] < mp_first[b.second];
	}
	return a.first > b.first;
}
int main(){

	cin>>n>>c;
	for(int i=0; i<n;i++){
		cin>>a[i];
		//mp에 숫자에 해당하는 키값의 값에 1을 더해준다. 
		mp[a[i]]++;
		//처음 위치를 저장해준다. 
		if(mp_first[a[i]] == 0) mp_first[a[i]]=i+1; 
	} 
	for(auto it: mp){
		v.push_back({it.second,it.first});
	} 
	//내림차순으로 정렬해준다. 
	sort(v.begin(),v.end(),cmp);

	
	for(auto i:v){
		for(int j=0; j<i.first; j++){
			cout << i.second<< " ";
		}
	} 
	return 0;
}
