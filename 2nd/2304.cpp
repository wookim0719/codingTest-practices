#include<bits/stdc++.h>
using namespace std;
int n;
int max_h;
int max_i;
int v[1001];
int ret;
int main(){
	cin>>n;
	for(int i=0; i<n;i++){
		int t1,t2;
		cin>>t1>>t2;
		v[t1]=t2;
		if(max_h<=t2){
			max_h=t2;
			max_i=t1;
		}
	}
	int max1=0;
	for(int i=0; i<max_i; i++){
		if(max1<v[i]) max1= v[i];
		ret+=max1;
	}
	int max2=0;
	for(int i=1000; i>max_i; i--){
		if(max2<v[i]) max2= v[i];
		ret+=max2;
	}

	
	cout<<ret+max_h;
	
	
	return 0;
}
