#include <iostream>
#include <queue>
#include <deque>

using namespace std;

typedef pair<int, int> pii;

int T, k;
priority_queue<pii> max_pq;
priority_queue<pii, vector<pii>, greater<pii>> min_pq;
int visited[1000000];

void operation() {
    char op;
    int n;

    cin >> k;
    
    for (int i = 0; i < k; i++) {
        cin >> op >> n;

        if (op == 'I') {
            max_pq.push({n, i});    // 숫자, i번 째에 넣은 수
            min_pq.push({n, i});

            visited[i] = true;
        }
        else if (op == 'D' && n == 1) {     // 최댓값 제거
            while (!max_pq.empty() && !visited[max_pq.top().second]) {
                // 이미 죽은거면 제거
                max_pq.pop();
            }

            if (!max_pq.empty()) {
                visited[max_pq.top().second] = false;
                max_pq.pop();
            }
        }
        else if (op == 'D' && n == -1) {     // 최솟값 제거
            while (!min_pq.empty() && !visited[min_pq.top().second]) {
                // 이미 죽은거면 제거
                min_pq.pop();
            }

            if (!min_pq.empty()) {
                visited[min_pq.top().second] = false;
                min_pq.pop();
            }
        }
    }
    
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int t = 0; t < T; t++) {
        max_pq = priority_queue<pair<int,int>>();
        min_pq = priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>();

        // 연산
        operation();

        // 죽은거 제거
        while (!max_pq.empty() && !visited[max_pq.top().second]) {
            max_pq.pop();
        }

        while (!min_pq.empty() && !visited[min_pq.top().second]) {
            min_pq.pop();
        }

        // 출력
        if (min_pq.empty() && max_pq.empty()) {
            cout << "EMPTY\n";
        }
        else {
            cout << max_pq.top().first << " " << min_pq.top().first << "\n";
        }
    }

    return 0;
}