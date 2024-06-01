#include<bits/stdc++.h>
using namespace std;
int n;
int p[21];
int j[21];
int res;

void go(int num, int total,int life){
	if(num==n){
		res= max(total,res);
		return;	
	}
	if(life-p[num]>0)
	go(num+1,total+j[num],life-p[num]);
	go(num+1,total,life);	
	return ;
}

 int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>p[i];
	} 
	for(int i=0; i<n; i++){
		cin>>j[i];
	}	
 	
 	go(0,0,100);
 	
 	cout<<res;
 	return 0;
 }
