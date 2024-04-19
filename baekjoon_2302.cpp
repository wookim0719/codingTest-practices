#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[41]; 
int res=1;
vector<int> v;
int b[41];


int main(){
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int temp;
		cin>>temp;
		a[temp]=1;
	}
	int cnt=0;
	for(int i=1; i<=n; i++){
		if(a[i]==0) cnt++;
		else{
			v.push_back(cnt);
			cnt=0;
		}
	}
	v.push_back(cnt);
	b[1]=1;
	b[2]=2;
	
	for(int i=3; i<=40; i++){
		b[i] = b[i-1]+b[i-2];
	}
	
	
	for(int k: v){
	if(k!=0)
	res= res*b[k];
	
}
	cout<<res;	
	
	return 0;
}
