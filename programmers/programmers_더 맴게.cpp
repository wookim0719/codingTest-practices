#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;
priority_queue<int,vector<int>,greater<int>> pq;
int sum;

int solution(vector<int> scoville, int K) {
   
    int cnt= scoville.size();
    for(int i=0; i<cnt; i++){
        pq.push(scoville[i]);
    }
    int tryed=0;
    while(true){
        if(pq.top()>=K)break;
        if(cnt==1) {
            tryed=-1; 
            break;
        }
        int f= pq.top();
        pq.pop();
        int s= pq.top();
        pq.pop();
        int neww= f+2*s;
        pq.push(neww);
        cnt--;
        tryed++;
    }
    
    int answer = tryed;
    return answer;
}
