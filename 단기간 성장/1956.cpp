#include<bits/stdc++.h>
using namespace std;
int a[401][401];
const int INF=987654321;
int ret=INF;

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0; i<n; i++){
		fill(a[i],a[i]+400,INF);
	}
	
	for(int i=0; i<m; i++){
		int t1,t2,t3;
		cin>>t1>>t2>>t3;
		t1--;t2--;
		a[t1][t2]=t3;
	}
	
	for(int k=0; k<n; k++){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
		//	cout<<a[i][j]<<"\n";
			if(i==j)continue;
			ret= min(ret,a[i][j]+a[j][i]);
		}
	}
	if(ret==INF) cout<<-1;
	else
	cout<<ret;
	return 0;
}
