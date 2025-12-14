// https://www.acmicpc.net/problem/22856
// 트리 순회 (골드 4)
// 2025-11-24

#include <iostream>

using namespace std;

struct Node{
    int left;
    int right;
};

    
Node node[100001];
int parent[100001]; // 각 노드의 부모 정보
bool visited[100001]; // 노드 방문 확인
int ans = 0;
int N;
int endNode; // 마지막 노드의 번호
bool endFlag = false; // 재귀함수를 끝내는 플래그


// 가장 오른쪽에 있는 노드의 번호를 찾음
int findEnd(int top){
    if (node[top].right == -1) return top;
    return findEnd(node[top].right);
}

// 중위 순회 재귀함수
void solution(int x, bool first){
    if (endFlag) return;
    
    // 왼쪽 자식 노드가 없거나 방문하지 않으면 해당 노드 재귀X
    if (node[x].left != -1 && !visited[node[x].left]) {
        ans++;
        solution(node[x].left, false);
    }
    if (endFlag) return;
    // 오른쪽 자식 노드가 없거나 방문하지 않으면 해당 노드 재귀X
    if (node[x].right != -1 && !visited[node[x].right]){
        ans++;
        solution(node[x].right, false);
    }

    if (endFlag) return;
    
    // 해당 노드가 마지막 노드임을 체크
    if (x == endNode) {
        endFlag = true;
        return;
    }
    // 해당 노드가 루트 노드가 아니면 이동횟수 +1
    if (!first) ans++;
    visited[x] = true;
}

int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
    	// 왼쪽 자식 노드, 오른쪽 자식 노드, 자기 자신
        int left, right, cnt;
        cin>> cnt >> left >> right;

        // 왼쪽 자식 노드가 존재하면 자기 자신을 왼쪽 자식 노드 부모로 설정
        if (left != -1) 
			parent[left] = cnt;
        
        // 오른쪽 자식 노드가 존재하면 자기 자신을 오른쪽 자식 노드 부모로 설정
        if (right != -1) 
			parent[right] = cnt;
        node[cnt] = {left,right};
    }

    endNode = findEnd(1);
    solution(1, true);

    if (N == 1) cout << "0";
    else cout << ans;
}