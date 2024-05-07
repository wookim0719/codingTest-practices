#include<bits/stdc++.h>
using namespace std;
int n;
char a[10];
int e[11];
string max_v="";
string min_v="9999999999";

bool possible(char v,int prev, int now){
	if(v =='<') return prev<now;
	else return prev>now; 
}

void go(string temp,int prev, int index){
	for(int i=0; i<=9;i++){
		if(e[i]&&possible(a[index],prev,i)){
			e[i]=0;
			go(temp+to_string(i),i,index+1);
			e[i]=1;
		}	
	}
	if(index == n){
		max_v = max(max_v,temp);
		min_v = min(min_v,temp);
	}
	return; 
}

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i]; 
	}

	
	for(int i=0; i<=9; i++){
		e[i]=1;
	}
	for(int i=0; i<10; i++){
		e[i]=0;
		go(to_string(i), i,0);
		e[i]=1;
	}
	cout<<max_v<<"\n";
	cout<<min_v;

	
	return 0;
}
