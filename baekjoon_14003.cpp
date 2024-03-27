#include <bits/stdc++.h>
using namespace std;
int n,num,len;
int a[1000004];
pair<int,int> ans[1000004];
const int INF = 1e9+4;
stack<int> stk;

int main(){
	cin>>n;
	fill(a, a+1000004,INF);
		
	for(int i=0; i<n; i++){
		cin>>num;
		auto lowerPos = lower_bound(a,a+len,num);
		int _pos = (int)(lower_bound(a,a+len,num) - a);
		// 작은 위치의 값이 INF이면 제일 큰 값이므로 길이를 증가시켜준다.  
		if(*lowerPos == INF) len++;
		*lowerPos = num;
		 ans[i].first = _pos;
		 ans[i].second= num;
	}
	cout<<len<<"\n";
	
	// 10 20 30 14의 경우에는 30이 먼저 들어가므로 그 14가 스택에 들어가지 못한다.
	//그렇다고 해서 25가 10과 20사이에 존재하는 경우에는 20이 먼저 들어가게 되고 len이
	//줄어드므로 25가 들어갈 수 없다. 
	for(int i=n-1; i>=0; i--){
		if(ans[i].first == len-1){
			stk.push(ans[i].second);
			len--;
		}
	}
	
	while(stk.size()){
		cout<<stk.top()<< " ";
		stk.pop();
	}
	
	return 0;
}
