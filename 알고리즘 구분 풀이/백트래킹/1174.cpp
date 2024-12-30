#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int,ll> mp;
int n;
int main(){
	cin>>n;
	
	for(int i=0; i<10; i++){
		mp[i+1]= i;
	}
	int idx=11;
	int idx2=1;
	ll last= 0;
	while(true){
		ll temp = mp[idx2];
	//	cout<<temp<<"\n";
		for(int i=0;i<=10; i++){
			if(temp%10>i){
				mp[idx] = temp*10+i;
				idx++;
				last = temp*10+i;
			}
		}
		if(last == 9876543210) break;
		idx2++;
	}
	if(n!=1 && mp[n]==0) cout<<-1;
	else
	cout<<mp[n];
	
	return 0;
}
