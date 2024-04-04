#include<bits/stdc++.h>
using namespace std;

int n, score,p;
vector<int> a;
int cnt=1;

bool compare(int a, int b) {
    return a > b; 
}
int main(){
	cin>>n>>score>>p;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		a.push_back(temp);
	}
	sort(a.begin(), a.end(),compare);
	for(int i=0; i<n; i++){
		if(a[i]>score) cnt++;
		if(a[i]==score&& i==p-1) cnt= p+1;
}
	if(cnt>p) cout<<-1;
	else
	cout<<cnt;
	return 0;
}
