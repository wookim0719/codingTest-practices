#include<bits/stdc++.h>
using namespace std;

int a[7];
int n,m2,y,x,c;
int m[21][21];

int main(){
	cin>>n>>m2;
	cin>>y>>x>>c;
	for(int i=0; i<n; i++){
		for(int j=0; j<m2; j++){
			cin>>m[i][j];
		}
	}
	for(int i=0; i<c; i++){
		int d;
		cin>>d;
		if(d==4&&(y+1)<n){
			y=y+1;
		 int temp=a[1];
		  a[1]=a[5];
		  a[5]=a[2];
		  a[2]=a[6];
		  a[6]=temp;
		if(m[y][x]){
		  a[2] = m[y][x];
		  m[y][x]=0;			
		}
		else{
			m[y][x]=a[2];	
		}
		cout<<a[1]<<"\n";
		}
		if(d==3&&(y-1)>=0){
		  y=y-1;
		  int temp=a[1];
		  a[1]=a[6];
		  a[6]=a[2];
		  a[2]=a[5];
		  a[5]=temp;
		if(m[y][x]){
		  a[2] = m[y][x];
		  m[y][x]=0;			
		}
		else{
			m[y][x]=a[2];	
		}
		cout<<a[1]<<"\n";
		}
		if(d==2&&(x-1)>=0){
		  x=x-1;
		  int temp=a[1];
		  a[1]=a[4];
		  a[4]=a[2];
		  a[2]=a[3];
		  a[3]=temp;
		if(m[y][x]){
		  a[2] = m[y][x];
		  m[y][x]=0;			
		}
		else{
			m[y][x]=a[2];	
		}
		cout<<a[1]<<"\n";
		}
		if(d==1&&(x+1)<m2){
		  x=x+1;
		  int temp=a[1];
		  a[1]=a[3];
		  a[3]=a[2];
		  a[2]=a[4];
		  a[4]=temp;
		if(m[y][x]){
		  a[2] = m[y][x];
		  m[y][x]=0;			
		}
		else{
			m[y][x]=a[2];	
		}
		cout<<a[1]<<"\n";
		}
	}

	
	
	return 0;
}
