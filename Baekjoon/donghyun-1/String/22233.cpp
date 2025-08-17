// https://www.acmicpc.net/problem/22233
// 가희와 키워드 (실버 3)
// 2025-08-09

#include <iostream>
#include <unordered_set>
#include <sstream>
#include <vector>

using namespace std;

int N, M;
unordered_set<string> keyword;

void input() {
    cin >> N >> M;
    string s;

    for (int i = 0; i < N; i++) {
        cin >> s;
        keyword.insert(s);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;

        stringstream ss(s);
        string token;
        vector<string> result;

        while (getline(ss, token, ',')) {  // 구분자 ',' 기준으로 잘라냄
            result.push_back(token);
        }

        for (int i = 0; i < result.size(); i++) {
            if (keyword.find(result[i]) != keyword.end()) {     // 있으면 삭제
                keyword.erase(result[i]);
            }
        }

        cout << keyword.size() << "\n";
    }

    return 0;
}