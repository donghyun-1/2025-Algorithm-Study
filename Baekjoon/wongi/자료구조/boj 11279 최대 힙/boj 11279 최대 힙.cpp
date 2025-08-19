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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<int> list;
    int count;
    cin >> count;
    vector<int> answer;
    for (int i = 0; i < count; i++) {
        int input;
        cin >> input;
        if (input == 0) {
            if (list.empty())
            {
                answer.push_back(0);
            }
            else
            {
                answer.push_back(list.top());
                list.pop();
            }
        }
        else
        {
            list.push(input);
        }
    }
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << '\n';
    }

}