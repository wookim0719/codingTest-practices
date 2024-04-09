#include <bits/stdc++.h>
using namespace std;
int n,k;
typedef long long ll;
pair<int,int> w[101];
pair<int,int> b[101];
int v[101][100001];

int check(int num,int value,int limit){
//	cout<<num<<" "<<value<<" "<<limit<<"\n";
	if(num==n) return value;
	int& ret = v[num][limit];
    if(ret) return ret;
	ret = -1e6;
	if(limit-w[num].first>=0) ret =max(ret,check(num+1,value+w[num].second,limit-w[num].first));
	if(limit-b[num].first>=0) ret =max(ret,check(num+1,value+b[num].second,limit-b[num].first));
	return ret;
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
	cin>>n>>k;
	for(int i=0;i<n; i++){
		int temp1,temp2,temp3,temp4;  
		cin>>temp1>>temp2>>temp3>>temp4;
		w[i] = {temp1,temp2};
		b[i] = {temp3,temp4}; 
	}
	
	int a = check(0,0,k);

	cout<<a;	
	return 0;
}
