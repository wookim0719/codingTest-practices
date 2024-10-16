#include<bits/stdc++.h>
using namespace std;
int n;
int a[129][129];
int cnt1;
int cnt2;

void go(int y,int x,int range){
	bool flag=true;
	int stan=a[y][x];
	for(int i=y; i<y+range; i++){
		for(int j=x; j<x+range; j++){
			if(a[i][j]!=stan) {
				flag= false;
				break;
			}
		}
	}
	if(flag){
		if(stan) cnt2++;
		else cnt1++;
	}
	else{
		int value= range/2;
		//cout<<y<<" "<<x<<" "<<range<<"\n";
		go(y,x,range/2);
		go(y+value,x+value,value);
		go(y,x+value,value);
		go(y+value,x,value);
	}
	return;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
		}
	}
	
	go(0,0,n);
	
	cout<<cnt1<<"\n";
	cout<<cnt2<<"\n";
	
	return 0;
}
