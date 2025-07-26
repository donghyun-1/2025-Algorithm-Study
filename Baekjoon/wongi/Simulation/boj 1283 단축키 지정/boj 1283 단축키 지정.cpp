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
vector<string> input;
bool used[26] = { false };
bool IsOption(char check)// used배열에 각 알파벳에 키워드로 사용 되었는지 안되었는지 bool로 체크
{
    return used[tolower(check) - 'a'];//아스키 코드 사용
}
void Change(string& checkStr,int checkStrIdx)
{
    checkStr = checkStr.substr(0, checkStrIdx) + "[" + checkStr[checkStrIdx] + "]" + checkStr.substr(checkStrIdx + 1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count;
    cin >> count;
    cin.ignore();
    
    for (int i = 0; i < count; i++)
    {
        string inputString;
        getline(cin, inputString);
        input.push_back(inputString);
    }
    /*
        cin.ignore();
        getline(cin, inputString);
        두개 사용하여 문자열에서 띄어쓰기도 같이 입력받게
    */
    for (int i = 0; i < count; i++)
    {
        bool isFind=false;
        
        for (int j = 0; j < input[i].size(); j++)
        {
            if (j == 0 || input[i][j - 1] == ' ')
                //첫번째 단어 하고 이제 각 문자는 띄어쓰기로 구분되어있으니까 그 전 인덱스가 빈칸이면 그 다음부터 단어 시작이니까 탐색
            {
                if (!IsOption(input[i][j]))
                    //단축키가 등록 안되어 있다면?
                    //이제 단축키 배열에서 인덱스를 true로 바꿔주고 그 단어 위치 찾아가서 대괄호 추가해줘야함
                {
                    used[tolower(input[i][j]) - 'a'] = true;
                    Change(input[i], j);
                    isFind = true;
                    break;
                }
            }
        }
        if (!isFind)// 줄 전체 왼쪽 부터 탐색하기 --> 첫번째 단어에서 키워드를 못찾았다면.
        {
            for (int j = 0; j < input[i].size(); j++)
            {
                if (input[i][j] == ' ') continue;

                if (!IsOption(input[i][j]))
                {
                    used[tolower(input[i][j]) - 'a'] = true;
                    Change(input[i], j);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        cout << input[i] << "\n";
    }
}