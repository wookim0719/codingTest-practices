#include<bits/stdc++.h>
using namespace std;
typedef pair<pair<int,string>,int> pp;
int t;
int visited[10000];
int goal;

int numify(string str){
	int num = stoi(str);
	return num;
}

string stringify(int num){
	return to_string(num);
}

int calD(int str){
	str *=2;
	if(str>9999) str%=10000;
	return str;
}
int calS(int str){
	if(str==0) str=9999;
	else{
		str -=1;	
	}
	return str;
}

int calL(int n){
	int l = n % 1000;
    int r = n / 1000;
    return l * 10 + r;
}
int calR(int n){
  	int l = n % 10;
    int r = n / 10;
    return l * 1000 + r;
}


void find(int t1){
	queue<pp> q;
	q.push({{t1,""},0});
	visited[t1]=1;
	while(q.size()){
		auto f= q.front();
		int fStr = f.first.first;
		string orderStr = f.first.second;
		q.pop();
		int cnt = f.second;
		if(fStr== goal){
			cout<<orderStr<<"\n";
			break;
		}
		int v1=calD(fStr);
		if(!visited[v1]){
			q.push({{v1,orderStr+'D'},cnt+1});
			visited[v1]=1;
		}
		int v2=calS(fStr);
		if(!visited[v2]){
			q.push({{v2,orderStr+'S'},cnt+1});
			visited[v2]=1;
		}
		int v3=calL(fStr);
		if(!visited[v3]){
			q.push({{v3,orderStr+'L'},cnt+1});
			visited[v3]=1;
		}
		int v4=calR(fStr);
		if(!visited[v4]){
			q.push({{v4,orderStr+'R'},cnt+1});
			visited[v4]=1;
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>t;
	
	while(t--){
		fill(visited,visited+10000,0);
		int t1;
		cin>>t1>>goal;
		find(t1);
	}
	return 0;
}
