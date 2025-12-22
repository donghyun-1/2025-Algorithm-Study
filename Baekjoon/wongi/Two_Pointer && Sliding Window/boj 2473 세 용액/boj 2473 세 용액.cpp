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
vector<long long> input;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        int a;
        cin >> a;
        input.push_back(a);
    }
    sort(input.begin(), input.end());

    int fixNum = 0;
    long long answer = 3e9;
    long long left=0;
    long long right=0;
    for (int i = 0; i < size-2; i++)//차피 나머지 값은 비교할 필요 없음 i뒤에 두값이 있으니 
    {
        int cur = input[i];
        int leftIdx = i + 1;
        int rightIdx = size - 1;
        //일단 현재 값을 고정 시켜두고 뒤에 두 값을 구하기.
        while (leftIdx < rightIdx)
        {
            long long sum = input[leftIdx] + input[rightIdx] + cur;
            if (abs(sum) < abs(answer))//더 작은 값이면 조합을 갱신
            {
                answer = sum;
                fixNum = cur;
                left = input[leftIdx];
                right = input[rightIdx];
            }
            if (sum < 0)
            {
                leftIdx++;
            }
            else
            {
                rightIdx--;
            }
        }
    }
    cout << fixNum << " " << left<<" " << right;

}