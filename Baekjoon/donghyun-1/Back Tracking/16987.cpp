// https://www.acmicpc.net/problem/16987
// 계란으로 계란치기 (골드 5)
// 2025-08-23

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int N;
vector<pii> egg(8);  // {life, weight}
int ans = 0;

void input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> egg[i].first >> egg[i].second;
    }
}

void backtracking(int idx, vector<pii>& temp_egg) {
    if (idx == N) {
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (temp_egg[i].first <= 0) {
                count++;
            }
        }

        ans = max(ans, count);
        return;
    }

    // 손에 든 계란 깨져있는 경우 넘어가기
    if (temp_egg[idx].first <= 0) {
        backtracking(idx+1, temp_egg);
        return;
    }

    bool hit = false;

    for (int i = 0; i < N; i++) {
        if (i == idx || temp_egg[i].first <= 0) continue;

        pii curr = temp_egg[idx];
        pii next = temp_egg[i];

        hit = true;

        // 계란 깨기
        temp_egg[idx].first -= next.second;
        temp_egg[i].first -= curr.second;

        backtracking(idx+1, temp_egg);

        temp_egg[idx].first += next.second;
        temp_egg[i].first += curr.second;
    }

    // 깰 계란 없음
    if (!hit) {  
        // 칠 대상이 없으면 그냥 다음으로
        backtracking(idx+1, temp_egg);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    backtracking(0, egg);

    cout << ans;

    return 0;
}