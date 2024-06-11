#include<bits/stdc++.h>
using namespace std;
int n;
int a[11];
int v[11];
vector<int> vv;

bool check(){
	bool flag= true;
	for(int i=0; i<n; i++){
		int cnt=0;
		for(int j=0; j<i; j++){
			if(vv[j]>vv[i]) cnt++;
		}
		if(cnt!= a[vv[i]-1]) return false;	
	}
	return true;
}


void go(int num){
	if(num==n){
	 bool ret=check();
	 if(ret){
	 	for(int i=0; i<n; i++){
	 		cout<<vv[i]<<" ";
		 }
		 	 exit(0);
	 }
	}
	for(int i=1; i<=n; i++){
	if(v[i]==0){
		v[i]=1;
		vv.push_back(i);
		go(num+1);
		vv.pop_back();
		v[i]=0;	
	}
}
	return;
}


int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	
	go(0);
	return 0;
}
