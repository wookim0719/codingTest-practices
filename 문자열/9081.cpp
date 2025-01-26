#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// 노란색 영역 안에 문자를 배열하는 함수
// size : 배열 크기, idx : 노란색 영역 가장 앞에 있는 수 인덱스
void findNextWord(char word[], int size, int idx){

    // 문자가 2개라면
    if(size <= 2) {
        // 그냥 뒤집고 끝냄
        reverse(word,word+size);
        cout << word << "\n";
        return;
    }

    // 맨 앞 문자 바꾸기
    char key = word[idx];
    int changeWord = 9999; // 작은 수가 출력되기 위함

    int select = idx; // 선택된 위치 인덱스

    for(int i = idx+1; i < size; i++){
        // 노란색 영역 맨 앞에 수와 같거나 작은 경우 제외
        if(word[i] <= key) continue;

        // 가장 작은 수를 선택
        if(word[i] < changeWord){
            changeWord = word[i];
            select = i;
        }
    }

    // 두 수를 교환
    word[idx] = word[select];
    word[select] = key;

    // 맨 앞을 제외하고 오름차순
    sort(word+idx+1,word+size);

    // 출력
    for(int i = 0; i < size; i++) printf("%c",word[i]);
    printf("\n");
}
int main(){
    int T;
    cin >> T;

    while(T--){
        string word; // 입력받은 단어
        cin >> word;
        bool isChange = false; // 수정됐는지 체크
        int size = word.size();
        char arr[size];
        for(int i = 0; i < size; i++) arr[i] = word[i];

        // 끝 인덱스부터 역탐색
        for(int i = size-2; i >= 0; i--){

            // 내림차순을 끊는 인덱스를 찾으면 해당 인덱스에서
            // findNextWord 알고리즘 시작
            if(word[i] < word[i+1]){
                isChange = true;
                findNextWord(arr,size,i);
                break;
            }
        }
        // 값 수정이 없었다면, 문자 그대로 출력
        if(!isChange) cout << word << "\n";
    }
}
