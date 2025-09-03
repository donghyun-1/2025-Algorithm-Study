// https://www.acmicpc.net/problem/10819
// 차이를 최대로 (실버 2)
// 2025-09-03

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<int> num;
bool used[9];
int ans = 0;

void input() {
    cin >> N;

    num.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
}

int calculate(vector<int> t) {
    int sum = 0;

    for (int i = 1; i < N; i++) {
        sum += abs(t[i-1] - t[i]);
    }

    return sum;
}

void backtracking(int start, vector<int>& temp) {
    if (temp.size() == N) {
        // 계산
        ans = max(ans, calculate(temp));
    }

    for (int i = 0; i < N; i++) {
        if (used[i]) continue;

        temp.push_back(num[i]);
        used[i] = true;

        backtracking(start + 1, temp);
        
        used[i] = false;
        temp.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    vector<int> v;
    backtracking(0, v);

    cout << ans;

    return 0;
}