#include<bits/stdc++.h>
using namespace std;
int n,b;
int v[101][101];
const int INF = 987654321;

int main(){
	cin>>n>>b;
	for(int i=0 ;i<=n; i++){
		for(int j=0; j<=n; j++){
			if(i!=j)
			v[i][j]=INF;
			else v[i][j]=0;
		}
	}
	
	
	for(int i=0; i<b; i++){
		int t1,t2,t3;
		cin>>t1>>t2>>t3;
		if(v[t1][t2]>t3)
		v[t1][t2]=t3;
	}
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
		v[i][j]=min(v[i][j], v[i][k]+v[k][j]);		
		}
	}
	
	}

	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(v[i][j]==INF)cout<<0<<" ";
			else
			cout<<v[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	
	return 0;
}
