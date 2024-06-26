#include<bits/stdc++.h>
using namespace std;
int n, e;
struct shortcut{
	int s;
	int e;
	int d;
};
vector<shortcut> v;
int ret = 987654321;;

void go(int c, int total){
	if(total>ret) return;
	else if(c>e) return;
	else if(c==e){
		ret= min(ret,total);
		return;
	}
	for(int i=0; i<v.size(); i++){
		if(c== v[i].s){
			go(v[i].e,total+v[i].d);
		}	
	}
	go(c+1,total+1);
	return;
}

int main(){
	cin>>n>>e;
	for(int i=0; i<n; i++){
		shortcut temp;
		cin>>temp.s>>temp.e>>temp.d;
		v.push_back(temp);
	}
	go(0,0);
	cout<<ret;
	return 0;
}
