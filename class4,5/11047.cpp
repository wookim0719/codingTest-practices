#include<bits/stdc++.h>
using namespace std;
int n;
int g;
vector<int> v;
int cnt;
//
//void go(int now,int cnt){
//	if(now==0){
//		ret=min(ret,cnt);
//		return;
//	}
//	for(int i=n-1; i>=0; i--){
//		if(now>=v[i]){
//			go(now-v[i],cnt+1);
//		}
//	}
//	return;
//}

int main(){
	cin>>n>>g;
	
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	
	while(true){
		if(g==0)break;
	//	cout<<g<<"\n";
		cnt++;
		for(int i=v.size()-1; i>=0; i--){
			if(g>=v[i]){
				g-=v[i];
				break;
			}
		}	
	}
	cout<<cnt;
	return 0;
}
