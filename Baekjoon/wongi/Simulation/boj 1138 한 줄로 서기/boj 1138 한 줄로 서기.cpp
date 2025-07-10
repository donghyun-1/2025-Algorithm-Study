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
/*
자신보다 큰 사람이 왼쪽에 arr[i]명 있어야 한다.
비어 있는 자리를 세어가면서  arr[i]번째 빈칸에 자신을 배치해야함
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count;
    cin >> count;
    vector<int> arr(count);
    vector<int> answer(count);
    for (int i = 0; i < count; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < count; i++)
    {
        int position = arr[i];// 현재 나보다 큰 사람이 왼쪽에 있어야 하는 사람의 수

        int j = 0;//줄의 인덱스 
        int cur = 0;// 지금까지 빈칸을 몇개 찾았는지에 대한 변수
        while (cur < position || answer[j] != 0)//빈자리 찾고 현 자리가 빈자리면 ++
        {
            if (answer[j] == 0)
            {
                cur++;
            }
            j++;
        }
        answer[j] = i + 1;//for문 0부터 시작했으므로 +1
    }
    for (int i = 0; i < count; i++) {
        cout << answer[i] << " ";
    }
}