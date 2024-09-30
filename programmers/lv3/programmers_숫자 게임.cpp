#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    queue<int> q1;
    queue<int> q2;
    for(int i=0; i<a.size(); i++){
        q1.push(a[i]);
    }    
    for(int i=0; i<b.size(); i++){
        q2.push(b[i]);
    }

    while(q1.size()){
    int f= q1.front();   
    q1.pop();
    while(q2.size()){
      int f2= q2.front();
        q2.pop();
        if(f2>f){
            answer++;
            break;
        }
    }
    }


    return answer;
}
