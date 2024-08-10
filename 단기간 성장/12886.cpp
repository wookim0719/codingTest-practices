#include<bits/stdc++.h>
using namespace std;
int a,b,c;
bool flag=0;
int visited[2000][2000];
vector<int> vv;


void go(int t1,int t2, int t3){
	if(t1==t2&&t2==t3){
		flag=1;
		return;
	}
	vv.clear();
	vv.push_back(t1);
	vv.push_back(t2);
	vv.push_back(t3);
	sort(vv.begin(),vv.end());
	if(!visited[vv[0]][vv[1]]){
	visited[vv[0]][vv[1]]=1;
	if(vv[0]!=vv[1])
	go(vv[0]+vv[0],vv[1]-vv[0],vv[2]);
	if(vv[0]!=vv[2])
	go(vv[0]+vv[0],vv[1],vv[2]-vv[0]);
	if(vv[1]!=vv[2])
	go(vv[0],vv[1]+vv[1],vv[2]-vv[1]);	
	}	
	return;	
}

int main(){
	cin>>a>>b>>c;
	int sum = a+b+c;
	
	if(sum%3!=0){
		flag= 0;
		cout<<0;	
	}
	
	else{
	go(a,b,c);	
	if(flag){
		cout<<1;
	}
	else cout<<0;
	}	
	
	return 0;
}
