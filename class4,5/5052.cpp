#include<bits/stdc++.h>
using namespace std;
int t;
vector<string> v;

bool check(int idx){
	string t1=v[idx];
	string t2=v[idx+1];
	bool flag= true;
	
	for(int i=0; i<t1.size(); i++){
	 if(t1[i]!=t2[i]){
			flag= false;
			break;
		}
	}
	return flag;
}

int main(){
	cin>>t;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(t--){
	bool flag=false;
	v.clear();
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		string temp;
		cin>>temp;
		v.push_back(temp);
	}
	sort(v.begin(),v.end());
	for(int i=0; i<v.size()-1; i++){
		if(v[i].size()>v[i+1].size())continue;
		if(check(i)){
			flag=true;
			break;
		}
	}
	if(flag)cout<<"NO"<<"\n";
	else cout<<"YES"<<"\n";
	}
	
	return 0;
}
