#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        multiset<int> ms;  // multiset을 사용하여 자동 정렬
        int k;
        cin >> k;
        
        while(k--) {
            string cmd;
            int num;
            cin >> cmd >> num;
            
            if(cmd == "I") {
                ms.insert(num);
            }
            else if(cmd == "D" && !ms.empty()) {
                if(num == 1) {
                    // 최댓값 삭제
                    auto it = ms.end();
                    --mu;
                    ms.erase(it);
                }
                else {
                    // 최솟값 삭제
                    ms.erase(ms.begin());
                }
            }
        }
        
        if(ms.empty()) {
            cout << "EMPTY\n";
        }
        else {
            auto it = ms.end();
            --it;
            cout << *it << " " << *ms.begin() << "\n";
        }
    }
    return 0;
}
