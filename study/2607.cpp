#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int a[30];
int temp[30];
int ret;
int len;

void check(string str){
	memset(temp,0,sizeof(temp));
	int cnt=0;
	int cnt2=0;
	for(int i=0; i<str.size(); i++){
		temp[str[i]-'A']++;
	}
	for(int i=0; i<30; i++){
		if(a[i]>temp[i])cnt+=a[i]-temp[i];
		if(a[i]<temp[i])cnt2+=temp[i]-a[i];
	}
	
	if(cnt<=1&&cnt2<=1) ret++;
	return ;
}

int main(){
	cin>>n;
	cin>>s;
	len =s.size();
	for(int i=0; i<len; i++){
		a[s[i]-'A']++;
	}
	
	for(int i=0; i<n-1; i++){
		string temp2;
		cin>> temp2;
		check(temp2);
	}
	cout<<ret;
	return 0;
}
