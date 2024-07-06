#include<bits/stdc++.h>
using namespace std;
int a,b;
int cntx,cnto;

void check(string str){
	a=0; b=0; cnto=0; cntx=0;
	char temp[3][3];
	for(int i=0; i<9; i++){
		if(str[i]=='O')cnto++;
		else if(str[i]=='X')cntx++;
		temp[i/3][i%3]=str[i];
	}
	
	//가로 길이 체크 	
	for(int i=0; i<3; i++){
		bool flag = true;
		for(int j=0; j<3; j++){
			if(temp[i][0]!=temp[i][j]) flag=false;
		}
		if(flag){
			if(temp[i][0]=='O') a++;
			else if(temp[i][0]=='X') b++;
		}
	} 
	//세로 길이 체크 
		for(int i=0; i<3; i++){
		bool flag2 = true;
		for(int j=0; j<3; j++){
			if(temp[0][i]!=temp[j][i]) flag2=false;
		}
		if(flag2){
			if(temp[0][i]=='O') a++;
			else if(temp[0][i]=='X') b++;
		}
	}
	
	//대각선 체크
	bool flag3=true;
	bool flag4= true;
	for(int i=0; i<3; i++){
		if(temp[0][0]!=temp[i][i]) flag3= false;
		if(temp[0][2] != temp[i][2-i]) flag4=false;	
	}
	if(flag3) {
		if(temp[0][0]=='O') a++;
		else if(temp[0][0]=='X') b++;
	}
	if(flag4) {
		if(temp[0][2]=='O') a++;
		else if(temp[0][2]=='X') b++;
	}
}




int main(){                    
	
	while(true){
		bool fflag=true;
		string s;
		cin>>s;
		if(s=="end")break;
		check(s);
		if(cntx-cnto>1) fflag=false;
		if(cntx<cnto) fflag=false;
		if(a==b&&a>0) fflag=false;
		if(a>b&&cntx>cnto)fflag= false;
		if((cntx+cnto)!=9&&a==0&&b==0) fflag=false;
		if(a<b&&cntx==cnto) fflag=false;
		if(!fflag)cout<<"invalid";
		else cout<<"valid";
		//cout<<a<<" "<<b<<"\n";
		//cout<<cntx<<" "<<cnto<<"\n";
		cout<<"\n";
	}
	
	return 0;
}
