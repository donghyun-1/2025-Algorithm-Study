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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N;
    vector<int> A;
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        A.push_back(input);
    }
    sort(A.begin(), A.end());
    //이분탐색은 정렬이 되어있다는 것을 가정으로 하기에 sort함수를 사용하여 정렬
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int input;
        cin >> input;

        //이분탐색
        int start = 0;//시작점
        int end = N - 1;//끝점
        bool isFound = false;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            //mid 즉 중간점을 기준으로 조건을 찾아가며 탐색 범위를 절반으로 줄여가며 탐색함
            if (A[mid] < input)
            {
                start = mid + 1;
            }
            else if (A[mid] > input)
            {
                end = mid - 1;
            }
            else
            {
                isFound = true;
                break;
            }
        }
        //여기까지 이분탐색
        if (isFound)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}