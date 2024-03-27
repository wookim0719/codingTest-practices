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
		// ���� ��ġ�� ���� INF�̸� ���� ū ���̹Ƿ� ���̸� ���������ش�.  
		if(*lowerPos == INF) len++;
		*lowerPos = num;
		 ans[i].first = _pos;
		 ans[i].second= num;
	}
	cout<<len<<"\n";
	
	// 10 20 30 14�� ��쿡�� 30�� ���� ���Ƿ� �� 14�� ���ÿ� ���� ���Ѵ�.
	//�׷��ٰ� �ؼ� 25�� 10�� 20���̿� �����ϴ� ��쿡�� 20�� ���� ���� �ǰ� len��
	//�پ��Ƿ� 25�� �� �� ����. 
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
