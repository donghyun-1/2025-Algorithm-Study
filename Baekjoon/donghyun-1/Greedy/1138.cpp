// https://www.acmicpc.net/problem/1138
// 한 줄로 서기 (실버 2)
// 2025-07-08

/* 
    <접근 방법>
    [1] 
    arr에 주어진 조건 입력
    ans 전부 최대값으로 초기화

    [2]
    키가 1인 사람은 무조건 arr[0]의 값이 곧 자기 idx
    키가 2인 사람 ans[0]부터 끝까지 넣어보면서 자기보다 큰 사람이 앞에 몇 명있는지 check

    [3]
    조건 성립 시 그 자리에 삽입
*/

#include <iostream>
#include <vector>

#define INF 100

using namespace std;

int N;
vector<int> arr;
vector<int> ans;

void input() {
    cin >> N;

    arr.resize(N);
    ans.resize(N, INF);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    // 숫자 1은 무조건 arr[0]번 인덱스에 위치
    ans[arr[0]] = 1;

    for (int i = 1; i < N; i++) {
        int cnt = arr[i];   // 본인보다 큰 숫자 개수
        int num = i+1;      // 삽입 할 숫자

        for (int j = 0; j < N; j++) {
            // 앞에 본인보다 큰 수가 cnt개 있고, 비어있으면 삽입 
            if (ans[j] == INF && cnt == 0) {
                ans[j] = num;
                break;
            }

            // 본인보다 큰 숫자 count
            if (ans[j] > num && cnt != 0) {
                cnt--;
            }
        }
    }

    // 출력
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}