#include<bits/stdc++.h>
using namespace std;
int n,a,b;
int v[100001];
int main(){
	cin>>n>>a>>b;
	
	if(a+b>n+1){
		cout<<-1;
	}
	else{
	if(a>=b){
		for(int i=n-b; i>=0; i--){
			v[i]=a;
			if(a>1)	
			a--;
		}
		int temp=1;
		for(int i=n-1; i>n-b; i--){
			v[i]= temp;
			temp++;
		}	
	}
	else if((b>a&& a==1)||(b>a&&(b+a-1==n))){
		int c=b;
		int temp=1;
		for(int i=n-1; i>=a-1; i--){
			if(i==a-1){
				v[i]=b;
			}
			else if(temp<b){
				v[i]=temp;
				temp++;
			}
			else{
				v[i]=1;
			}
		}
		for(int i=a-2; i>=0; i--){
			if(a>1) a--;
			v[i]=a;
		}
	}
	else{
		int c=b;
		int temp=1;
		for(int i=n-1; i>=n-b; i--){
			v[i]= temp;
			temp++;
		}
		for(int i=n-b-1; i>=0; i--){
			if(a>1) a--;
			v[i]=a;
		}	
	}
	for(int i=0; i<n; i++){
		cout<<v[i]<<" ";
	}	
}
	return 0;
}
