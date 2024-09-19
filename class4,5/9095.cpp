#include<bits/stdc++.h>
using namespace std;
int t;

int go(int num, int sum){
	int res=0;
	if(sum==num){
		return 1;
	}	
	for(int i=1; i<4; i++){
		if(sum+i<=num){
			res+=go(num,sum+i);
		}
	}	
	return res;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>t;
	while(t--){
		int temp;
		cin>>temp;
		cout<<go(temp,0)<<"\n";
	}
	
	
	return 0;
}
