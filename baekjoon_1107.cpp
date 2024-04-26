#include<bits/stdc++.h>
using namespace std;
int goal,error;
int value =0;
const int INF = 987654321;
int res=INF;
int a[11];
int flag2=0;

bool check(int temp){
	bool tt = true;
	while(true){
		int x = temp%10;
		if(a[x]==1){
			tt= false;
			break;
		}
		temp = temp/10;
		if(temp ==0) break;
	}	
	return tt;
}

int main(){
	cin>>goal;
	cin>>error;
	for(int i=0; i<error; i++){
		int temp2;
		cin>>temp2;
		a[temp2] =1 ;
	}
	
	
	for(int i=0; i<1000000; i++){
		value++;
		int possible = check(value);
		if(possible) {
		//	cout<<value<<"\n";
			if(abs(goal-value) < abs(goal-res)){
				res = value;
			}
		}
	}
//	cout<<res<<"\n";
	int press= abs(res-goal);
	while(true){
		res=res/10;
		press++;
		if(res==0) break;

	}
	
	int comp = abs(goal -100);
	if(comp<press) press= comp;	
	
	for(int i=0; i<10; i++){
		if(a[i]==0)
		flag2=1;
	}
	if(flag2==0)press = comp;
	
	cout<<press;
	return 0;
}
