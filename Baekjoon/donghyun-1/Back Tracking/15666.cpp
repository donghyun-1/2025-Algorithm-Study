// https://www.acmicpc.net/problem/15666
// N과 M (12) (실버 2)
// 2025-10-09

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;

void solve(int start, vector<int>& temp) {
    if (temp.size() == M) {
        for (int i = 0; i < M; i++) {
            cout << temp[i] << " ";
        }
        cout << "\n";
        return;
    }

    int prev = -1;  // 이전에 사용한 값을 저장 (중복 방지용)
    for (int i = start; i < N; i++) {
        if (prev == arr[i]) continue;  // 같은 depth에서 중복 값 건너뜀
        prev = arr[i];

        temp.push_back(arr[i]);
        solve(i, temp);   // i부터 → 같은 수 다시 선택 가능 (중복 조합)
        temp.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    arr.resize(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    vector<int> v;
    solve(0, v);

    return 0;
}
