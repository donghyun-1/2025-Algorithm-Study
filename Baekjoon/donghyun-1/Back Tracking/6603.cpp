// https://www.acmicpc.net/problem/6603
// 로또 (실버 2)
// 2025-05-30

#include <iostream>
#include <vector>

using namespace std;

vector<int> S;

void input(int k) {
    S.resize(k);

    for (int i = 0; i < k; i++) {
        cin >> S[i];
    }
}

void lotto(int start, vector<int>& lotto_num) {
    if (lotto_num.size() == 6) {
        for (int i = 0; i < 6; i++) {
            cout << lotto_num[i] << " ";
        }
        cout << "\n";
        
        return;
    }

    for (int i = start; i < S.size(); i++) {
        lotto_num.push_back(S[i]);
        lotto(i + 1, lotto_num);
        lotto_num.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;

    while (1) {
        cin >> k;

        if (k == 0) break;

        // 집합 입력
        input(k);

        // 백트래킹
        vector<int> lotto_num;
        lotto(0, lotto_num);

        cout << "\n";
    }

    return 0;
}