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
			//map에 요소 저장한다. 
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
		// 경우의 수를 계산해서 출력한다 
		//각각의 타입의 수에서 다 안 입는 경우인 1만큼 뺴준다 
		for(auto k : dict){
			total = total*(k.second+1);
		} 
		result[i] = total-1;
		total =1;
		dict.clear();
		//map을 초기화해준다. 
	}
	
	for(int i=0; i<num; i++){
		cout<< result[i]<<"\n";
	}
	return 0;
}
