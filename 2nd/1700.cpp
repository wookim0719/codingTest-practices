#include<bits/stdc++.h>
using namespace std;
int n;
int a[100];
int hole;
vector<int> h;
int ret=987654321;

void check(int cnt, int index){
	if(index == n) {
		ret = min(ret,cnt);
		return;
	}
	
	//존재하면 넘어가
	if(find(h.begin(),h.end(),a[index])!= h.end()){
		check(cnt, index+1);
	}
	// 존재안하면
	else {
		if(h.size()<hole) {
			h.push_back(a[index]);
			check(cnt, index+1);
		}
		else{
			for(int i=0; i<h.size(); i++){
				int temp = h[i];
				h.erase(h.begin()+i);
				h.push_back(a[index]);
				check(cnt+1,index+1);
				h.pop_back();
				h.push_back(temp);
			}
		}
	}
	return ;
}

int main(){
	cin>>hole>>n;
	
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	check(0,0);
	cout<<ret;
	return 0;
}
