#include <bits/stdc++.h>
using namespace std;
int n,x,N;
int main(){
 cin>>n;
 
 for(int t=0; t< n; t++){
 	string s;
 	string order;
 	deque<int> D;
 	cin>>s>>N>>order;
 	x=0;
 	for(char c:order){
 		if(c == '[' || c == ']') continue;
 		if(c>='0' && c<= '9') x= x*10 + c-'0';
 		else{
 		// , 일때에는 그냥 넣어주고 숫자면 10을 곱해서 값을 굴린다.  
 			 if(x>0) D.push_back(x);
			 x=0;
		 }
	 }
	 		 		if(x > 0) D.push_back(x);
	  bool error = false, rev = false;
 		for(char a : s){
 			if(a == 'R') rev = !rev; 
 			else{
                // 비어있는데 제거하려 하면 에러
                if(D.empty()){
                    error = true;
                    break;
                }
                if(rev) D.pop_back();
                else D.pop_front(); 
			}
		}  
	  // 에러가 발생한 경우
        if(error) cout << "error" << '\n';
        // 아닐 경우 덱의 원소를 하나하나 출력
        else{
        	cout << "["; 
            // 덱이 뒤집힌 상태면 진짜로 뒤집어 준다.
            if(rev) reverse(D.begin(), D.end());
            for(int i = 0; i < D.size(); i++){
        		cout << D[i];  
                if(i < D.size()-1) cout << ",";
            }
        	cout << "]\n";  
        }

 }
 return 0;
	
}
