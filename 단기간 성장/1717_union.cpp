#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000001];

int findp(int n){
	if(a[n]==n) return n;
	return a[n] = findp(a[n]);
}
void unionp(int t1,int t2){
	t1= findp(t1);
	t2= findp(t2);
	if(t1>t2) a[t2] = t1;
	else a[t1]=t2; 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=0; i<=n; i++){
		a[i]=i;
	}
	for(int i=0; i<m; i++){
		int t1,t2,t3;
		cin>>t1>>t2>>t3;
		if(t1){
		 if(findp(t2)==findp(t3))
		 cout<<"YES"<<"\n";
		 else cout<<"NO"<<"\n";
		}
		else{
		   unionp(t2,t3);
		}
	}
//	for(int i=0; i<=n; i++){
//		cout<<mp2[i]<<"\n";
//	}
//	for(int i=0; i<=n; i++){
//		cout<<mp2[i]<<"\n";
//	}
	
	return 0; 
}
