#include <bits/stdc++.h>
using namespace std;

string s;
int n;
vector<string> v;
vector<bool> dp; // dp[i]는 s의 i번째 위치부터 끝까지 구성 가능한지 여부

int main() {
    cin >> s;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    dp.resize(s.size() + 1, false);
    dp[s.size()] = true; // 기저 조건: 끝에 도달하면 성공
    
    for(int i = s.size() - 1; i >= 0; i--) {
        for(int j = 0; j < n; j++) {
            if(i + v[j].size() <= s.size() && 
               s.substr(i, v[j].size()) == v[j] && 
               dp[i + v[j].size()]) {
                dp[i] = true;
                break;
            }
        }
    }
    
    cout << dp[0];
    
    return 0;
}