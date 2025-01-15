#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<char> v;

string go(){
	string res;
	for(int i=0; i<m; i++){
		if(!res.size()) res+=v[i];
		else{
			if(res[0]>=v[i]){
				res= v[i]+res;
			}
			else{
				res+=v[i];
			}
		}
	//	cout<<res<<"\n";
	}
	return res;
}

int main(){
	cin>>n;
	
	while(n--){
		cin>>m;
		v.clear();
		for(int i=0; i<m; i++){
			char temp;
			cin>>temp;
			v.push_back(temp);
		}
		string ret = go();
		cout<<ret<<"\n";
	}
	
	return 0;
}
