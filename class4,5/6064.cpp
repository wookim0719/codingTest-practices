#include<bits/stdc++.h>
using namespace std;
int t;
int m,n;
int y,x;

int main(){
	cin>>t;
	
	while(t--){
		cin>>m>>n;
		cin>>y>>x;
		int mn=abs(m-n);
		int yx=abs(y-x);
		bool flag= false;
		// 카잉 달력 종료조건
		 
		if(!flag){
			cout<<-1<<"\n";
		}
		else{
		queue<pair<pair<int,int>,int>> q;
		q.push({{1,1},1});
		while(true){
			auto f= q.front();
			int yy= f.first.first;
			int xx= f.first.second;
		//	cout<<yy<<" "<<xx<<" "<<f.second<<"\n";
			if(yy==y&&xx==x){
				cout<<f.second<<"\n";
				break;
			}
			q.pop();
			yy++;
			xx++;
			if(yy>m){
				yy=1;
			}
			if(xx>n){
				xx=1;
			}
			q.push({{yy,xx},f.second+1});
		}
	}
	}
	
	return 0;
}
