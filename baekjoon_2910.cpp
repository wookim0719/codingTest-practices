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
		//mp�� ���ڿ� �ش��ϴ� Ű���� ���� 1�� �����ش�. 
		mp[a[i]]++;
		//ó�� ��ġ�� �������ش�. 
		if(mp_first[a[i]] == 0) mp_first[a[i]]=i+1; 
	} 
	for(auto it: mp){
		v.push_back({it.second,it.first});
	} 
	//������������ �������ش�. 
	sort(v.begin(),v.end(),cmp);

	
	for(auto i:v){
		for(int j=0; j<i.first; j++){
			cout << i.second<< " ";
		}
	} 
	return 0;
}
