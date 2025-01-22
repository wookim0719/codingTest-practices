#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[21][21];
vector<string> v;
int main(){
	cin>>n>>m;
	
	for(int i=0; i<n; i++){
		string temp;
		cin>>temp;
		for(int j=0; j<m; j++){
			a[i][j]=temp[j];
		}	
	}	
	string s;	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(a[i][j]!='#'){
				s+=a[i][j];
			}
			else{
				if(s.size()>1)
				v.push_back(s);
				s.clear();
			}
		}
		if(s.size()>1) v.push_back(s);
				s.clear();
	}
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(a[j][i]!='#'){
				s+=a[j][i];
			}
			else{
				if(s.size()>1)
				v.push_back(s);
				s.clear();
			}
		}
		if(s.size()>1) v.push_back(s);
		s.clear();
	}
	sort(v.begin(),v.end());
	
	//for(string s: v) cout<<s<<"\n";
	cout<<v[0];
	return 0;
}
