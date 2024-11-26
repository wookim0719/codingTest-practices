#include <iostream>
#include <algorithm>
using namespace std;



char map[10000][10000]; // ���� ��� ��

// k = 0 �� �� �׸��� �׸��� ��(�ּ� ����)
void unit(int sx, int sy){
    map[sx][sy] = '*';
    map[sx+1][sy-1] = '*';
    map[sx+1][sy+1] = '*';
    for(int i = sy-2; i <= sy + 2; i++) map[sx+2][i] = '*';
}

// �߽���ǥ�� �������� �׸��� �׸�-> (sx,sy)��ǥ�� ���� len���� �׸�
void Draw(int sx, int sy, int len){
    // N = 3�̸� �ּҴ��� unit() ȣ��
    if(len == 3){
        unit(sx,sy);
        return;
    }
    // len < 3 �̸� �׳� return
    else if( len < 3) return;

    int halfX = len/2; // �������� ����
    int halfY = len/2; // �������� ����
    Draw(sx,sy,len/2); // �� ���� �ִ� �ﰢ��
    Draw(sx+halfX,sy-halfY,len/2); // ���� �ﰢ��
    Draw(sx+halfX,sy+halfY,len/2); // ������ �ﰢ��

}
int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int sy = (2*N-1)/2;
    fill(&map[0][0],&map[9999][10000],' ');
    Draw(0,sy,N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < 2*N-1; j++) cout << map[i][j];
        cout << "\n";
    }
}
