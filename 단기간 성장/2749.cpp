#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n;
ll A[2][2] = {{1,1},{1,0}};
ll ans[2][2] = {{1, 0}, {0, 1}}; // 단위 행렬로 초기화

void mat_mul(ll a[2][2], ll b[2][2]){
	ll temp[2][2];
	memset(temp,0,sizeof(temp));
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			for(int k=0; k<2; k++){
				temp[i][j] += a[i][k]*b[k][j];
			}
			temp[i][j] = temp[i][j] % 1000000;
		}
	}
	memcpy(a,temp,sizeof(temp));
}
int main(){
	cin>>n;
	
	while(n){
		if(n%2){
			mat_mul(ans,A);
		}
		mat_mul(A,A);
		n/=2;
	}
	cout<<ans[1][0] % 1000000;
	return 0;
}
