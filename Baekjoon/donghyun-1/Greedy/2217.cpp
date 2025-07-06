// https://www.acmicpc.net/problem/2217
// 로프 (실버 4)
// 2025-07-05

/* 
    <접근 방법>
    [1] 
    arr에 로프 N개 입력 후 오름차순 정렬
    
    [2]
    (정렬된 상태에서)
    로프 1개 쓸 때는 arr[N-1]이 최대 중량
    로프 2개 쓸 때는 arr[N-2] * 2가 최대 중량
    로프 3개 쓸 때는 arr[N-3] * 3이 최대 중량

    [3]
    따라서 로프 N개 쓸 때까지 전부 비교 후 출력
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> arr;

void input() {
    cin >> N;
    
    arr.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 오름차순 정렬
    sort(arr.begin(), arr.end());
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    int ans = 0;

    for (int i = 1; i <= N; i++) {
        int weight = arr[N-i] * i;

        ans = max(ans, weight);
    }

    cout << ans;
    
    return 0;
}