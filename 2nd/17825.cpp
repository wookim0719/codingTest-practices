#include<bits/stdc++.h>
using namespace std;
int board[500]={0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40};
int boardb[8] = {13,16,19,25,30,35,40,0};
int boardbb[8] = {22,24,25,30,35,40};
int boardbbb[8] = {28,27,26,25,30,35,40};
int boardbbbb[4] = {25,30,35};
int a[11];
int pos[5];
int ret;

int move(int index, int num){
	if(pos[index]==5){
		pos[index]= 99+num;
	}
	else if(pos[index]==10){
		pos[index]= 199+num;
	}
	else if(pos[index]==15){
		pos[index]= 299+num;
	}
	else{
		pos[index]+=num;
	}
	int value= board[pos[index]];
	return value;
}
bool issame(int index){
	for(int i=0; i<4;i++){
	if(i==index)continue;
	if(pos[index]==pos[i])
	return true;
	if(pos[index]==103&&(pos[i]==202||pos[i]==303))return true;
	if(pos[index]==104&&(pos[i]==203||pos[i]==304))return true;
	if(pos[index]==105&&(pos[i]==204||pos[i]==305))return true;
	if(pos[index]==106&&(pos[i]==205||pos[i]==306||pos[i]==20))return true;
	
	if(pos[index]==202&&(pos[i]==103||pos[i]==303))return true;
	if(pos[index]==203&&(pos[i]==104||pos[i]==304))return true;
	if(pos[index]==204&&(pos[i]==105||pos[i]==305))return true;
	if(pos[index]==205&&(pos[i]==106||pos[i]==306||pos[i]==20))return true;
	
	if(pos[index]==303&&(pos[i]==202||pos[i]==103))return true;
	if(pos[index]==304&&(pos[i]==203||pos[i]==104))return true;
	if(pos[index]==305&&(pos[i]==204||pos[i]==105))return true;
	if(pos[index]==306&&(pos[i]==205||pos[i]==106||pos[i]==20))return true;
	
	if(pos[index]==20&&(pos[i]==205||pos[i]==106||pos[i]==306))return true;
}
	return false;
}

void check(int num, int sum){
	if(num==10) {
		ret =max(sum, ret);
		return;
	}
	int value = 0;
	for(int i=0; i<4; i++){
		int temp= pos[i];
		value = move(i,a[num]);
		if(!issame(i))
		check(num+1,sum+value);
		pos[i] =temp;
	} 	
	return ;
}

int main(){
	for(int i=0; i<10; i++){
		cin>>a[i];
	}
	
	for(int i=0; i<7; i++){
		board[100+i] = boardb[i];
		board[200+i] = boardbb[i];
		board[300+i] = boardbbb[i];
	}
	check(0,0);
	cout<<ret;
	
	return 0;
}
