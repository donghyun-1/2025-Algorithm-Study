// https://www.acmicpc.net/problem/1339
// 단어 수학 (골드 4)
// 2025-08-25

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

int N;
vector<string> word;
unordered_map<char, int> alphabet;
long long sum = 0;

void input() {
    cin >> N;
    word.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> word[i];
    }
}

void cal_weight() {
    for (int i = 0; i < N; i++) {
        int w = 1;

        for (int j = word[i].size()-1; j >= 0; j--) {
            alphabet[word[i][j]] += w;

            w *= 10;
        }
    }
}

bool compare(const pair<char, int>& a, const pair<char, int>& b) {
    return a.second > b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    cal_weight();

    // unordered_map -> vector
    vector<pair<char, int>> v(alphabet.begin(), alphabet.end());

    // 가중치 내림차순 정렬
    sort(v.begin(), v.end(), compare);

    int num = 9;
    unordered_map<char, string> charInt;

    for (int i = 0; i < v.size(); i++) {
        charInt[v[i].first] = to_string(num);
        num--;
    }

    // 단어 계산
    for (int i = 0; i < N; i++) {
        string temp = "";
        for (int j = 0; j < word[i].size(); j++) {
            temp += charInt[word[i][j]];
        }
        sum += stoll(temp);
    }

    cout << sum;

    return 0;
}