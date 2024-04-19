#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[41];
int v[41];


int go(int num){
	if(num>=n) return 1;
	if(a[num]) return go(num+1);
	int &ret = v[num];
	if(ret!=-1) return ret ;
	ret=0;
	if(!a[num+1]){
		ret+= (go(num+1)+go(num+2));
	}
	else
	ret+= go(num+1);

	return ret;
}

int main(){
	cin>>n>>m;
	for(int i=0; i<m;i++){
		int temp;
		cin>>temp;
		a[temp]=1;
	}
		memset(v, -1, sizeof(v));
	
	int result= go(1);
	
	cout<<result;
	return 0;
}
