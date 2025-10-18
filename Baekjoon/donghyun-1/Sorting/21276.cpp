// https://www.acmicpc.net/problem/21276
// 계보 복원가 호석 (골드 2)
// 2025-10-10

#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N, M;
vector<string> name;
vector<int> graph[1001];
map<string, int> familyIdx;
map<int, string> familyName;
int indegree[1001];
vector<string> ancestor;
vector<string> child[1001];

void input() {
	cin >> N;

	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		familyIdx[s] = i;
		familyName[i] = s;
		name.push_back(s);
	}

	cin >> M;
	string a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		indegree[familyIdx[a]]++;
		graph[familyIdx[b]].push_back(familyIdx[a]);
	}
}

// 조상 출력
void print_ancestor() {
	for (int i = 0; i < N; i++) {
		if (indegree[i] == 0) {
			ancestor.push_back(familyName[i]);
		}
	}

	sort(ancestor.begin(), ancestor.end());

	cout << ancestor.size() << "\n";
	for (int i = 0; i < ancestor.size(); i++) {
		cout << ancestor[i] << " ";
	}
	cout << "\n";
}

void topology_sort() {
	queue<int> q;

	// 조상 먼저 전부 push
	for (int i = 0; i < ancestor.size(); i++) {
		q.push(familyIdx[ancestor[i]]);
	}

	while(!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i];
			indegree[next]--;
			if (indegree[next] != 0) continue;

			child[curr].push_back(familyName[next]);
			q.push(next);
		}
	}

	for (int i = 0; i < N; i++) {
		sort(child[i].begin(), child[i].end());
	}
}

void print_child() {
	sort(name.begin(), name.end());

	for (int i = 0; i < N; i++) {
		string curr_name = name[i];
		cout << curr_name << " " << child[familyIdx[curr_name]].size() << " ";
		for (int j = 0; j < child[familyIdx[curr_name]].size(); j++) {
			cout << child[familyIdx[curr_name]][j] << " ";
		}
		cout << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	print_ancestor();

	topology_sort();

	print_child();

	return 0;
}