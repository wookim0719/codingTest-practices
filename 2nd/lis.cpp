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
		// ��������� ī��Ʈ �ִ� 
		int maxvalue= 0; 
		for(int j=0; j<i; j++){
		// ���� i��ġ�� ������ �۰�
		// ī��Ʈ���� ���� ū ��쿡 maxvalue�� �������ش�.  
			if(a[j]<a[i]&& maxvalue<cnt[j]) maxvalue = cnt[j];
		} 
		cnt[i] = maxvalue+1;
		ret = max(cnt[i],ret);
	}
	
	cout<<ret;

	return 0;
}
