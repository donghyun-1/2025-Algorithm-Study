// https://www.acmicpc.net/problem/11279
// 최대 힙 (실버 2)
// 2025-08-19

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int> pq;

    int N;
    cin >> N;

    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;

        if (num == 0 && pq.empty()) {
            cout << "0\n";
        }
        else if (num == 0) {
            cout << pq.top() << "\n";
            pq.pop();
        }
        else {
            pq.push(num);
        }
    }

    return 0;
}