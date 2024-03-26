#include <bits/stdc++.h>
using namespace std;
int n, lis[1001], len, num;

int main(){
	
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>num;
		// lis에 입력한 숫자의 lower  bound위치를 구한다. 
		auto lowerpos = lower_bound(lis,lis+len, num);
	//			cout<<num<<" "<< *lowerpos<<"\n";	
				
		if(*lowerpos == 0){
		len++;
		} 
		//해당위치에 값을 대체해서 넣어준다.  
		*lowerpos = num; 
	}
	
	cout<<len;
	
	return 0;
}
