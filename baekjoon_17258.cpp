#include <bits/stdc++.h>
using namespace std;
int n, m, k, t, a, b, cnt[301], dp[301][301];
 vector<pair<int,int>> v;
 
 int go(int here, int num, int prev){
 	if(here == v.size()) return 0;
 	if(dp[here][num]) return dp[here][num];
	// �ʿ��� �ο��� t���� ���� �ο����� ���ش�. �̰� �󸶳� �ο��� �ʿ����� �� 
 	int cost = max(0, t-v[here].second);
	// �̰� ģ����� �����ؾߵ� ����  real_cost�� ���� �־��ش�.  
 	int real_cost = (prev>= cost)? 0: cost-prev;
 	
 	int &ret = dp[here][num];
 	// ���� ������ ������ ��쿡�� if������ �Լ��� �����Ѵ�.  
 	if(num - real_cost>=0){
 		return ret = max(go(here+1,num-real_cost,cost)+v[here].first,go(here+1,num,0));
	 }
	 // �ȵǴ� ��쿡�� �������� �Ѿ��. 
	 else return ret= go(here+1,num,0);
 }
 
 
 
int main(){
	cin>> n>> m>>k>>t;
	for(int j=0; j<m; j++){
		cin>>a>>b;
		for(int i=a; i<b; i++)cnt[i] = min(t, ++cnt[i]);
	}
	int temp = cnt[1];
	//_count �� �ð� �� ����  
	int _count = 1;
	for(int i=2; i<=n; i++){
		//���࿡ �ο� ���� �޶����� ���  
		if(temp != cnt[i]){
			v.push_back({_count,temp});
			_count = 0;
			temp = cnt[i];
		}
		_count++;
	}
	v.push_back({_count, temp});
	    for(pair<int ,int> a : v){
    	cout << a.first << " : " << a.second << "\n";
	}
	// here: ��ġ, k�� ������ ģ����, prev�� �� ģ�� �� 
	cout<<go(0,k,0)<<"\n";
	return 0;
}
