#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int maxV=0;
int minV= 987654321;
vector<int> v;
int jump;

bool check(int value){
   // cout<<value<<" ";
    int cnt =0;
    for(int i=0; i<v.size(); i++){
     // cout<<v[i]-value<<" ";
        if(v[i]-value+1<=0){
            cnt++;
            if(cnt>=jump){
               return false;
            }
        }
        else{
            cnt=0;
        }
    }
    cout<<"\n";
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    v= stones;
    for(int i: stones){
        maxV = max(maxV,i);   
        minV = min(minV,i);
    }
    jump = k;
    int s = minV;
    int e = maxV;
    while(s<=e){
        int mid = (s+e)/2;
        if(check(mid)){
            answer = max(answer,mid);
            s= mid+1;
        }
        else{
            e = mid-1;
        }
    }   
    return answer;
}
