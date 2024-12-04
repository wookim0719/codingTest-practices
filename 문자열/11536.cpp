#include<bits/stdc++.h>
using namespace std;
int n;
vector<string> v;
vector<string> v2;

bool isDsc(){
	sort(v2.begin(),v2.end(),greater<string>());
	for(int i=0; i<v2.size(); i++){
		if(v2[i]!=v[i]){
			v2=v;
			return false;
		}
	}
	return true;
}

bool isAsc(){
	sort(v2.begin(),v2.end());
	for(int i=0; i<v2.size(); i++){
		if(v2[i]!=v[i]){
			return false;
		}
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0; i<n; i++){
		string temp;
		cin>>temp;
		v.push_back(temp);
		v2.push_back(temp);	
	}
	
	if(isAsc()) cout<<"INCREASING";
	else if(isDsc()) cout<<"DECREASING";
	else
	cout<<"NEITHER";
	
	return 0;
}

