#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a[1000001];
map<int,int> mp2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=0; i<=n; i++){
		a[i].push_back(i);
		mp2[i]=i;
	}
	for(int i=0; i<m; i++){
		int t1,t2,t3;
		cin>>t1>>t2>>t3;
		if(t1){
		 if(mp2[t2]==mp2[t3])
		 cout<<"YES"<<"\n";
		 else cout<<"NO"<<"\n";	
		}
		else{
		   	   int mid= min(mp2[t2],mp2[t3]);
		  	   int mid2= max(mp2[t2],mp2[t3]);
		  	   if(mid==mid2) continue;
		  	   else{
		  		for(int i:a[mid2]){
		   		 a[mid].push_back(i);
		   		 mp2[i]=mid;
		   		}
		   		a[mid2].clear();
			 }	z
		}
	}
	
//	for(int i=0; i<=n; i++){
//		cout<<mp2[i]<<"\n";
//	}
	
	return 0; 
}
