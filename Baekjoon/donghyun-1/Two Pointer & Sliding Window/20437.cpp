// https://www.acmicpc.net/problem/20437
// 문자열 게임 2 (골드 5)
// 2025-07-30

/* 
    <풀이 과정 요약>

    [1] 테스트 횟수, 문자열, 문자 개수 입력

    [2] 문자 c가 몇 번째 인덱스에 있는지 positions에 저장

    [3] positions에 원소가 K개 이상 존재한다면:
        - 슬라이딩 윈도우로 길이 계산: positions[i + K - 1] - positions[i] + 1
        - 3번 조건은 가장 짧은 문자열 찾기
        - 4번 조건은 가장 긴 문자열 찾기

    [4] 정답 출력

    <추가>
    - 3번 조건도 결국 문자열의 첫 번째와 마지막 글자가 같은 경우임
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string W;
int K;

void input() {
    cin >> W >> K;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        input();

        int ans3 = 10001;
        int ans4 = -1;
        
        for (char c = 'a'; c <= 'z'; c++) {
            vector<int> positions;

            // 알파벳 c가 몇 번째 인덱스에 있는지 저장
            for (int i = 0; i < W.size(); i++) {
                if (W[i] == c) {
                    positions.push_back(i);
                }
            }

            // 알파벳 c가 K개 있는지 확인
            if (positions.size() < K) continue;

            for (int i = 0; i+K-1 < positions.size(); i++) {
                int start = positions[i];
                int end = positions[i+K-1];

                // 문자열 길이 구하기
                ans3 = min(ans3, end-start+1);      // 3번 조건
                ans4 = max(ans4, end-start+1);      // 4번 조건
            }
        }

        // 정답 출력
        if (ans3 == 10001 || ans4 == -1) cout << "-1\n";
        else cout << ans3 << " " << ans4 << "\n";
    }

    return 0;
}