#include <bits/stdc++.h>
using namespace std;
int n;
int a[44];
const int INF= 987654321;
int ret = INF;
string s;

void go(int here){
	// 열의 n번째까지 뒤집을 지 안뒤집을때 
	if(here == n+1) {
		int sum = 0;
		for(int i=1; i<=(1<<(n-1)); i *=2) {
			int cnt =0;
			for(int j=0; j<=n; j++) 
			// 첫 번째 자리등 자리마다 1,2,4를 나타내므로 &연산자로 1인지 확인 
			//i번째 자리가 1인 경우 cnt를 1을 더해준다.  
			if(a[j] & i )cnt++;
			// sum에는기존의 값을 더할지 아님 뒤집은 값을 더할지 작은값을 더해준다.
			// n이 총 갯수이므로 n-cnt는 뒤집었을 경우의 T의 갯수이다.  
			sum += min(cnt,n-cnt); 
		}
		ret = min(ret,sum);
		return ;
	}
		go(here+1);
		a[here] = ~a[here];
		go(here+1);
}


int main(){
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>s;
		int value = 1;
		// T일 경우에 값을 곱해서 그 값을 추가한다.
		//2번째 자리일 경우 2가 a[i]에 2가 추가된다. 
		for(int j=0; j<n; j++){
			if(s[j] =='T')
			a[i] |= value;	
			value *=2;
		}
	}
	
	go(1);
	
	cout<<ret<<"\n";
	return 0;
}


