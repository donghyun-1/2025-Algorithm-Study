// https://www.acmicpc.net/problem/30804
// 과일 탕후루 (실버 2)
// 2025-07-09

/* 
    <접근 방법>
    [1] 
    arrFruit에 탕후루 과일 전체 입력

    [2]
    투 포인터 사용하여 현재 범위 내 과일 개수 cnt (countFruit)
    동시에 서로 다른 과일 개수 cnt (diff)

    [3]
    서로 다른 과일 2개 이하면 최대 길이 비교 후 갱신
    최대 길이 출력
*/

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> countFruit(10, 0);      // 현재 꽂혀있는 과일 cnt
vector<int> arrFruit;               // 탕후루 과일 전체 입력

void input() {
    cin >> N;

    arrFruit.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arrFruit[i];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    // 투 포인터
    int left_idx = 0;
    int right_idx = 0;
    int max_f = 0;

    // 맨 처음
    countFruit[arrFruit[0]]++;
    int diff = 1;

    while (left_idx <= right_idx) {
        if (diff <= 2) {
            right_idx++;

            if (right_idx == N) break;
            
            // 새로운 과일 추가
            if (countFruit[arrFruit[right_idx]] == 0) {
                diff++;
            }
            countFruit[arrFruit[right_idx]]++;
        }
        else {
            countFruit[arrFruit[left_idx]]--;

            // 기존 과일 제거
            if (countFruit[arrFruit[left_idx]] == 0) {
                diff--;
            }

            left_idx++;
        }

        if (diff <= 2) {
            max_f = max(max_f, right_idx-left_idx+1);
        }
    }

    cout << max_f;

    return 0;
}