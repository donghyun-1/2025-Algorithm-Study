// https://www.acmicpc.net/problem/1541
// 잃어버린 괄호 (실버 2)
// 2025-07-20

/* 
    <접근 방법>
    [1] 
    문자열 입력

    [2]
    최솟값을 만들기 위해서는 최대한 큰 수를 빼야함 따라서 '-' 기준으로 split하고
    남은 '+' 식들을 더해줌 

    [3]
    첫 '+' 식은 answer에 그대로 더해주고 남은 '+' 식은 answer에서 빼주기
*/

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> result;
    stringstream ss(input);
    string splitdata;

    while (getline(ss, splitdata, delimiter)) {
        result.push_back(splitdata);
    }

    return result;
}

int sum(string str) {
    vector<string> temp = split(str, '+');

    int sum = 0;
    for (int i = 0; i < temp.size(); i++) {
        sum += stoi(temp[i]);
    }

    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 문자열 입력
    string input;
    cin >> input;

    // - 로 자르기
    vector<string> str = split(input, '-');

    // 더하기 후 빼기
    int answer = 0;
    for (int i = 0; i < str.size(); i++) {
        int temp = sum(str[i]);

        if (i == 0) {
            answer += temp;
        }
        else {
            answer -= temp;
        }
    }

    cout << answer;

    return 0;
}