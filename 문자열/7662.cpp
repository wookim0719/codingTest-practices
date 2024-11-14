#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        multiset<int> ms;  // multiset�� ����Ͽ� �ڵ� ����
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
                    // �ִ� ����
                    auto it = ms.end();
                    --mu;
                    ms.erase(it);
                }
                else {
                    // �ּڰ� ����
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
