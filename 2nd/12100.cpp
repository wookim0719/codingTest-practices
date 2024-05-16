#include<bits/stdc++.h>
using namespace std;
int n;
int a[21][21];
int zero,past;
int ret;

void move_down(){
	for(int i=0; i<n; i++){
		int zero=0;
		int past=0;
		for(int j=n-1 ; j>=0; j--){
			if(a[j][i]==0)zero++;
			else{
			if(a[j][i]==past) {
				a[j+zero+1][i]*=2;
				a[j][i]=0;
				past=0;
				zero++;
		}
		//숫ㅈ가 같지 않을때  
		else{
			past = a[j][i]; 
			if(zero>=1){
			a[j+zero][i]= a[j][i];
			a[j][i]=0;	
			}
		}
	}
	}
}
	return ;
}

void move_up(){
	for(int i=0; i<n; i++){
		int zero=0;
		int past=0;
		for(int j=0 ; j<n; j++){
			if(a[j][i]==0)zero++;
			else{
			if(a[j][i]==past) {
				a[j-zero-1][i]*=2;
				a[j][i]=0;
				past=0;
				zero++;
		}
		//숫ㅈ가 같지 않을때  
		else{
			past = a[j][i]; 
			if(zero>=1){
			a[j-zero][i]= a[j][i];
			a[j][i]=0;	
			}
		}
	}
	}
}
	return ;
}
void move_right(){
	for(int i=0; i<n; i++){
		zero=0;
		past=0;
		for(int j=n-1 ; j>=0; j--){
			if(a[i][j]==0){
			zero++;
			}
			else{
			if(a[i][j]==past&&a[i][j]!=0) {
				a[i][j+zero+1] +=a[i][j];
				a[i][j]=0;
				past = 0;
				zero++;
		}
		else{
			past =a[i][j];
			if(zero>=1){
			a[i][j+zero]= a[i][j];
			a[i][j]=0;	
			}
		}
	}
	}
}
	return ;
}
void move_left(){
	for(int i=0; i<n; i++){
		zero=0;
		past=0;
		for(int j=0 ; j<n; j++){
			if(a[i][j]==0){
			zero++;
			}
			else{
			if(a[i][j]==past&&a[i][j]!=0) {
				a[i][j-zero-1] +=a[i][j];
				a[i][j]=0;
				past = 0;
				zero++;
		}
		else{
			past =a[i][j];
			if(zero>=1){
			a[i][j-zero]= a[i][j];
			a[i][j]=0;	
			}
		}
	}
	}
}
	return ;
}

void go(int num){
	if(num==5){
		for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			ret = max(ret,a[i][j]);
		}
	}
	return;
	}
	int b[21][21];
	memcpy(b,a,sizeof(a));
	move_up();
	go(num+1);
	memcpy(a,b,sizeof(a));
	move_right();
	go(num+1);
	memcpy(a,b,sizeof(a));
	move_down();
	go(num+1);
	memcpy(a,b,sizeof(a));
	move_left();
	go(num+1);
	return;
}

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
		}
	}
	go(0);
	
	cout<<ret;
	return 0;
}
