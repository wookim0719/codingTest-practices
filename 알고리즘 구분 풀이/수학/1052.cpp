#include<bits/stdc++.h>
using namespace std;
int n;
int k;

int go(){
	int temp=n; 
	int val =0;
	while(true){
		if(temp==1) break;
		int value= temp%2;
		if(value){
			val++;
		}
		temp/=2;
	}
	if(temp) val++;
	return val;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k;
	int gap=0;
	while(true){
	//	cout<<n<<" ";
		int res = go();
	//	cout<<res<<"\n";
		if(res <= k) break;
		gap++;
		n++;	
	}	
	cout<<gap;
	return 0;
}
