#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    // 사람들의 몸무게를 정렬
    sort(people.begin(), people.end());
    
    int left = 0; // 가장 가벼운 사람의 인덱스
    int right = people.size() - 1; // 가장 무거운 사람의 인덱스
    int boats = 0;

    while (left <= right) {
        // 가장 가벼운 사람과 가장 무거운 사람을 함께 태울 수 있는지 확인
        if (people[left] + people[right] <= limit) {
            // 함께 태울 수 있다면 두 사람 모두 태움
            left++;
            right--;
        } else {
            // 함께 태울 수 없다면 가장 무거운 사람만 태움
            right--;
        }
        boats++; // 보트의 사용 횟수 증가
    }

    return boats; // 총 보트 사용 횟수 반환
}

