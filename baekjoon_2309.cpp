
#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> a(9);
	int total = 0;
	int value = 0;
	int search;
	
	for(int i=0; i<9; i++){
		cin>> a[i];
		total = total + a[i];
	}
	
	sort(a.begin(),a.end());
		
	value = total -100;
	
	for(int i=0; i<9; i++){
		search = value - a[i];
		for(int j=i+1; j<9; j++){
			if(search == a[j]){
				for(int k=0; k<9; k++){
					if(k != i && k != j){
						cout<< a[k] << "\n";
					}
				}
				exit(0);
			}
				
		}	
	}
	return 0;
	
} 
