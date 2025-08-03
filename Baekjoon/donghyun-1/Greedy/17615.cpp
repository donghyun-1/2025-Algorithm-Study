// https://www.acmicpc.net/problem/17615
// 볼 모으기 (실버 1)
// 2025-08-01

#include <iostream>
#include <string>

using namespace std;

int N;
int ans = 500000;
string R;

void swap(int a, int b, string& s) {
    char temp = s[a];
    s[a] = s[b];
    s[b] = temp;
}

void moveRedRight() {
    string s = R;
    int cnt = 0;
    int pivot = -1;

    for (int i = N; i >= 0; i--) {
        if (pivot == -1 && s[i] == 'R') continue;   // 이미 옮김

        if (pivot == -1 && s[i] == 'B') pivot = i;
        else if (s[i] == 'R') {
            // 빨간색 옮기기
            swap(pivot, i, s);
            cnt++;
            pivot--;
        }
    }

    //cout << s << "\n";
    ans = min(ans, cnt);
}

void moveBlueRight() {
    string s = R;
    int cnt = 0;
    int pivot = -1;

    for (int i = N-1; i >= 0; i--) {
        if (pivot == -1 && s[i] == 'B') continue;   // 이미 옮김

        if (pivot == -1 && s[i] == 'R') pivot = i;
        else if (s[i] == 'B') {
            // 파란색 옮기기
            swap(pivot, i, s);
            cnt++;
            pivot--;
        }
    }

    //cout << s << "\n";
    ans = min(ans, cnt);
}

void moveRedLeft() {
    string s = R;
    int cnt = 0;
    int pivot = -1;

    for (int i = 0; i < N; i++) {
        if (pivot == -1 && s[i] == 'R') continue;   // 이미 옮김

        if (pivot == -1 && s[i] == 'B') pivot = i;
        else if (s[i] == 'R') {
            // 빨간색 옮기기
            swap(pivot, i, s);
            cnt++;
            pivot++;
        }
    }

    //cout << s << "\n";
    ans = min(ans, cnt);
}

void moveBlueLeft() {
    string s = R;
    int cnt = 0;
    int pivot = -1;

    for (int i = 0; i < N; i++) {
        if (pivot == -1 && s[i] == 'B') continue;   // 이미 옮김

        if (pivot == -1 && s[i] == 'R') pivot = i;
        else if (s[i] == 'B') {
            // 파란색 옮기기
            swap(pivot, i, s);
            cnt++;
            pivot++;
        }
    }

    //cout << s << "\n";
    ans = min(ans, cnt);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> R;

    // 빨간색 - 오른쪽으로 옮기기
    moveRedRight();

    // 파란색 - 오른쪽으로 옮기기
    moveBlueRight();

    // 빨간색 - 왼쪽으로 옮기기
    moveRedLeft();

    // 파란색 - 왼쪽으로 옮기기
    moveBlueLeft();

    // 정답 출력
    cout << ans;

    return 0;
}