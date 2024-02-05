#include<bits/stdc++.h>
using namespace std;

int main()
{	
vector<int> time(100,0);
	vector<int> space(2);
	vector<int> fee(3);
	int second = 0;
	int max =0;
	int total = 0;
	// A. B, C를 받아오기 
	for(int i=0 ; i<3; i++){
		cin>> fee[i];
	}
	
	for(int i=0 ; i<3 ; i++){
		for(int j=0; j<2; j++){
			cin>> space[j];
			if(max<space[j])
			max = space[j];
		}
			for(int k=space[0]-1; k<space[1]-1; k++){
			time[k]++;
		}	
	}

	for(int i=0; i< max; i++){
		if(time[i]==1){
			total +=fee[0];
		}
		if(time[i]==2){
			total += fee[1]*2;
		}
		if(time[i]==3){
		 total += fee[2]*3;
		}
	}
	cout<< total;
 
	return 0;
	
}
