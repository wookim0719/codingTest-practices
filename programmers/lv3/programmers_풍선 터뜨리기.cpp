#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> a) {
    int n= a.size();
    int pos;
    int ret=987654321;
    for(int i=0; i<n; i++){
        if(a[i]<ret){
            ret=a[i];
            pos=i;
        }
    }
    stack<int> stk;
    for(int i=pos-1; i>=0; i--){
       while(stk.size()){
          if(stk.top()>a[i]){
              stk.pop();
          }
           else {
               break;
           }
       }
        stk.push(a[i]);
    }
        stack<int> stk2;
    for(int i=pos+1; i<n; i++){
       while(stk2.size()){
          if(stk2.top()>a[i]){
              stk2.pop();
          }
           else {
               break;
           }
       }
        stk2.push(a[i]);
    }
    
    int answer = stk.size()+stk2.size();
    return answer+1;
}
