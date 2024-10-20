#include<bits/stdc++.h>
using namespace std;
int cnt;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num=1;
	while(true){
		cnt=0;
		queue<char> q;
		string temp;
		cin>>temp;
		if(temp[0]=='-') break;
		for(char c: temp){
			if(c=='{')q.push('{');
			else{
				if(q.size()){
				char f = q.front();
				if(f=='{') q.pop();
				}
				else{
					q.push('{');
					cnt++;
				}	
			}
		}
		if(q.size()){
			cnt+= (q.size()/2);
		}
		cout<<num<<'.'<<" "<<cnt<<"\n";
		num++;
	}
	return 0;
}
