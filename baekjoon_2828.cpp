#include <bits/stdc++.h>
using namespace std;
int cnt=0;
int main(){
	int n,l,k;
	cin>> n>> l>>k;
	int pos =0;
	int pend=pos+l-1;

	for(int i=0; i<k; i++){
		int input;
		cin>> input;
		int apple = input-1;
		if(pend<apple){
			cnt = cnt+apple-pend;
			pos = pos+apple-pend;
			pend = pos+l-1;
		}
		if(pos>apple){
			cnt = cnt+pos-apple;
			pos = apple;
			pend = pos+l-1;
		}
	}
	
	cout<<cnt;
	return 0;
}
