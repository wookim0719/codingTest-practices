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
	//a �迭�� �Ҽ��� ��� �߰����ش�.  
	for(int i=2; i<=n; i++){
		if(!che[i]) a[p++] = i;
	}
	
	while(1){
		cout<<sum<<" "<<hi<<" "<<lo<<"\n";
		if(sum>= n) {
			cout<<"���� ���ݴϴ�"<<"\n"; 
			sum -= a[lo++];
		}
		else if(hi == p) break;
		else {
			cout<<"���� �����ݴϴ�"<<"\n";
			sum += a[hi++];
		}
		if(sum == n) ret++;
				cout<<sum<<" "<<hi<<" "<<lo<<"\n";

	} 
	
	
	
	cout<<ret;
	
	
	
	return 0;
}
