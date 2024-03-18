#include <bits/stdc++.h>
using namespace std;

int n;
int a[12];
int o[5];
char b[5] = {'+', '-', '*','/'};
const int INF = 10000001;
const int DNF = -100000001;
int max_ret = DNF;
int min_ret = INF;

void find(string s){
	int value = a[0];
	for(int i=0; i<n-1;i++){
		if(s[i] == '+')
			value = value + a[i+1];	
		if(s[i] == '-')
			value = value - a[i+1];	
		if(s[i] == '*')
			value = value * a[i+1];	
		if(s[i] == '/')
			value = value / a[i+1];		
	}
	max_ret = max(value,max_ret);
	min_ret = min(value,min_ret);
	
	return;
}



void calcul(string temp){
	if(temp.size()==n-1){
		find(temp);
		return;
	}
	for(int i=0; i<4; i++){
		if(o[i]) {
			o[i]--;
			calcul(temp+b[i]);
			o[i]++;
		}
	}
	return;
}



int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	for(int i=0; i<4; i++){
		cin>>o[i];
	}	
	
	calcul("");
	
	cout<<max_ret<<"\n"<<min_ret;
	return 0;
}
