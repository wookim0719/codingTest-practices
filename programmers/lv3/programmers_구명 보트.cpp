#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    // ������� �����Ը� ����
    sort(people.begin(), people.end());
    
    int left = 0; // ���� ������ ����� �ε���
    int right = people.size() - 1; // ���� ���ſ� ����� �ε���
    int boats = 0;

    while (left <= right) {
        // ���� ������ ����� ���� ���ſ� ����� �Բ� �¿� �� �ִ��� Ȯ��
        if (people[left] + people[right] <= limit) {
            // �Բ� �¿� �� �ִٸ� �� ��� ��� �¿�
            left++;
            right--;
        } else {
            // �Բ� �¿� �� ���ٸ� ���� ���ſ� ����� �¿�
            right--;
        }
        boats++; // ��Ʈ�� ��� Ƚ�� ����
    }

    return boats; // �� ��Ʈ ��� Ƚ�� ��ȯ
}

