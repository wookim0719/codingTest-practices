#include<bits/stdc++.h>
using namespace std;
int t;
int n;
string a,b;

int counting(){
	int cnt=0;
	for(int i=0; i<n; i++){
		if(a[i]=='B'&&b[i]=='W') cnt++;
	}
	return cnt;
}

int main(){
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		cin>>a>>b;
		int cnt3=0;
		int cnt=0;
		int cnt2=0;
		int cnt4=0;
		int cnt5=0;
		for(char c:a)if(c=='B') cnt++;
		else cnt4++;
		for(char c:b)if(c=='B') cnt2++;
		else cnt5++;
	//	cout<<cnt<<" "<<cnt2<<"\n";
		if(cnt==cnt2){
			cout<<counting()<<"\n";
		}
		else{
			int cnt3=0;
			if((cnt-cnt2)>0)
			for(int i=0; i<n; i++){
				if(a[i]!=b[i]&&a[i]=='B'){
					a[i]=b[i];
					cnt3++;
				//	cout<<cnt3<<" "<<abs(cnt-cnt2)<<"\n";
					if(cnt3==abs(cnt-cnt2)){
						cout<<cnt3+counting()<<"\n";
//						cout<<a<<"\n";
//						cout<<b<<"\n";
						break;
					}
				}
			}
			else{
			for(int i=0; i<n; i++){
				if(a[i]!=b[i]&&a[i]=='W'){
					a[i]=b[i];
					cnt3++;
				//	cout<<cnt3<<" "<<abs(cnt-cnt2)<<"\n";
					if(cnt3==abs(cnt-cnt2)){
						cout<<cnt3+counting()<<"\n";
//						cout<<a<<"\n";
//						cout<<b<<"\n";
						break;
					}
				}
			}
			}
		}
	}	
	return 0;
}
