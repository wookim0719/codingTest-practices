#include <bits/stdc++.h>
using namespace std;
int goal,error;
int a[10];
int press;

bool check(int num){
	int flag =0;
	while(true){
		int x = num%10;
		if(a[x]) {
			flag=1;
			break;
		}
		num = num/10;
		if(num==0) break;
	}
	if(!flag)
	return true;
	else 
	return false;
}

int main(){
	cin>>goal>>error;
	for(int i=0; i<error; i++){
		int temp;
		cin>>temp;
		a[temp]++;
	}	
	
	if(error==10){
		press = abs(goal-100);
	}
	else{
		press = abs(goal-100);
		for(int i=0; i<1000000; i++){
			int t= i;
			if(check(i)){
				int y=0;
				y += abs(t-goal);
				while(true){
				   t= t/10;
					y++;
					if(t==0) break;
				}
				press = min(press, y);
			}
		}
		
	}
	
	cout<<press;
	
	return 0;
}
