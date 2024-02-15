#include <bits/stdc++.h>
using namespace std;

int n;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	for(int i=0; i<n; i++){
		int value;
		int value_2=0;
		int value_5=0;
		cin >>value;
		
		for(int j=2; j<=value; j*=2){
			value_2+= value/j;
		}
		for(int j=5; j<=value; j*=5){
			value_5+= value/j;
		}
		
		cout<<value_5<<"\n";
	}
	return 0;
}
