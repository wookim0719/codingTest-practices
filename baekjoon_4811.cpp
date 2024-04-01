#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// 가지고있는 온전한 약의 수, 반쪽 약의 수를 따로 저장  
ll a[61][61];

ll test(int one, int half){
	//cout<<cur<<" "<<one<<" "<<half<<" "<<"\n";
	if(one ==0&& half==0)
		return 1;
	ll &ret= a[one][half];
	if(ret) return ret;
	if(half>0){
	ret +=test(one,half-1);
	}
	if(one>0){
	ret += test(one-1,half+1);
	}
		return ret;
} 


int main(){
	while(true){
		int temp;
		cin>>temp;
		if(temp==0)
		break;	
	ll ret2= test(temp,0);
	cout<<ret2<<"\n";
	}
	
	return 0;
}
