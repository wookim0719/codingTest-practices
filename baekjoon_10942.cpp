#include<bits/stdc++.h>
using namespace std;
int n, a[2004],dp[2004][2004], t, from,to;

void fastIO(){ 
    ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 
	return;
}
int main(){
	fastIO();
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i=1; i<=n; i++){
		dp[i][i]=1;
	}
	for(int i=1; i<n; i++){
		if(a[i] == a[i+1]) dp[i][i+1]=1;
	}
	for(int _size =2; _size<n; _size++){
		for(int i=1; i<=n-_size; i++){
	// a[i]와 a[i+_size]와 같고 안에 값이 펠린드롬이면 펠린드롬이다.  
			if(a[i]== a[i+ _size] && dp[i+1][i+_size-1]){
				dp[i][i+_size]=1;
			}
		}
	}
	
	cin>>t;
	
	while(t--){
		cin>>from>>to;
		cout<<dp[from][to]<<"\n";
	}
	
	return 0;
}
