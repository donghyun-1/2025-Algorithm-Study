// https://www.acmicpc.net/problem/1197
// 최소 스패닝 트리 (골드 4)
// 2025-07-29

/* 
    <풀이 과정 요약>

    [1] 간선 정보를 입력받고, 가중치 기준으로 정렬한다.

    [2] Union-Find(Disjoint Set)를 초기화한다.
        - find(x): 대표 노드(최상위 부모)를 찾으며, 경로 압축 적용
        - union(a, b): 대표 노드가 다르면 하나로 합침

    [3] Kruskal 알고리즘 수행:
        - 가중치가 낮은 간선부터 순회
        - find로 두 정점이 같은 집합인지 확인 (사이클 방지)
        - 다르면 union 수행 후 해당 간선을 MST에 포함
        - 간선 개수가 V - 1개가 되면 종료

    [4] 최종 가중치 출력
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;

    bool operator<(const Edge& other) {
        return weight < other.weight;
    }
};

int V, E;
int parent[10001];
vector<Edge> edges;

void input() {
    cin >> V >> E;

    int A, B, C;
    for (int i = 0; i < E; i++) {
        cin >> A >> B >> C;

        edges.push_back({A, B, C});
    }
}

// 경로 압축 (제일 위에 있는 조상 찾기)
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

// union (집합 합치기)
void unionParent(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        parent[b] = a;
    }
}

int kruskal() {
    int mst_weight = 0;
    int cnt = 0;

    for (const auto& edge : edges) {
        if (find(edge.u) != find(edge.v)) { // 조상 다르면(사이클 안생기면)
            unionParent(edge.u, edge.v);    // 합치기
            mst_weight += edge.weight;
            cnt++;
            if (cnt == V - 1) break;
        }
    }

    return mst_weight;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    input();

    // 초기 부모는 자기 자신
    for (int i = 1; i <= V; i++) {
        parent[i] = i;
    }

    // 정렬 (가중치 오름차순)
    sort(edges.begin(), edges.end());

    // 크루스칼
    cout << kruskal(); 

    return 0;
}