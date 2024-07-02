#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin>>n;
	while(n--){
		int ret=987654321;
		int ret2=0;
		vector<int> v[27];
		string s;
		int k;
		cin>>s;
		cin>>k;
	for(int i=0 ;i<s.size(); i++){
		v[s[i]-'a'].push_back(i);
	}
	for(int i=0; i<27;i++){
		if(v[i].size()>=k){
			for(int j=0; j<=v[i].size()-k; j++){
			//	cout<<i<<v[i][j+k-1]-v[i][j]<<"\n";
				ret= min(ret, v[i][j+k-1]-v[i][j]+1);
				ret2= max(ret2,v[i][j+k-1]-v[i][j]+1);
			}	
		}
	}
	if(ret!=987654321)
	cout<<ret<<" "<<ret2<<"\n";	
	else cout<<-1<<"\n";
	}	
	
	return 0;
}
