#include <bits/stdc++.h>
using namespace std;
int n, m, k, t, a, b, cnt[301], dp[301][301];
 vector<pair<int,int>> v;
 
 int go(int here, int num, int prev){
 	if(here == v.size()) return 0;
 	if(dp[here][num]) return dp[here][num];
	// 필요한 인원수 t에서 현재 인원수를 빼준다. 이건 얼마나 인원이 필요한지 구 
 	int cost = max(0, t-v[here].second);
	// 이건 친구들로 보충해야될 값을  real_cost에 값을 넣어준다.  
 	int real_cost = (prev>= cost)? 0: cost-prev;
 	
 	int &ret = dp[here][num];
 	// 현재 보충이 가능한 경우에는 if문안의 함수를 실행한다.  
 	if(num - real_cost>=0){
 		return ret = max(go(here+1,num-real_cost,cost)+v[here].first,go(here+1,num,0));
	 }
	 // 안되는 경우에는 다음으로 넘어간다. 
	 else return ret= go(here+1,num,0);
 }
 
 
 
int main(){
	cin>> n>> m>>k>>t;
	for(int j=0; j<m; j++){
		cin>>a>>b;
		for(int i=a; i<b; i++)cnt[i] = min(t, ++cnt[i]);
	}
	int temp = cnt[1];
	//_count 는 시간 을 말함  
	int _count = 1;
	for(int i=2; i<=n; i++){
		//만약에 인원 수가 달라지는 경우  
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
	// here: 위치, k는 가능한 친구수, prev는 들어간 친구 수 
	cout<<go(0,k,0)<<"\n";
	return 0;
}
