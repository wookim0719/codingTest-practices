#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n;
    cin >> n;
    
    priority_queue<int> minHeap; // 최대 힙
    priority_queue<int, vector<int>, greater<int>> maxHeap; // 최소 힙
    
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        
        if (minHeap.empty() || temp <= minHeap.top()) {
            minHeap.push(temp);
        } else {
            maxHeap.push(temp);
        }
        
        // 균형 조정
        if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        } else if (maxHeap.size() > minHeap.size()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        
        // 중간값 출력
            cout << minHeap.top() << "\n";
        
    }
    
    return 0;
}

