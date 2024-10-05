#include<bits/stdc++.h>
using namespace std;
int n;

int main(){
	cin>>n;
	deque<int> q;
	for(int i=0; i<n; i++){
		string temp;
		cin>>temp;
		if(temp=="push"){
			int temp2;
			cin>>temp2;
			q.push_back(temp2);
		}
		else{
			if(temp=="front"){
				if(q.size()){
					cout<<q.front()<<"\n";
				}
				else cout<<-1<<"\n";
			}
			if(temp=="back"){
				if(q.size()){
					cout<<q.back()<<"\n";
				}
			}
			if(temp=="size"){
				cout<<q.size()<<"\n";
			}
			if(temp=="pop"){
				if(q.size()){
					cout<<q.front()<<"\n";
					q.pop_front();
				}
				else cout<<-1<<"\n";
			}
			if(temp=="empty"){
				if(q.size()){
					cout<<0<<"\n";
				}
				else cout<<1<<"\n";
			}
		}
	}
	
	return 0;
}
