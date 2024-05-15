#include<bits/stdc++.h>
using namespace std;

int h,n;
int a[102];
int ret;
vector<int> v;

int main(){
	cin>>h>>n;
	
	for(int i=0;i<n; i++){
		cin>>a[i];
	}
	int index=0;
	
	while(true){
	if(index==n) break;
	if(find(v.begin(),v.end(),a[index])!= v.end()){
		index++;
	}
	else{
		if(v.size()<h) {
			v.push_back(a[index]);
			index++;
		}
		else{
		int last=0;
		int pos =0;
		for(int i=0; i<v.size(); i++){
			int here= n;
			for(int j=index+1; j<n; j++){
				if(a[j]==v[i]){
					here = j;
					break;
				}
				}
				if(last<here){
				last = here;
				pos = i;
			}
		}
		v.erase(v.begin()+pos);	
		v.push_back(a[index]);
		index++;
		ret++;
	}
	}
}
	
	cout<<ret;
	return 0;

}
