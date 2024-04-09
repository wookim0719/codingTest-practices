#include <bits/stdc++.h>
using namespace std;
int a[100001];
pair<int,int> p = {0,0};
int power,cnt;
// 횟수와 순간의 왼쪽, 오른쪽을 저장함   
int v[100001][5][5];

int go(int n, int pos){
	if(pos == 0) return 2;
	else if(pos==a[n]) return 1;
	else if((pos+2)%4==a[n]&&pos!=2) return 4;
	else if((pos==2)&& (a[n]+2)%4==0)return 4;
	else return 3;
}

int check(int n,int left,int right){
	//cout<<n<<"\n";
	if(n == cnt) return 0;
	int& ret = v[n][left][right];
	if(ret!=-1) return ret;
	ret = 1e6;
	ret = min(ret,check(n+1,a[n],right)+go(n,left));
 	ret = min (ret,check(n+1,left,a[n])+go(n,right));
	return ret;
}
 

int main(){
	
	while(true){
		int temp;
		cin>>temp;
		if(temp==0) break;
		else{
			a[cnt] = temp;
		}
		cnt++;
	}
	memset(v,-1,sizeof(v));
	power = check(0,0,0);
	
	cout<<power;
	return 0;
}
