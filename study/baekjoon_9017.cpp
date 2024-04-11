#include<bits/stdc++.h>
using namespace std;
int n;
int t[1001];
int a[1001];
int k[1001];
int h[201];
int y[201];
//int v[201];

int main(){
	cin>>n;
	while(n--){
		int output=987654321;
		int g=0;
		int num;
		cin>>num;
		vector<int> v;
		memset(k,0,sizeof(k));
		memset(a,0,sizeof(a));
		memset(y,0,sizeof(y));
		
	for(int i=0;i<num;i++){
		int temp;
		cin>>temp;
		t[i]=temp-1;
		a[temp-1]++;
		if(a[temp-1]==5) h[t[i]] = i;
	
	}
		
	for(int i =0; i<200;i++){
		if(a[i]>=6){
		v.push_back(i);
		}
	}	

	int num2=0;
	for(int i=0; i<num; i++){
		if(find(v.begin(), v.end(), t[i]) != v.end()){
			if(y[t[i]]!=4){
				k[t[i]]+=(num2+1);
				y[t[i]]++;
			}
				num2++;
		}
	}
	
	
	

	for(int i=0; i<200; i++){
		if(k[i]<output&&k[i]!=0){
				g=i+1;
				output= k[i];
		}	
		if(k[i]==output&&k[i]!=0){
			if(h[i]<h[g-1]){
				output= k[i];
				g= i+1;
			}
		}
	}
	cout<<g<<"\n";
	}
		
	return 0;
}
