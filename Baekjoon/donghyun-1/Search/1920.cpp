// https://www.acmicpc.net/problem/1920
// 수 찾기 (실버 4)
// 2025-06-13

#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, t;
    unordered_set<int> numSet;

    // 입력
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> t;
        
        numSet.insert(t);
    }

    // 찾기
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> t;

        if (numSet.find(t) == numSet.end()) {
            cout << "0\n";
        }
        else {
            cout << "1\n";
        }
    }

    return 0;
}