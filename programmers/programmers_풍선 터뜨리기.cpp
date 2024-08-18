#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
int ret;

int solution(vector<int> a) {
    int answer = 0;
    int min_v= 1000000001;
    int indexx=0;
    for(int i=0 ;i<a.size(); i++){
        if(min_v>a[i]){
            min_v=a[i];
            indexx=i;
        }
    }
    if(indexx!=a.size()-1){
    int s= indexx+1;
    stack<int> stk;
    stk.push(a[s]);
 
    while(stk.size()){
        s++;
        if(s>=a.size()) break;
        int t= stk.top();
        if(t>a[s]){
            while(stk.size()){
                int t= stk.top();
                if(t>a[s]) stk.pop();
                else break;
            }
        }
        stk.push(a[s]);
    }
    ret+=stk.size();
    cout<<stk.size()<<"\n";
    }
    if(indexx!=0){
    int s2= indexx-1;
    stack<int> stk2;
    stk2.push(a[s2]);
    while(true){
        s2--;
        if(s2<0) break;
        int t= stk2.top();
        if(t>a[s2]){
             while(stk2.size()){
                int t= stk2.top();
                if(t>a[s2]) stk2.pop();
                else break;
            }
        }
        stk2.push(a[s2]);
    }
    ret+=stk2.size();
    cout<<stk2.size()<<"\n";
    }
    answer= ret+1;
    
    return answer;
}
