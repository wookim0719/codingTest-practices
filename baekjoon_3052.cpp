
#include<bits/stdc++.h>
using namespace std;

int a[10];
int main(){


for (int i = 0; i < 10; ++i) {
        cin >> a[i];
        a[i] = a[i] % 42; // �� ���Ҹ� 42�� ���� �������� ����
    }
	
	set<int>mySet(a,a+10);
	

	cout<< mySet.size();
	return 0;
}


