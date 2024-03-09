#include <bits/stdc++.h>
using namespace std;

bool che[4000001];
int n, a[2000001], p,lo,hi,ret,sum;

int main(){
	cin>>n;
	for(int i=2; i<=n; i++){
		if(che[i]) continue;
		for(int j=2*i; j<=n; j+=i){
			che[j] =1;
		}
	}
	//a 배열에 소수인 경우 추가해준다.  
	for(int i=2; i<=n; i++){
		if(!che[i]) a[p++] = i;
	}
	
	while(1){
		cout<<sum<<" "<<hi<<" "<<lo<<"\n";
		if(sum>= n) {
			cout<<"값을 빼줍니다"<<"\n"; 
			sum -= a[lo++];
		}
		else if(hi == p) break;
		else {
			cout<<"값을 더해줍니다"<<"\n";
			sum += a[hi++];
		}
		if(sum == n) ret++;
				cout<<sum<<" "<<hi<<" "<<lo<<"\n";

	} 
	
	
	
	cout<<ret;
	
	
	
	return 0;
}
