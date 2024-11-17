#include<bits/stdc++.h>
using namespace std;
int n,m;
bool isprime[1000001];

void go(){
	isprime[0]=false;
	isprime[1]=false;
	for(int i=2; i*i<=m; i++){
		if(isprime[i])
		for(int j=i*i; j<=m; j+=i){
			isprime[j] = false;
		}
	}
}

int main(){
	cin>>n>>m;
	fill(isprime,isprime+1000001,true);	
	go();
	for(int i=n; i<=m; i++){
		if(isprime[i])
			cout<<i<<"\n";
	}
	
	return 0;
}
