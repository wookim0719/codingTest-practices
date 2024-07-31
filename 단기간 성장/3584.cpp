#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int v[10001];
unordered_map<int,int> mp;

int main(){
	cin>>t;
	while(t--){
		fill(v,v+10001,0);
		mp.clear();
		cin>>n;
		for(int i=0;i<n-1; i++){
		int a,b;
		cin>>a>>b;
		v[b]=a;	
		}
		int c,d;
		cin>>c>>d;
		while(true){
		mp[c]=1; 
		if(v[c]==0)break;
		c= v[c];
		}
		while(true){
		if(mp[d]==1) {
		cout<<d<<"\n";
		break;
		}
		if(v[d]==0)break;
		d= v[d];
		}
	}
	
	return 0;
}
