#include<bits/stdc++.h>
using namespace std;
int n,m,h;
int a[501][501];
int res;
int ret=987654321;

int main(){
	cin>>n>>m>>h;
	int highest=0;
	for(int i=0;i<n; i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];
			highest = max(highest,a[i][j]);
		}
	}
	
	for(int i=highest; i>=0; i--){
		int r=0;
		int p=0;
		for(int j=0; j<n; j++){
			for(int k=0; k<m; k++){
				if(a[j][k]>=i){
					r+=a[j][k]-i;
				}
				else{
					p+=i-a[j][k];
				}
			}
		}
		if(h+r>=p){
		int value= 2*r+p;
	//	cout<<value<<" "<<i<<"\n";
		if(value<ret){
			ret=value;
			res=i;
		}
		}
	}
	cout<<ret<<" "<<res;
	return 0;
}
