#include<bits/stdc++.h>
using namespace std;
int a[301][301];
int v[301][301];
int n,m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(j!=0)
			v[j][i] += a[j][i]+ v[j-1][i];
			else 
			v[j][i] = a[j][i];
		}
	}
	
	int t;
	cin>>t;
	for(int i=0; i<t; i++){
		int t1,t2,t3,t4;
		cin>>t1>>t2>>t3>>t4;
		t1--;t2--;t3--;t4--;
		int sum=0;
		for(int i=t2; i<=t4; i++){
			if(t1!=0)
			sum+= v[t3][i]-v[t1-1][i];
			else sum+= v[t3][i];
		}	
		cout<<sum<<"\n";
	}
	
	return 0;
}
