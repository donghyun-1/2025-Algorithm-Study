// https://www.acmicpc.net/problem/1717
// 집합의 표현 (골드 5)
// 2025-07-19

/* 
    <접근 방법>
    [1]
    입력 받은 후
    대표 노드를 자기 자신으로 초기화

    [2]
    0번 연산 시 union-find 사용해서 대표 노드가 같은지 확인하고 다르다면 대표 노드 같게 만들기
    1번 연산 시 find로 대표 노드 같은지 확인 후 같으면 YES 다르면 NO 출력
*/

#include <iostream>

using namespace std;

int parent[1000001];

// 대표 노드 찾기
int find(int a) {
    if (a == parent[a]) {
        return a;
    }
    else {
        return parent[a] = find(parent[a]);
    }
}

// 집합 연결하기
void union_func(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        parent[b] = a;
    }
}

// 대표 노드 같은지 확인
bool check(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return true;

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    int op, a, b;
    for (int i = 0; i < m; i++) {
        cin >> op >> a >> b;

        if (op == 0) {
            union_func(a, b);
        }
        else if (op == 1) {
            if (check(a, b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}