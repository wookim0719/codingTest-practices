#include<bits/stdc++.h>
using namespace std;
int h,w;
vector<int> v;
int ret=0;
deque<int> dq;

int main(){
	cin>>h>>w;
	for(int i=0; i<w; i++){
		int temp;
		cin>>temp;
		dq.push_front(temp);
	}
	int m=0;
	for(int i=0; i<w; i++){
		if(dq.front()<dq.back()){
			if(dq.front()>m)
			m=dq.front();
			else
			ret+=m-dq.front();
			dq.pop_front();
		}
		else{
			if(dq.back()>m)
			m=dq.back();
			else
			ret+=m-dq.back();
			dq.pop_back();
		}
		//cout<<m;
	}
	
	cout<<ret;
	return 0;
}

#include <iostream>
#include <vector>

int main() {
    int T;
    int N, M, K;
    int X, Y;
    int answer = 0;

    cin >> N >> M;
    vector<int> v(M);

    for (int i = 0; i < M; i++)
        cin >> v[i];

    for (int i = 1; i < M - 1; i++) {
        int left = 0; int right = 0;
        //���� �ִ� ��
        for (int j = 0; j < i; j++) left = max(left, v[j]);
        //������ �ִ� ��
        for (int j = M - 1; j > i; j--) right = max(right, v[j]);
        //���� ���
        answer += max(0, min(left, right) - v[i]);
    }

    cout << answer << endl;
    return 0;
}
 
