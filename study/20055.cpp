#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> robot;
pair<int,int> a[202];
int num_z;
int stage;

void rotate_belt(){
	pair<int,int> b[202];
	for(int i=0; i<n; i++){
		b[(i+1)%n] = a[i]; 
	}
	for(int i=0; i<robot.size(); i++){
		robot[i]= (robot[i]+1)%n;
		if(robot[i]==n/2-1){
		robot.erase(robot.begin()+i);
		i--;	
		} 
	}
	b[n/2-1].second=0;
	memcpy(a,b,sizeof(b));
	return;
}
void rotate_robot(){
	for(int i=0; i<robot.size(); i++){
		int pos= robot[i];
		int next= (pos+1)%n;
		if(a[next].first>0&&a[next].second==0){
			robot[i]=(pos+1)%n;
			a[pos].second--;
			a[next].first--;
			a[next].second++;
		if(next==n/2-1){
			a[next].second--;
			robot.erase(robot.begin()+i);
			i--;
		}
		} 
	}
	return;
}

void place_robot(){
	if(a[0].first>0&&a[0].second==0){
		a[0].first--;
		a[0].second++;
		robot.push_back(0);
	}
	return;
}

int main(){
	cin>>n>>k;
	n=2*n;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		a[i]= {temp,0};
	}
	
	while(true){
		num_z=0;
		stage++;
		rotate_belt();
		rotate_robot();
		place_robot();
		for(int i=0; i<n; i++){
			if(a[i].first==0)num_z++;
		}
		if(num_z>=k) break;
	}
	cout<<stage;
	
	return 0;
}
