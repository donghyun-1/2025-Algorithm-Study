// https://www.acmicpc.net/problem/1543
// 문서 검색 (실버 5)
// 2025-05-25

#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string doc, s;
    getline(cin, doc);
    getline(cin, s);

    int length = s.size();
    int idx = 0;
    int cnt = 0;

    while (idx + length <= doc.size()) {    // 또는 while (idx <= (int)doc.size() - length)
        string temp = doc.substr(idx, length);
        
        if (temp == s) {
            cnt++;
            idx += length;
        }
        else {
            idx++;
        }
        //cout << temp << "\n";
    }

    cout << cnt;

    return 0;
}