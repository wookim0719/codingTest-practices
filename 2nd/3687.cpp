#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[10]={6,2,5,5,4,5,6,3,7,6};
ll dp[101];
int n;
int temp;


string make_big(int num){
	string value="";
	if(num%2){
		int zn= num/2-1;
		value= value +'7';
		for(int i=0; i<zn; i++){
			value = value+'1';
		}
	}
	else{
		int zn2= num/2;
		for(int i=0; i<zn2; i++){
			value = value+'1';
		}	
	}
	return value;
}

ll make_min(int num){
	if(num==temp) return 0;
	ll &ret= dp[num];
	if(ret) return ret;
	ret = 1e16;
	for(int i=0; i<10; i++){
		if(num+a[i]<=temp){
		if(num+a[i]==temp&&i==0) continue;
		else{
		ret = min(ret, i+10*make_min(num+a[i]));
		}
		}
	}
	return ret;	
}


int main(){
	cin>>n;
	while(n--){
		cin>>temp;
		memset(dp,0,sizeof(dp));
		cout<<make_min(0)<<" "<<make_big(temp)<<"\n";	
	}
	return 0;
}
