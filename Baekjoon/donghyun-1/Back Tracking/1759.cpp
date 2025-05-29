// https://www.acmicpc.net/problem/1759
// 암호 만들기 (골드 5)
// 2025-05-29

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

void find_pw(int start, int length, string s, vector<char>& alpha) {
    if (s.size() == length) {
        int cnt = 0;
        
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < 5; j++) {
                if (s[i] == vowels[j]) {
                    cnt++;
                }
            }
        }

        if (cnt >= 1 && s.size() - cnt >= 2) {
            cout << s << "\n";
        }
    }

    for (int i = start; i < alpha.size(); i++) {
        s += alpha[i];
        find_pw(i + 1, length, s, alpha);
        s.pop_back();
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int L, C;
    cin >> L >> C;

    vector<char> alpha(C);

    // 입력
    for (int i = 0; i < C; i++) {
        cin >> alpha[i];
    }

    // 정렬
    sort(alpha.begin(), alpha.end());

    string s = "";
    find_pw(0, L, s, alpha);

    return 0;
}