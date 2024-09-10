#include<bits/stdc++.h>
using namespace std;
int n;
int cnt;
int main(){
	cin>>n;
	while(n--){
		int a;
		cin>>a;
		bool flag= false;
		if(a==1 ) flag= true;
		else{
		for(int i=2; i<a; i++){
			if(a%i==0){
				flag= true;
			}
		}
		if(!flag) cnt++;
	}
}
	cout<<cnt;
	return 0;
}
