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
int S, P;
string passWord;
int passWordCnt[4]; // ->입력 받은 각 문자들의 조건 횟수
int inputArrCnt[4]; // ->현재 구간에서의 각 문자들의 나온 횟수
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> S >> P;
    cin >> passWord;
    for (int i = 0; i < 4; i++)
    {
        cin >> passWordCnt[i];
    }
    for (int i = 0; i < P; i++)
    {

        if (passWord[i] == 'A')
        {
            inputArrCnt[0]++;
        }
        else if (passWord[i] == 'C')
        {
            inputArrCnt[1]++;

        }
        else if (passWord[i] == 'G')
        {
            inputArrCnt[2]++;
        }
        else if (passWord[i] == 'T')
        {
            inputArrCnt[3]++;
        }
    }

    int left = 0;//시작점
    int right = P - 1;//끝점
    int curState=0;
    int answer = 0;
    while (curState<S-P+1)//체
    {
        bool answerTrigger = true;
        for (int i = 0; i < 4; i++)
        {
            if (inputArrCnt[i] < passWordCnt[i])
            {
                answerTrigger = false;
                break;
            }
            //하나라도 최소조건에 맞지 않으면 조건에 맞지 않으니 break
        }
   
        //현재 구간 검사
        if (answerTrigger)
        {
            answer++;
        }

        //먼저 왼쪽에 있는 문자 빼주고
        if (passWord[left] == 'A') inputArrCnt[0]--;
        else if (passWord[left] == 'C') inputArrCnt[1]--;
        else if (passWord[left] == 'G') inputArrCnt[2]--;
        else if (passWord[left] == 'T') inputArrCnt[3]--;
        
        //윈도우 위치 한칸 이동
        left++;
        right++;

        //오른쪽으로 이동해서 맨끝에 추가된 단어 판단하여 ++
        if (passWord[right] == 'A') inputArrCnt[0]++;
        else if (passWord[right] == 'C') inputArrCnt[1]++;
        else if (passWord[right] == 'G') inputArrCnt[2]++;
        else if (passWord[right] == 'T') inputArrCnt[3]++;
      
        curState++;
    }
    cout << answer;
}