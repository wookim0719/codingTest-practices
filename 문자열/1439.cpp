#include <iostream>
using namespace std;
string s;
int main() {
    cin>>s;
    int cnt=0;
    int cnt2=0;
    char temp =s[0];
    for(int j=1; j<s.size(); j++){
        char i= s[j];
        if(temp==i){
            continue;
        }
        else{
            if(temp=='0') {
                cnt++;
                temp = i;
            }
            else{
             cnt2++;
            temp = i;
            }
        }
    }
     if(temp=='0') {
                cnt++;
            }
            else{
             cnt2++;
            }
    cout<<min(cnt,cnt2);
    return 0;
}