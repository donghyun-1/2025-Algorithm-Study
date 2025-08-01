#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int pos[26][10000];   // 알파벳별 인덱스 저장
int posCnt[26];       // 각 알파벳별 인덱스 개수
/*
-->푸는 방법이 잘 생각이 나지 않아 구글링 + gpt의 도움을 받아 풀었습니다.
각 알파벳별로 문자열 내에서 등장하는 인덱스를 전부 기록
알파벳별로 인덱스를 K개씩 연속으로 묶어서 부분 문자열을 만들어줌
구간의 길이 = 마지막 인덱스 - 처음 인덱스 + 1
이때 가장 짧은/긴 값을 각각 minLen/maxLen에 갱신
만족하는 부분 문자열이 하나도 없으면 -1 출력
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        string input;
        int K;
        cin >> input >> K;

        // 배열 초기화
        for (int j = 0; j < 26; j++)
        {
            posCnt[j] = 0;
        }

        int minLen = 10001;
        int maxLen = -1;

        // 각 알파벳 등장 위치 저장
        for (int j = 0; j < input.size(); j++)
        {
            int ch = input[j] - 'a';//알파벳 인덱스 
            pos[ch][posCnt[ch]++] = j;// 등장 위치에 저장 , 등장 개수 1 증가시키기
        }

        // 각 알파벳별로 K개씩 슬라이딩 윈도우
        for (int ch = 0; ch < 26; ch++)
        {
            if (posCnt[ch] < K) continue;// 만약 이 알파벳이 k개 미만이면 부분 문자열을 만들 수 없음.
            for (int j = 0; j <= posCnt[ch] - K; j++)
            {
                int len = pos[ch][j + K - 1] - pos[ch][j] + 1;//부분 문자열 시작 인덱스 - 부분 문자열 끝 인덱스;
                minLen = min(minLen, len);
                maxLen = max(maxLen, len);
            }
        }

        if (minLen == 10001 || maxLen == -1)
            cout << -1 << "\n";
        else
            cout << minLen << " " << maxLen << "\n";
    }
}
