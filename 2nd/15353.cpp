#include<bits/stdc++.h>
using namespace std;
string a,b;
stack<int> sa;
stack<int> sb;
stack<int> c;
int main(){
	cin>>a>>b;
	for(int i=0; i<a.size(); i++){
		sa.push(a[i]-'0');
	}
	for(int i=0; i<b.size(); i++){
		sb.push(b[i]-'0');
	}
	int give=0;
	while(sa.size()||sb.size()){
		int temp1=0;
		int temp2=0;
		if(sa.size()){
			temp1= sa.top();
			sa.pop();
		}
		if(sb.size()){
			temp2 = sb.top();
			sb.pop();
		}
		int temp3 = temp1+temp2+give;
		give= temp3/10;
		c.push(temp3%10);
	}
	if(give)c.push(give);
	
	while(c.size()){
		int z= c.top();
		c.pop();
		cout<<z;
	}
	
	return 0;
}
