#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000001];
int cnt[1000001];
int previous[1000001];
int ret;
int idx;
stack<int> stk;

void run(int i){
	int temp = previous[i];
	if(temp==-1) return;
	stk.push(a[previous[i]]);
	run(temp);
	return;
}

int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL); 
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	memset(previous, -1, sizeof(previous));
	
	for(int i=0; i<n; i++){
		int max_value=0;
		for(int j=0; j<i; j++){
			if(a[i]>a[j]&&cnt[i]+1<=cnt[j]){
				if(cnt[j]>max_value) {
					max_value=cnt[j];
					previous[i]=j;
				}
		}
		}
		cnt[i]=max_value+1;
		if(cnt[i]>ret){
			idx=i;
			ret=cnt[i];
		}
	}
	stk.push(a[idx]);
	run(idx);
	cout<<ret<<"\n";
	
	while(stk.size()){
		int b=stk.top();
		stk.pop();
		cout<<b<<" ";
	}
	
	return 0;
}
