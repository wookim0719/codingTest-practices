#include<bits/stdc++.h>
using namespace std;
string a = "000000000000000000000";
int n;
int value;


int main(){
	 ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	
	cin>>n;
	int b = n-1;
	
	while(b--){
		string s;
		cin>>s;
		if(s[0] == 'a'&&s[2]=='d'){
			cin>>value;
			a[value] = '1';
		}
		if(s[0]== 'c'){
			cin>>value;
		if(a[value]=='1')
	cout<<1<<"\n";
	else
	cout<<0<<"\n";

		}
		if(s[0]== 'r'){
		cin>>value;
		a[value] = '0';

		}
		if(s[0]== 'e')
	a="000000000000000000000";
		if(s[0]== 't'){
						cin>>value;
			if(a[value]=='1') a[value]='0';
	else a[value]='1';
		}
		if(s[0]== 'a'&& s[2]=='l')
	a="111111111111111111111";
	}

	
	return 0;
}
