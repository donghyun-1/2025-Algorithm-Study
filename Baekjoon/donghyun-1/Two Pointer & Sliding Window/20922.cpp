// https://www.acmicpc.net/problem/20922
// 겹치는 건 싫어 (실버 1)
// 2025-07-04

/* 
    <접근 방법>
    [1]
    벡터 arr에 수열 입력
    
    [2]
    투 포인터 사용해서 idx 0번부터 right 1칸씩 이동 + cnt 변수에 현재 길이 저장 + ans 변수에 cnt 최댓값 저장
    중복은 unordered_map[num]에 지금까지 나온 num의 개수 저장하며 체크 (K개 이하 유지해야 함)
    K개 초과 시 K개 이하가 될 때까지 left 이동
    
    [3]
    ans 출력 (cnt 최댓값)
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, K;
vector<int> arr;
unordered_map<int, int> arr_map;

void input() {
    cin >> N >> K;

    arr.resize(N);

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

    // 투 포인터
    int left = 0;
    int right = 0;
    int cnt = 0;
    int ans = -1;

    while (left <= right) {
        if (right == N) break;

        // 중복 K개 이하면 right 이동
        if (arr_map[arr[right]] < K) {
            arr_map[arr[right]]++;
            cnt++;
            right++;
            ans = max(ans, cnt);
        }
        // K개 초과 시 left 이동
        else {
            cnt--;
            arr_map[arr[left]]--;
            left++;
        }
    }

    cout << ans;

    return 0;
}