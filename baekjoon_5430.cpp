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
 		// , �϶����� �׳� �־��ְ� ���ڸ� 10�� ���ؼ� ���� ������.  
 			 if(x>0) D.push_back(x);
			 x=0;
		 }
	 }
	 		 		if(x > 0) D.push_back(x);
	  bool error = false, rev = false;
 		for(char a : s){
 			if(a == 'R') rev = !rev; 
 			else{
                // ����ִµ� �����Ϸ� �ϸ� ����
                if(D.empty()){
                    error = true;
                    break;
                }
                if(rev) D.pop_back();
                else D.pop_front(); 
			}
		}  
	  // ������ �߻��� ���
        if(error) cout << "error" << '\n';
        // �ƴ� ��� ���� ���Ҹ� �ϳ��ϳ� ���
        else{
        	cout << "["; 
            // ���� ������ ���¸� ��¥�� ������ �ش�.
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
