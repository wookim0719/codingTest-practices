#include<bits/stdc++.h>
using namespace std;

vector<int> v(3);
string value;

int main(){
	
	while(1){
	//초기화 해준다. 
	v.clear(); 
	int a,b,c;
	cin>>a>>b>>c;
	if(a==0&& b==0&& c==0) break;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	//정렬을 하여 크기대로 저장 
	sort(v.begin(),v.end());
//	for(int it: v)
//	cout<<it<<"\n";
    if (v[2] >= (v[0] + v[1])) {
        value = "Invalid";
    }
    else if (v[0] == v[1] && v[1] == v[2]) { // 수정된 부분
        value = "Equilateral";
    }
    else if (v[0] == v[1] || v[1] == v[2] || v[0] == v[2]) {
        value = "Isosceles";
    }
    else {
        value = "Scalene";
    }
	
	cout<<value<<"\n";
	}
	
	
	return 0;
}
