#include <bits/stdc++.h>
using namespace std;
int n, a[1001], cnt[1001];
int ret;

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	
	for(int i=0; i<n; i++){
		// 현재까지의 카운트 최댓값 
		int maxvalue= 0; 
		for(int j=0; j<i; j++){
		// 현재 i위치의 값보다 작고
		// 카운트값이 가장 큰 경우에 maxvalue를 변경해준다.  
			if(a[j]<a[i]&& maxvalue<cnt[j]) maxvalue = cnt[j];
		} 
		cnt[i] = maxvalue+1;
		ret = max(cnt[i],ret);
	}
	
	cout<<ret;

	return 0;
}
