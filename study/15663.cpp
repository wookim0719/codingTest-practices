#include<bits/stdc++.h>
using namespace std;
int n;
int m;
map<string,int>mp;
vector<int> v;
vector<int> a;
int visited[10];

void go(){
	if(v.size()==m){
		string temp2="";
		for(int i=0; i<=v.size(); i++){
			temp2+= v[i]+'0';
		}
		if(mp[temp2]==0){
		for(int j=0; j<v.size(); j++){
		cout<<v[j]<<" ";
		}
		cout<<"\n";
		mp[temp2]=1;
		}
		return;
	}
	for(int i=0; i<a.size(); i++){
		if(!visited[i]){
			visited[i]=1;
		v.push_back(a[i]);
		go();
		v.pop_back();
		visited[i]=0;	
		}
	
	}
	return;
}




int main(){
	cin>>n>>m;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		a.push_back(temp); 
		sort(a.begin(),a.end());
	}
	go();
	
	
	return 0;
}
