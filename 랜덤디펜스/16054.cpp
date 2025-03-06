#include <bits/stdc++.h>
using namespace std;
int n, m;
map<string, vector<string>> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    cin.ignore(); // 입력 버퍼 비우기

    string fixed = " are worse than "; 

    // 입력 받기
    for (int i = 0; i < n; i++) {
        string temp;
        getline(cin, temp); // 공백 포함 입력 받기
        size_t pos = temp.find(fixed);
        
        if (pos == string::npos) continue; // 고정 문구가 없으면 넘어감
        
        string first = temp.substr(0, pos);
        string second = temp.substr(pos + fixed.length());
        
        mp[first].push_back(second);
    }

    // 쿼리 처리
    while (m--) {
        string res = "";
        string temp;
        getline(cin, temp); 
        size_t pos = temp.find(fixed);
        if (pos == string::npos) {
            cout << "pants on Fire\n";
            continue;
        }

        string first = temp.substr(0, pos);
        string second = temp.substr(pos + fixed.length());

        // 1. Fact 체크
        bool found = false;
            queue<string> q;
            map<string, bool> visited;

            q.push(first);
            visited[first] = true;
            
            while (!q.empty()) {
                string cur = q.front();
                q.pop();

                if (cur == second) {
                    res = "Fact";
                    found = true;
                    break;
                }

                for (string next : mp[cur]) {
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
        if(!found){
            queue<string> q2;
            map<string, bool> visited2;

            q2.push(second);
            visited2[second] = true;
            
            while (!q2.empty()) {
                string cur = q2.front();
                q2.pop();

                if (cur == first) {
                    res = "Alternative Fact";
                    found = true;
                    break;
                }

                for (string next : mp[cur]) {
                    if (!visited2[next]) {
                        visited2[next] = true;
                        q2.push(next);
                    }
                }
            }
        }
        // 3. pants on Fire
        if (res.empty()) res = "pants on Fire";

        cout << res << "\n";
    }

    return 0;
}
