#include <bits/stdc++.h>
using namespace std;
int main(){
	int num;
	cin>>num;
	int M;
	cin>> M;
	int total =0;
	vector<int> arr(15001);
	for(int i=0; i<num; i++){
		int temp;
		cin >> temp;
		arr[i] = temp;
	}
	//2���� ������ ã�Ƽ� �� ������ ���� M�̸� ��ȯ  
	for(int i=0; i<num; i++){
		for(int j=i+1; j<num; j++){
			  if(arr[i]+ arr[j] == M){
			  	total++;
			  }
		}
	}
	cout<<total<<"\n";
	return 0;
}
