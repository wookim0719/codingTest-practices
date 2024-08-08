#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1025][1025];
int ga[1025][1025];
int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];	
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(j==0){
				ga[i][j]=a[i][j];
			}
			else if(j>0){
				ga[i][j] = ga[i][j-1]+a[i][j];
			}
//			if(i>0){
//				se[i][j] = se[i][j-1]+a[i][j];
//			}
//			else{
//				se[i][j] = a[i][j];
//			}
		}
	}

	while(m--){
		int sum=0;
		int t1,t2,t3,t4;
		cin>>t1>>t2>>t3>>t4;
		t1--; t2--;t3--; t4--;
		for(int i=t1; i<=t3; i++){
			if(t2>0)
			sum+=ga[i][t4]- ga[i][t2-1];	
			else{
			sum+=ga[i][t4];
			}
		}
		cout<<sum<<"\n";
	}
	
	
	return 0;
}
