#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A,B,C;
ll go(ll a, ll b){
	if(b ==1) return a%C;
	
	ll ret = go(a,b/2);
	ret = (ret*ret) %C;
	// 홀수일 경우 한 번더 곱해서 값을 구해야한다.  
	if(b%2) ret= ret*a%C;
	return ret;
}
int main(){
	cin>>A>>B>>C;
	cout<< go(A,B);
	
	return 0;
}
