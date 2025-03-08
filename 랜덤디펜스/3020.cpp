#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> bottom;
vector<int> high;
vector<int> ret;
int dp[500001];
int cnt=0;
int value = 987654321;

void check(int num){
	auto idx= lower_bound(bottom.begin(),bottom.end(),num);
	int count = idx-bottom.begin(); 
//	cout<<num <<" "<< n/2-count<<"\n";
	dp[num] += n/2-count;
	return;
}

void check2(int num){
	auto idx= lower_bound(high.begin(),high.end(),num);
//	cout<<num<<" "<<idx-high.begin()<<"\n";
	int count = idx-high.begin(); 
	dp[num] += count;
	return;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		if(i%2){
			high.push_back(m-temp);
		}
		else{
			bottom.push_back(temp);
		}
	}
	sort(bottom.begin(),bottom.end());
	sort(high.begin(),high.end());

	for(int i=1; i<=m; i++){
		check(i);
		check2(i);
	//	cout<<dp[i]<<"\n";
		if(dp[i]<value){
		//	cout<<i<<" "<<dp[i]<<"\n";
			cnt =1;
			value = dp[i];
		}
		else if(dp[i]==value){
			cnt++;
		}
	}
	
	cout<<value<<" "<<cnt;
	
	return 0;
}
