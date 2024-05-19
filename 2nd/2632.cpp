#include<bits/stdc++.h>
using namespace std;
int goal;
int an,bn;
int a[1001];
int b[1001];
int suma[10000001];
int sumb[10000001];
vector<int> v;
int res;
int sum; 

bool possible(int temp,int s){
	v.clear();
	for(int i=0; i<s; i++){
		if(temp&(1<<i)){
			v.push_back(i);
		}
	}
	if(v.size()&&(v[0]==0)&&(v[v.size()-1]==s-1)){
	int index=0;
	for(int i=0; i<v.size()-1; i++){
		if(v[i+1]-v[i]!= 1) {
		index= i+1;	
		break;
		}
	}
	if(index== v.size()-1) return true;
	for(int i=index; i<v.size()-1; i++){
		if(v[i+1]-v[i]!=1)return false;
	}
		return true;	
	}
	
	else if(v.size()){
			for(int i=0; i<v.size()-1; i++){
		if(v[i+1]-v[i]!= 1) return false;
	}
	return true;
	}
	
	return true;
}

int main(){
	cin>>goal>>an>>bn;
	for(int i=0; i<an; i++){
		cin>>a[i; 
	}
	for(int i=0; i<bn; i++){
		cin>>b[i];
	}
	
	for(int i=0; i<(1<<an); i++){ 
		if(possible(i,an)){
			sum=0;
			for(int j=0; j<an; j++){
				if(i&(1<<j)) sum+=a[j];
			}
			if(sum>0)
			suma[sum]++;
		}
	}
	for(int i=0; i<(1<<bn); i++){
		if(possible(i,bn)){
			sum=0;
			for(int j=0; j<bn; j++){
				if(i&(1<<j)) sum+=b[j];
			}
			if(sum>0)
			sumb[sum]++;
		}
	}

	// 두 피자를 모두 이용해서 구하는 경우 
	for(int i=1; i<goal; i++){
		res+= suma[i] * sumb[goal-i];

	} 
	//한 피자만 사용하는 경우 
	res+=suma[goal];
	res+=sumb[goal]; 
	

	cout<<res;
	return 0;
}
