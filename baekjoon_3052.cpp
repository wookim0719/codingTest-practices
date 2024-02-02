
#include<bits/stdc++.h>
using namespace std;

int a[10];
int main(){


for (int i = 0; i < 10; ++i) {
        cin >> a[i];
        a[i] = a[i] % 42; // 각 원소를 42로 나눈 나머지를 저장
    }
	
	set<int>mySet(a,a+10);
	

	cout<< mySet.size();
	return 0;
}


