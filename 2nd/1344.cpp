#include<bits/stdc++.h>
using namespace std;
double a,b;
int n[12]={0,1,4,6,8,9,10,12,14,15,16,18};
double dp[20][20][20];



double go(int num,int cnta, int cntb){
	if(num==18){
		bool flag1=false;
		bool flag2=false;
		for(auto i:n){
			if(i==cnta) flag1=true;
			if(i==cntb) flag2=true;
		}
		if(flag1&&flag2) return 1;
		else return 0;
	}
	double &ret= dp[num][cnta][cntb];
	if(ret>-0.5) return ret;
	ret=0;
	ret +=go(num+1,cnta+1,cntb+1)*a*b;
	ret +=go(num+1,cnta+1,cntb)*a*(1-b);
	ret +=go(num+1,cnta,cntb+1)*(1-a)*b;
	ret +=go(num+1,cnta,cntb)*(1-a)*(1-b);
	return ret;
}



int main(){
	cin>>a>>b;
	a= a/100;
	b= b/100;
	memset(dp, -1, sizeof(dp));
	double res= go(0,0,0);

	printf("%.6lf",1-res);	
	return 0;
}
