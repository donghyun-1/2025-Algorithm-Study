// https://www.acmicpc.net/problem/1946
// 신입 사원 (실버 1)
// 2025-07-17

/* 
    <접근 방법>
    [1] 
    pair<서류, 면접> 점수 입력

    [2]
    first 값을 기준으로 정렬

    [3]
    0번 인덱스 second 값을 기준으로 각 second 값 비교
    만약 이전 기준보다 값이 더 작다면, 더 잘 봤다는 의미기 때문에 뽑힘 (cnt++) + 기준을 현재 second 값으로 갱신 
    하지만 더 크다면 서류, 면접 순위 전부 이전 지원자보다 뒤쳐지기 때문에 탈락
*/

#include <iostream>
#include <algorithm>

using namespace std;

int N;
pair<int, int> arr[100001];

void input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin>> T;

    for (int t = 0; t < T; t++) {
        // 입력
        input();

        // first 기준으로 정렬
        sort(arr, arr + N);
        
        // 비교
        int pivot = arr[0].second;
        int cnt = 1;

        for (int i = 1; i < N; i++) {
            if (pivot > arr[i].second) {
                cnt++;
                pivot = arr[i].second;
            }
        }

        // 출력
        cout << cnt << "\n";
    }

    return 0;
}