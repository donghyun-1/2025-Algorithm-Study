// https://www.acmicpc.net/problem/1931
// 회의실 배정 (골드 5)
// 2025-08-20

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int ans = 0;
vector<pair<int, int>> v;

void input() {
    cin >> N;

    int a, b;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }
}

bool compare(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    // 끝나는 시간 기준으로 정렬
    sort (v.begin(), v.end(), compare);

    int last_time = 0;

    for (int i = 0; i < N; i++) {
        if (v[i].first >= last_time) {
            last_time = v[i].second;
            ans++;
        }
    }

    cout << ans;

    return 0;
}