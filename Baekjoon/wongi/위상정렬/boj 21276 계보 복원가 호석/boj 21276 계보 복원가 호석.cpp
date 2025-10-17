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
#include <unordered_set>
#include<unordered_map>
#include<math.h>
using namespace std;
int n, m;
map<string, vector<string>> inputArr;
map<string, int> indegreeCnt;//indegree 수
vector<string> names;//그냥 이름들 배열
vector<string>oldestName;// 시조 이름 저장 배열
int k = 0;//가문의 개수
int main()
{
    /*
        n명의 사람 이름 입력 받고
        기억하는 m개의 정보를 입력을 받는데
        x y 꼴로 입력이 주어지는데
        x의 상위에 y가 있다는 걸 의미

        출력
        첫번째 줄: 가문의 개수 K
        두번째 줄: 각 가문의 ROOT 사람 이름 출력
        세번째 줄부터~: 사전순으로 이름 , 자식 수 , 자식 이름 출력 

    */
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        names.push_back(name);
        indegreeCnt[name] = 0;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string x, y;
        cin >> x >> y;
        inputArr[y].push_back(x);
        indegreeCnt[x]++;
    }

    for (int i = 0; i < n; i++)
    //일단 가문의 개수를 확인.
    // 더해서 시조의 이름 저장
    {
        string curName = names[i];
        if (indegreeCnt[curName] == 0)
        {
            k++;
            oldestName.push_back(curName);
        }
    }
    cout << k << '\n';
    sort(oldestName.begin(), oldestName.end());
    for (int i = 0; i < k; i++)
    {
        cout << oldestName[i] << ' ';
    }
    cout << '\n';
    //가문 개수, 시조 이름 출력
    sort(names.begin(), names.end());

    for (int i = 0; i < n; i++)
    {
        string curName = names[i];
        vector<string> child=inputArr[curName];
        vector<string> answer;
        for (int j = 0; j < child.size(); j++)
        {
            if (abs(indegreeCnt[curName] - indegreeCnt[child[j]])== 1)
                //근데 이제 직계 자식만 출력해야 하므로 현재 이름과 자식들의 indgree 차가 1일때만 answer배열에다가 넣어두기
            {
                answer.push_back(child[j]);
            }
        }
        sort(answer.begin(),answer.end());
        cout << curName << ' ' << answer.size()<<' ';
        
        for (int j = 0; j < answer.size(); j++)
        {
            cout << answer[j] << ' ';
        }
        cout << '\n';
    }
}