#include <bits/stdc++.h>
using namespace std;

int main(){
	int num;
	int cloth;
	cin>> num;
	int total =1;
	vector<int> result(100);
	for(int i=0; i<num; i++){
		map<string,int> dict;
		cin >> cloth;
		for(int j=0; j<cloth; j++){
			//map�� ��� �����Ѵ�. 
			string name;
			string type;
			cin>> name>> type;
			if(dict.find(type) != dict.end()){
				dict[type]++;
			//	cout<<dict[type]<<"\n";
			}
			else{
				dict[type]=1;
			//	cout<<dict[type]<<"\n";
			}
		}
		// ����� ���� ����ؼ� ����Ѵ� 
		//������ Ÿ���� ������ �� �� �Դ� ����� 1��ŭ ���ش� 
		for(auto k : dict){
			total = total*(k.second+1);
		} 
		result[i] = total-1;
		total =1;
		dict.clear();
		//map�� �ʱ�ȭ���ش�. 
	}
	
	for(int i=0; i<num; i++){
		cout<< result[i]<<"\n";
	}
	return 0;
}
