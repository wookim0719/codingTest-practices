#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll b;
ll a[5][5];
ll temp[5][5];
ll v[5][5];
ll v2[5][5];
ll ans[5][5];

void mul(ll v1[5][5], ll v2[5][5]){
	memset(temp,0,sizeof(temp));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<n; k++){
				temp[i][j]+=(v1[i][k]*v2[k][j]);
			}
			temp[i][j]%=1000;
		}
	}
  for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            v1[i][j] = temp[i][j];
        }
    }
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>b;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int tmp;
			cin>>tmp;
			a[i][j]=tmp;
			v[i][j]=tmp;
		}
	}
//	memset(ans,1,sizeof(ans));
	for (int i = 0; i < n; i++) {
    ans[i][i] = 1;  // 대각선 요소를 1로 설정
}	
	while(b>0){
	 if(b%2==1){
	 	mul(ans,a);
	 }
	 mul(a,a);
	 b/=2;
	}	

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}


	return 0;
}
