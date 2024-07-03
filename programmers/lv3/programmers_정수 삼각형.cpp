#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=501;

int dp[MAX][MAX];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    //�ʱ� ����.
    dp[0][0]=triangle[0][0];
    
    for(int i=1;i<triangle.size();i++){
        for(int j=0;j<=i;j++){
            //1) �࿡�� �� ������ ��쿣 �ٷ� ������
            if(j==0) dp[i][j]=dp[i-1][j]+triangle[i][j];
            //2) �࿡�� �� �������� ��쿣 ���� ������
            else if(j==i) dp[i][j]=dp[i-1][j-1]+triangle[i][j];
            //������
            else dp[i][j]=max(dp[i-1][j-1], dp[i-1][j])+triangle[i][j];
            
        }
    }
    for(int i=0; i<triangle.size(); i++){
        answer= max(answer,dp[triangle.size()-1][i]);
    }    
    return answer;
}
