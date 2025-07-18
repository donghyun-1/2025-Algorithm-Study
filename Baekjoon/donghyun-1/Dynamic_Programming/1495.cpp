// https://www.acmicpc.net/problem/1495
// 기타리스트 (실버 1)
// 2025-07-15 

/* 
    <접근 방법>
    [1] 
    N, S, M 입력 / V 입력
    2차원 dp벡터 생성 (dp[i][0~M] = i 번째 곡 볼륨 ?일 때 true / false)

    [2]
    이전 볼륨에서 -V[i] / +V[i] 한 값이 0 이상 M 이하면 true 처리

    [3]
    마지막 곡에서 true인 값 중 최대 볼륨 출력
*/

#include <iostream>
#include <vector>

using namespace std;

int N, S, M;
vector<int> V;
vector<vector<bool>> dp;

void input() {
    cin >> N >> S >> M;

    V.resize(N);
    dp.resize(N, vector<bool>(M+1, false));
    

    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }
}

void solution() {
    // 초기 설정
    if (S - V[0] >= 0) dp[0][S-V[0]] = true;
    if (S + V[0] <= M) dp[0][S+V[0]] = true;

    // 경우의 수 계산
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= M; j++) {
            if (dp[i-1][j]) {
                if (j - V[i] >= 0) dp[i][j-V[i]] = true;
                if (j + V[i] <= M) dp[i][j+V[i]] = true;
            }
        }
    }
}

void print() {
    for (int i = M; i >= 0; i--) {
        if (dp[N-1][i]) {
            cout << i;
            return;
        }
    }

    cout << -1;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    input();

    // dp 계산
    solution();

    // 결과 출력;
    print();

    return 0;
}