#include <bits/stdc++.h>
using namespace std;
int n, lis[1001], len, num;

int main(){
	
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>num;
		// lis�� �Է��� ������ lower  bound��ġ�� ���Ѵ�. 
		auto lowerpos = lower_bound(lis,lis+len, num);
	//			cout<<num<<" "<< *lowerpos<<"\n";	
				
		if(*lowerpos == 0){
		len++;
		} 
		//�ش���ġ�� ���� ��ü�ؼ� �־��ش�.  
		*lowerpos = num; 
	}
	
	cout<<len;
	
	return 0;
}
