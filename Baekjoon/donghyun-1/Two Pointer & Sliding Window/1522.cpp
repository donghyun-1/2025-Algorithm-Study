// https://www.acmicpc.net/problem/1522
// 문자열 교환 (실버 1)
// 2025-07-10

/* 
    <접근 방법>
    [1] 
    문자열 입력

    [2]
    a 개수 count -> 윈도우 길이 정하기 위해 (length)
    윈도우 안에 전부 a가 들어가 있으면 a가 모두 연속이라고 볼 수 있음

    [3]
    슬라이딩 윈도우 사용해서 문자열 처음부터 끝까지 검사 (원형으로도 체크)
    윈도우 안에 있는 b의 개수가 곧 바꾸는 횟수
    최소 횟수 갱신 (ans)

    [4]
    출력 (ans)
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = 1000;
    int length = 0;

    // 문자열 입력
    string s;
    cin >> s;

    // 윈도우 길이
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') length++;
    }

    // 슬라이딩 윈도우
    int left_idx = 0;
    int right_idx = left_idx + length - 1;

    while (1) {
        int cnt = 0;

        for (int i = left_idx; i <= right_idx; i++) {
            // b 개수 세기
            int idx = i % s.size();

            if (s[idx] == 'b') cnt++;
        }

        // 갱신
        ans = min(ans, cnt);

        // 윈도우 이동
        left_idx++;
        right_idx++;

        if (left_idx == s.size()) break;
    }

    cout << ans;

    return 0;
}