#include<bits/stdc++.h>
using namespace std;
int n,k,t,m;
int test;
vector<int> res;

struct team{
	int score[105];
	int total=0;
	int submit=0;
	int last=0;
};
int main(){
	cin>>test;
	while(test--){
		int cnt=0;
		cin>>n>>k>>t>>m;
		team temp[105];
		memset(temp,0,sizeof(temp));
		for(int i=0 ;i<m; i++){
			int tea,problem,sco;
			cin>>tea>>problem>>sco;
			temp[tea].submit++;
			temp[tea].last = i;
			if(temp[tea].score[problem]<sco){
			temp[tea].total +=(sco-temp[tea].score[problem]);		
			temp[tea].score[problem]=sco;
		}
		}
//		for(int i=1; i<=n; i++){
//			cout<<temp[i].total<<"\n";
//		}
		for(int i=1; i<=n; i++){
			if(i==t)continue;
			if(temp[i].total>temp[t].total) cnt++;
			else if(temp[i].total==temp[t].total){
				if(temp[i].submit<temp[t].submit) cnt++;
				else if(temp[i].submit==temp[t].submit){
					if(temp[i].last<temp[t].last) cnt++;}
			}
		}
		cout<<cnt+1<<"\n";
	}
	
	
	return 0;
}
