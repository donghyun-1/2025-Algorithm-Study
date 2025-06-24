// https://www.acmicpc.net/problem/12891
// DNA 비밀번호 (실버 2)
// 2025-06-23

#include <iostream>
#include <vector>

using namespace std;

int S, P;
string s;
vector<int> v;
vector<int> cnt;
int ans = 0;


void input() {
    cin >> S >> P;
    cin >> s;

    v.resize(4);    // 조건
    cnt.resize(4);

    for (int i = 0; i < 4; i++) {
        cin >> v[i];
    }
}

void add(char c) {
    if (c == 'A') {
        cnt[0]++;
    }
    else if (c == 'C') {
        cnt[1]++;
    }
    else if (c == 'G') {
        cnt[2]++;
    }
    else if (c == 'T') {
        cnt[3]++;
    }
}

void del(char c) {
    if (c == 'A') {
        cnt[0]--;
    }
    else if (c == 'C') {
        cnt[1]--;
    }
    else if (c == 'G') {
        cnt[2]--;
    }
    else if (c == 'T') {
        cnt[3]--;
    }
}

void check() {
    for (int i = 0; i < 4; i++) {
        if (v[i] > cnt[i]) return;
    }

    ans++;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    // 슬라이딩 윈도우 초기
    for (int i = 0; i < P; i++) {
        add(s[i]);
    }

    check();

    // 슬라이딩 윈도우
    for (int i = 1; i <= S-P; i++) {
        // 왼쪽 제거
        del(s[i-1]);

        // 오른쪽 추가
        add(s[i+P-1]);

        check();
    }

    cout << ans;

    return 0;
}