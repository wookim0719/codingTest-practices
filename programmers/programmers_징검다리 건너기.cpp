#include <string>
#include <vector>

using namespace std;
vector<int> v;
int ret=0;
int k;

bool check(int value){
    bool flag= true;
    int cnt=0;
    for(int i=0; i<v.size(); i++){
        if(v[i]-value<=0){
            cnt++;
            if(cnt>=k) return false;
        }
        else{
            cnt=0;
        }
    }
    if(cnt>=k) return true;
    else return true;
}
int solution(vector<int> stones, int kk) {
    v= stones;
    k=kk;
    int answer = 0;
    int s=0;
    int e=200000000;
    
    while(s<=e){
        int mid = (s+e)/2;
        if(check(mid)){
           s=mid+1;
           ret= max(ret,mid); 
        }
        else{
            e= mid-1;
        }
    }
    answer= ret;
    return answer+1;
}
