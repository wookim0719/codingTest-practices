#include<bits/stdc++.h>
using namespace std;
int num;
int a[101];
int n;

int main(){
	memset(a,-1, sizeof(a));
	cin>>num;
	for(int i=0; i<num; i++){
		cin>>a[i];
	}
	cin>>n;
	
	while(n--){
		int gender;
		int pos;
		cin>>gender>>pos;
		if(gender==1){
			for(int i=0;i<num; i++){
				if((i+1)%pos==0){
					a[i] ^=1;
				}
			}
		}
		if(gender==2){
			int pos2 = pos-1;
			int limit = (pos>num-pos)? num-pos:pos2;
			int z=0;
			for(int i=1; i<=limit; i++){
				if(a[pos2-i] == a[pos2+i]) z++;
				else break;
			}
			a[pos2] = 1^a[pos2];
			for(int i=1; i<=z; i++){
				a[pos2-i] = a[pos2-i]^1;
				a[pos2+i] = a[pos2+i]^1;
			}
		}
	}
	for(int i=0; i<num; i++){
		cout<<a[i]<<" ";
		if((i+1)%20==0)
			cout<<'\n';
	}
	
	return 0;
}
