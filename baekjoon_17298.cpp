#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1000001];
int ret[1000001];
stack<int> s;

int main(){
	cin>>n;
		memset(ret, -1, sizeof(ret));
	for(int i=0; i<n; i++){
		cin>> arr[i];
		while(s.size() && arr[i]>arr[s.top()]){
				ret[s.top()] = arr[i];
			s.pop();
		}
					s.push(i);
	}

	
	for(int i=0; i<n; i++){
		cout<< ret[i]<< " ";
	}
	return 0;
	
}
