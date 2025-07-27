// https://www.acmicpc.net/problem/1283
// 단축키 지정 (실버 1)
// 2025-07-26

/* 
    <접근 방법>
    [1] 
    문자열 입력

    [2]
    방법 1: ' '로 구분해서 저장해서 맨 첫 글자 확인 (set.count로 단축키 사용 중인지 확인)
    이 때 방법 1에서 단축키 지정이 끝나면 문자열 출력 후 continue로 다음 문자열 검사

    방법 2: 문자열 맨 앞 부터 한 글자씩 확인
*/

#include <iostream>
#include <string>
#include <unordered_set>
#include <sstream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    unordered_set<char> setKey;

    cin.ignore();

    while (N--) {
        string s;
        getline(cin, s);

        stringstream ss(s);
        string token;

        // 방법 1: 맨 앞 글자 확인
        bool found = false;
        string temp = "";
        while (ss >> token) {
            string processed = token;
            char key = tolower(token[0]);  // 대소문자 구분 없이 처리

            if (!found && setKey.count(key) == 0) {  // 없으면
                setKey.insert(key);
                found = true;

                processed = '[' + string(1, token[0]) + ']' + token.substr(1);
            }

            if (!temp.empty()) 
                temp += ' ';
            temp += processed;
        }

        if (found) {
            cout << temp << "\n";
            continue;
        }


        // 방법 2: 한 글자씩 전부 확인하기
        temp = "";
        for (int i = 0; i < s.size(); i++) {
            char key = tolower(s[i]);

            if (!found && s[i] != ' ' && setKey.count(key) == 0) {   // key 없으면
                setKey.insert(key);
                found = true;
                temp += '[' + string(1, s[i]) + ']';
                continue;
            }

            temp += s[i];
        }
        
        cout << temp << "\n";
    }

    return 0;
}