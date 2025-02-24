#include<bits/stdc++.h>

using namespace std;

pair<char,bool> str[101]; // ���� �ִ� ����

//���� ��� �Լ�
void printWord(string word){
    for(int i = 0; i < word.length(); i++){
				// �����ִ� �͸� ���
        if(str[i].second) cout << str[i].first;
    }
    cout << '\n';
}
// ����Լ�
void solution(int start, int end, string word){
//	cout<<start<<" "<<end<<"\n";
		// �ּ� �ε����� ù ������ 
    int minIdx = start;

    // �ּҰ� �ε��� ã��
    for(int i = start; i <= end; i++)
        if(str[minIdx].first > str[i].first) minIdx = i;
		
		// ����ġ ��
    str[minIdx].second = true;
    printWord(word);
		
		//�ּҰ� �ڿ� �ִ� ���ڿ�
    if(minIdx + 1 <= end) solution(minIdx+1,end,word);

		//�ּҰ� �տ� �ִ� ���ڿ�
    if(minIdx - 1 >= start) solution(start,minIdx-1,word);
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    string input;
    cin >> input;

    for(int i = 0; i < input.length(); i++) 
        str[i] = make_pair(input[i],false);

    solution(0,input.length()-1,input);

    return 0;
}
