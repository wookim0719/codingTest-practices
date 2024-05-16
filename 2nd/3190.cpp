#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[101][101];
int turn;
int tim[101];
char dir[101];
int sizee;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int visited[101][101];

deque<pair<int,int>> pos;

bool check(){
	if(pos.front().first<0||pos.front().second<0||pos.front().first>=n||pos.front().second>=n){
		return false;
	}
	if(visited[pos.front().first][pos.front().second]>1) return false;
	else 
	return true;
}

bool go(int d){
	bool flag= true;
	int y= pos.front().first;
	int x= pos.front().second;
	if(a[y+dy[d]][x+dx[d]]){
		a[y+dy[d]][x+dx[d]]=0;
		sizee++;
		pos.push_front({y+dy[d],x+dx[d]});
		visited[y+dy[d]][x+dx[d]]++;
		}
	//사과가 존재하지 않을 때 
	else{
		pos.push_front({y+dy[d],x+dx[d]});
		visited[y+dy[d]][x+dx[d]]++;
		flag = check();
				visited[pos.back().first][pos.back().second]--;

		pos.pop_back();
	}
	return flag; 
}

int main(){
	cin>>n>>k;
	for(int i=0; i<k; i++){
		int temp1,temp2;
		cin>>temp1>>temp2;
		a[temp1-1][temp2-1] = 1;
	}
	cin>>turn;
	for(int i=0; i<turn; i++){
		cin>>tim[i]>>dir[i];
	}
	bool stop = false;
	pos.push_front({0,0});
	visited[0][0]=1;
	int d = 1;
	int current=0;
	for(int i=0; i<turn; i++){
		for(int j=current; j<tim[i]; j++){
			current++;
			if(!go(d)) {
				stop = true;
				break;
			}
		}
		if(stop) break;
		if(dir[i]=='D') d= (d+1)%4;
		else d= (d+3)%4;
	}

	if(!stop){
		while(true){
			current++;
			if(!go(d))
 	break;
		}
	}
	
	cout<<current;
	return 0;
}
