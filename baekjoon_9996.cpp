#include<bits/stdc++.h>
using namespace std;

int main(){
	int num;
	// ���ϸ��� �����ϴ� ����  
	string pattern; 
	int position;
	// ����� ������ ���Ϳ� �����ϴ� ���� 
    string output[100];
	cin>> num;  
	cin>> pattern;
	for(int i=0; i<pattern.size(); i++){
		if((int)pattern[i] == 42)
		position = i;
	}
	
	// �� num���� �Է��� �޾� ���� 
	for(int i=0; i<num; i++){
		string a;
		cin >> a;
		output[i]="DA";
		
		if(pattern.size()-1>a.size()){
			output[i]="NE";
		}

		// * �� ��ġ�� ������ ������ ���Ѵ� 
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
