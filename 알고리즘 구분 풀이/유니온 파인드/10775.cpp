#include<bits/stdc++.h>
using namespace std;
int g,p;
int dp[100001];
vector<int> v;
int cnt;

int findBest(int num){
	int s=0;
	int e=v.size()-1;
	int result=-1;
	while(s<=e){
		int mid = (s+e)/2;
	//	cout<<mid<<"\n";
		if(v[mid]>num){
			e= mid-1;
		}	
		else{
			result = max(result,mid);
			s= mid+1;
		}
	}
//	cout<<result<<"\n";
	return result;
}

void killl(int num){

	v.erase(v.begin()+num);
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>g>>p;
	
	for(int i=1; i<=g;i++){
		v.push_back(i);
	}
	sort(v.begin(),v.end());
	
	for(int i=0; i<p; i++){
		int temp;
		cin>>temp;
		int idx= findBest(temp);
		if(idx!=-1){
			killl(idx); 
			cnt++;
		}
		else{
			break;
		}
//		for(int i: v){
//			cout<<i<<" ";
//		}
	}
	
	cout<<cnt;
	
	return 0;
}
