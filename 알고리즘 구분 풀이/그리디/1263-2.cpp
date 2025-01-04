#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> v;
vector<pair<int,int>> v2;

vector<int> job;

bool pos(int s){
	int ss= s;
	//cout<<s<<"\n";
	for(int i=0; i< v2.size(); i++){
	//	cout<<s<<"\n";
		if((ss+v2[i].second)<=v2[i].first){
			ss = ss+v2[i].second;
		}
		else return false;
	}
//	cout<<s;
	return true;
}

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		int t1,t2;
		cin>>t1>>t2;
		v.push_back({t2-t1,t2});
		v2.push_back({t2,t1});
	}	
	sort(v.begin(),v.end());
	bool flag= false;
	int s = v[0].first;
	sort(v2.begin(),v2.end());
	while(true){
		if(s<0) break;
		if(pos(s))
		break;
		flag = true;
		s--;
	}
	if(s<0) cout<<-1;
	else cout<<s;
	
	return 0;
}
