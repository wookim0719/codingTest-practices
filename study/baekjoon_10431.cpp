#include<bits/stdc++.h>
using namespace std;
int n;
int num;
vector<pair<int,int>> v;

int main(){
	cin>>n;
	while(n--){
		cin>>num;
		vector<int> a;
		int value =0;
		//매번 새로운 사람이 들어올 때 앞에 몇 명이 자신보다 큰 지 세서 더해주면 됨
		//그리고 키 순으로 정렬을 해준다. 
		for(int i=0; i<20; i++){
			int b;
			cin>> b;
			for(int t: a){
				if(t>b) value++;
			}
			a.push_back(b);	
		}		
		sort(a.begin(), a.end());
		v.push_back({num, value});
	} 	
	
	for(auto i: v){
		cout<<i.first<<" "<<i.second<<"\n";
	}
	return 0;
}
