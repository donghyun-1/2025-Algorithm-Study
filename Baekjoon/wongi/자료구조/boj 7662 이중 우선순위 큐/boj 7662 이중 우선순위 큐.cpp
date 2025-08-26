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
using namespace std;
priority_queue<int> downArr;//내림차순 
priority_queue<int, vector<int>, greater<int>> upArr;//오름차순 
map<int, int> cnt; // 값별 개수 카운트
//지금 우선순위 큐를 두개 사용하기 때문에 cnt 맵을 사용하여 각 큐에 
//삭제 할 때 카운트 배열의 카운트 값을 보면서 두개의 큐에 삭제 하려는 값이 제거 되었는지 제거 안되었는지 확인할 수 있음.
// 한쪽힙에서 삭제를 해도 반대 힙에는 그 똑같은 값이 남아있을수 있음 --> 각 우선순위가 다르게 정렬이 되어있으므로
// 따라서 나중에 그 값이 top으로 올라왔을때 카운트가 0이면 이미 다른 큐에서 삭제된 값이므로 pop해버림
//일종의 동기화 느낌
void clearArr()
{
    while (!downArr.empty())
    {
        downArr.pop();
    }
    while (!upArr.empty())
    {
        upArr.pop();
    }
    cnt.clear();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    


    int T;
    cin >> T;
    while (T--)
    {
        clearArr();
        int K;
        cin >> K;
        for (int i = 0; i < K; i++)
        {
            char input;
            int num;
            cin >> input >> num;
            if (input == 'I')
            {
                downArr.push(num);
                upArr.push(num);
                cnt[num]++; // 값 개수 증가
            }
            else if(input=='D')
            {
                if (num == 1) // 최댓값 삭제
                {
                    while (!downArr.empty() && cnt[downArr.top()] == 0)
                    {
                        downArr.pop();
                    }
                    if (!downArr.empty())
                    {
                        cnt[downArr.top()]--;
                        downArr.pop();
                    }
                }
                else if (num == -1) // 최솟값 삭제
                {
                    while (!upArr.empty() && cnt[upArr.top()] == 0)
                    {
                        upArr.pop();
                    }
                    if (!upArr.empty())
                    {
                        cnt[upArr.top()]--;
                        upArr.pop();
                    }
                }
            }
        }
        /*
        혹시나 카운트가 0인 값들이 있을 수 있으니 그 양쪽 큐를 확인하면서 값을 삭제해 줘야함
        */
        while (!downArr.empty() && cnt[downArr.top()] == 0)
        {
            downArr.pop();
        }
        while (!upArr.empty() && cnt[upArr.top()] == 0)
        {
            upArr.pop();
        }

        if (downArr.empty())
        {
            cout << "EMPTY" << '\n';
        }
        else
        {
            cout << downArr.top() << " " << upArr.top() << "\n";
        }
    }
}