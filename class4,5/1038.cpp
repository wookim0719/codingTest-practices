#include<bits/stdc++.h>
using namespace std;
int n;
int ccount;
int ret;

void go(int num, int ten){
	if(ten==0) {
		if(ccount == n) ret = num;
		ccount++;
		return;
	}	
	else{
		int last = num%10;
		if(num == 0) last= 10;
		for(int i=0; i<last; i++){
			int next = (num*10)+i;
			if(num==0&& i==0) continue;
			go(next,ten-1);
		}		
	}
	return;
}

int main(){
	cin>>n;
	
	for(int i=0; i<10; i++){
		go(0,i);
	}
	cout<<ret;
	return 0;
}
