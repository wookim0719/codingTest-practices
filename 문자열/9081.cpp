#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// ����� ���� �ȿ� ���ڸ� �迭�ϴ� �Լ�
// size : �迭 ũ��, idx : ����� ���� ���� �տ� �ִ� �� �ε���
void findNextWord(char word[], int size, int idx){

    // ���ڰ� 2�����
    if(size <= 2) {
        // �׳� ������ ����
        reverse(word,word+size);
        cout << word << "\n";
        return;
    }

    // �� �� ���� �ٲٱ�
    char key = word[idx];
    int changeWord = 9999; // ���� ���� ��µǱ� ����

    int select = idx; // ���õ� ��ġ �ε���

    for(int i = idx+1; i < size; i++){
        // ����� ���� �� �տ� ���� ���ų� ���� ��� ����
        if(word[i] <= key) continue;

        // ���� ���� ���� ����
        if(word[i] < changeWord){
            changeWord = word[i];
            select = i;
        }
    }

    // �� ���� ��ȯ
    word[idx] = word[select];
    word[select] = key;

    // �� ���� �����ϰ� ��������
    sort(word+idx+1,word+size);

    // ���
    for(int i = 0; i < size; i++) printf("%c",word[i]);
    printf("\n");
}
int main(){
    int T;
    cin >> T;

    while(T--){
        string word; // �Է¹��� �ܾ�
        cin >> word;
        bool isChange = false; // �����ƴ��� üũ
        int size = word.size();
        char arr[size];
        for(int i = 0; i < size; i++) arr[i] = word[i];

        // �� �ε������� ��Ž��
        for(int i = size-2; i >= 0; i--){

            // ���������� ���� �ε����� ã���� �ش� �ε�������
            // findNextWord �˰��� ����
            if(word[i] < word[i+1]){
                isChange = true;
                findNextWord(arr,size,i);
                break;
            }
        }
        // �� ������ �����ٸ�, ���� �״�� ���
        if(!isChange) cout << word << "\n";
    }
}
