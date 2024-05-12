#include<bits/stdc++.h>
using namespace std;
string s;
string bomb;
queue<char> q1;
queue<char> q2;

int main(){
	cin>>s>>bomb;
	while(true){
		bool flag=false;
		string t=s;
		int index= 0;
		for(int i=0; i<s.size();i++){
			if(s[i]==bomb[0]&&index==0){
			//	cout<<i<<"\n";
				index++;
				q2.push(s[i]);
			}
			//만약에 비교가 진행되는 경우에 
			//같으면 넣고  틀리면 다시 넣어준다. 
			else if(index>0){
			//	cout<<i;
				if(s[i]==bomb[index]){
					q2.push(s[i]);
					index++;
				}
				else{
				 if(s[i]!=bomb[index]){
				 //	cout<<i<<"\n";
				 	while(q2.size()) {
				 		char temp = q2.front();
				 		q1.push(temp);
				 		q2.pop();
					 }
					 if(s[i]==bomb[0]){
					 	q2.push(s[i]);
					 	index=1;
					 }
					 else{
					 q1.push(s[i]);
					 index=0; 
				}
				 }	
				}
				if(q2.size() == bomb.size()){
				//	cout<<i;
					while(q2.size()) q2.pop();
					index=0;
					flag= true;
				}
			}
			else{
			q1.push(s[i]); 
			} 
		}
		s="";
		while(q1.size()){
			char k= q1.front();
			s.push_back(k);
			q1.pop();
		}			
			if(!flag) break;
	}
	
	if(s.size()) cout<<s;
	else cout<<"FRULA";
	
	return 0;
}
