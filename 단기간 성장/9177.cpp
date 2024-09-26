#include<bits/stdc++.h>
using namespace std;
int t;
bool flag=false;
string t1,t2,t3;
int visited[201][201];
int dp[201][201];
struct thr{
	int a,b,c;
};

void go(){
	thr temp;
	temp.a=0; temp.b=0; temp.c=0;
	queue<thr> q;
	q.push(temp);
	while(q.size()){
		thr f= q.front();
		q.pop();
		if(f.a==t1.size()){
			flag=true;
			return;
		}
		int m=f.a;
		int s1=f.b;
		int s2=f.c;
		//cout<<m<<" "<<s1<<" "<<s2<<"\n";
		if(t1[m]==t2[s1]){
			thr temp2;
			temp2.a= f.a+1;
			temp2.b= f.b+1;
			temp2.c= f.c;
			if(!visited[temp2.b][temp2.c]){
				visited[temp2.b][temp2.c]=1;
				q.push(temp2);	
			}
		}
		if(t1[m]==t3[s2]){
			thr temp2;
			temp2.a= f.a+1;
			temp2.b= f.b;
			temp2.c= f.c+1;
			if(!visited[temp2.b][temp2.c])
			visited[temp2.b][temp2.c]=1;
			q.push(temp2);
		}
	}
	
	return;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>t;
	int cnt=1;
	while(t--){
		memset(visited,0,sizeof(visited));
		flag=false;
		cin>>t2>>t3>>t1;
		go();
		go2(0,0);
		if(flag){
			cout<<"Data set"<<" "<<cnt<<":"<<" yes"<<"\n";
		}
		else{
			cout<<"Data set"<<" "<<cnt<<":"<<" no"<<"\n";
		}
		cnt++;
	}
	
	return 0;
}
