#include<bits/stdc++.h>
using namespace std;

int main(){
	int num;
	// 파일명을 저장하는 변수  
	string pattern; 
	int position;
	// 출력할 값들을 벡터에 저장하는 변수 
    string output[100];
	cin>> num;  
	cin>> pattern;
	for(int i=0; i<pattern.size(); i++){
		if((int)pattern[i] == 42)
		position = i;
	}
	
	// 총 num번을 입력을 받아 저장 
	for(int i=0; i<num; i++){
		string a;
		cin >> a;
		output[i]="DA";
		
		if(pattern.size()-1>a.size()){
			output[i]="NE";
		}

		// * 가 위치한 곳까지 같은지 비교한다 
		for(int j=0; j<position; j++){
			if(pattern[j] != a[j]){
			output[i]="NE";
		}
		}
		for(int j=pattern.size()-1; j>position; j--){
			
			if(pattern[j] != a[a.size()-pattern.size()+j])
			output[i]="NE";
		}
		
		} 
	

	for(int i=0; i<num; i++){
		cout<< output[i];
		if(i!=num-1){
			cout<<"\n";
		}
	}
	
	
	return 0;
}
