#include <bits/stdc++.h>
using namespace std;
int n;
int a[44];
const int INF= 987654321;
int ret = INF;
string s;

void go(int here){
	// ���� n��°���� ������ �� �ȵ������� 
	if(here == n+1) {
		int sum = 0;
		for(int i=1; i<=(1<<(n-1)); i *=2) {
			int cnt =0;
			for(int j=0; j<=n; j++) 
			// ù ��° �ڸ��� �ڸ����� 1,2,4�� ��Ÿ���Ƿ� &�����ڷ� 1���� Ȯ�� 
			//i��° �ڸ��� 1�� ��� cnt�� 1�� �����ش�.  
			if(a[j] & i )cnt++;
			// sum���±����� ���� ������ �ƴ� ������ ���� ������ �������� �����ش�.
			// n�� �� �����̹Ƿ� n-cnt�� �������� ����� T�� �����̴�.  
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
		// T�� ��쿡 ���� ���ؼ� �� ���� �߰��Ѵ�.
		//2��° �ڸ��� ��� 2�� a[i]�� 2�� �߰��ȴ�. 
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


