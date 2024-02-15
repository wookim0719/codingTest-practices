#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[101][101];

int main(){
	cin>>n>>m;
	for(int i=0; i<n; i++){
		string temp;
		cin>> temp;
		for(int j=0; j<m; j++){
			if(temp[j]=='c')
				arr[i][j] = 0;
			else
				arr[i][j] = -1;
		}
	}
	
	for(int i=0; i<n; i++){
		int temp = -1;
		for(int j=0; j<m; j++){
			if(arr[i][j]==0)
				temp= j;
			else{
				if(temp>-1)
				arr[i][j]=	j-temp;
			}	
			
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<< arr[i][j]<< " ";
		}
		cout<< "\n";
	}
	
	return 0;
	
}
