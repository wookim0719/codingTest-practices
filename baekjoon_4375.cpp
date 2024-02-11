#include <bits/stdc++.h>
using namespace std;
	int n;

int main(){
	while(scanf("%d", &n)!= EOF){
		int value =1, digit =1;
		while(true){
			if(value % n ==0){
				printf("%d\n", digit);
				break;
			}
			else{
				value = (value *10 )+1;
				value %= n;
				digit++;
			}
		}
	}
			return 0;

}
